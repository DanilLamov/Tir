#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "stb_image.h"

std::map<std::string, std::shared_ptr<ShaderProgram>> ResourceManager::shaderProgramMap;
std::map<std::string, std::shared_ptr<Texture2D>> ResourceManager::texture2DMap;
std::map<std::string, std::shared_ptr<Buffer>> ResourceManager::bufferMap;
std::map<std::string, std::shared_ptr<Sprite>> ResourceManager::spriteMap;
std::map<std::string, std::shared_ptr<Background>> ResourceManager::backgroundMap;
std::map<std::string, std::shared_ptr<ParticleGenerator>> ResourceManager::particleGeneratorMap;
std::string ResourceManager::exePath;

void ResourceManager::setExecutablePath(const std::string& executablePath) {
	size_t slash = executablePath.find_last_of("\\");
	exePath = executablePath.substr(0, slash);
}

std::string ResourceManager::getExecutablePath() {
	return exePath;
}

void ResourceManager::clearResources() {
	shaderProgramMap.clear();
}

std::string ResourceManager::getFileString(const std::string& relativeFilePath) {
	std::ifstream in(exePath + "\\" + relativeFilePath.c_str());

	if (!in.is_open()) {
		std::cerr << "Resource manager: failed to open file: " << relativeFilePath << std::endl;
		return std::string();
	}

	std::stringstream buffer;
	buffer << in.rdbuf();
	return buffer.str();
}

std::shared_ptr<ShaderProgram> ResourceManager::createShaderProgram(const std::string& shaderProgramName, 
																	const std::string& vertexShaderPath, 
																	const std::string& fragmentShaderPath,
																	const std::string& geometryShaderPath) {
	//получение кода вертексного шейдера
	std::string vertexShaderSource = getFileString(vertexShaderPath), fragmentShaderSource, geometryShaderSource = "";
	if (vertexShaderSource.empty()) {
		std::cerr << "Resource manager: file with vertex shader is empty" << std::endl;
		return nullptr;
	}

	//получение кода фрагментного шейдера
	fragmentShaderSource = getFileString(fragmentShaderPath);
	if (fragmentShaderSource.empty()) {
		std::cerr << "Resource manager: file with fragment shader is empty" << std::endl;
		return nullptr;
	}

	//получение кода геометрического шейдера
	if (geometryShaderPath != "") {
		geometryShaderSource = getFileString(geometryShaderPath);
		if (geometryShaderSource.empty()) {
			std::cerr << "Resource manager: file with geometry shader is empty" << std::endl;
			return nullptr;
		}
	}

	//добавляем объект в карту шейдерных програм
	std::shared_ptr<ShaderProgram>& shaderProgram = shaderProgramMap.emplace(shaderProgramName, std::make_shared<ShaderProgram>(vertexShaderSource, fragmentShaderSource, geometryShaderSource)).first->second;
	return shaderProgram;
}

std::shared_ptr<ShaderProgram> ResourceManager::getShaderProgram(const std::string& shaderProgramName) {
	std::map<const std::string, std::shared_ptr<ShaderProgram>>::const_iterator it = shaderProgramMap.find(shaderProgramName);
	if (it != shaderProgramMap.end()) return it->second;

	std::cerr << "Resource manager can't find the shader program: " << shaderProgramName << std::endl;
	return nullptr;
}

std::shared_ptr<Texture2D> ResourceManager::createTexture2D(const std::string& textureName, const std::string& texturePath) {
	int channels = 0, width = 0, height = 0;

	//переворачивает изображение при загрузке
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(std::string(exePath + "\\" + texturePath).c_str(), &width, &height, &channels, 0);
	if (!data) {
		std::cerr << "Resource manager can't load image: " << texturePath << std::endl;
		return nullptr;
	}

	std::shared_ptr<Texture2D> texture = texture2DMap.emplace(textureName, std::make_shared<Texture2D>(width, height, data, channels, GL_NEAREST, GL_CLAMP_TO_EDGE)).first->second;

	stbi_image_free(data);

	return texture;
}

std::shared_ptr<Texture2D> ResourceManager::getTexture2D(const std::string& textureName) {
	std::map<const std::string, std::shared_ptr<Texture2D>>::const_iterator it = texture2DMap.find(textureName);
	if (it != texture2DMap.end()) return it->second;

	std::cerr << "Resource manager can't find the texture: " << textureName << std::endl;
	return nullptr;
}

std::shared_ptr<Buffer> ResourceManager::createBuffer(const std::string& BufferName) {
	std::shared_ptr<Buffer>& buffer = bufferMap.emplace(BufferName, std::make_shared<Buffer>()).first->second;
	return buffer;
}

std::shared_ptr<Buffer> ResourceManager::getBuffer(const std::string& BufferName) {
	std::map<const std::string, std::shared_ptr<Buffer>>::const_iterator it = bufferMap.find(BufferName);
	if (it != bufferMap.end()) return it->second;

	std::cerr << "Resource manager can't find the texture: " << BufferName << std::endl;
	return nullptr;
}

std::shared_ptr<Sprite> ResourceManager::createSprite(const std::string& spriteName, const std::string& shaderProgramName, const std::string& textureName) {
	return spriteMap.emplace(spriteName, std::make_shared<Sprite>(getShaderProgram(shaderProgramName), getTexture2D(textureName))).first->second;
}

std::shared_ptr<Sprite> ResourceManager::getSprite(const std::string& spriteName) {
	std::map<const std::string, std::shared_ptr<Sprite>>::const_iterator iter = spriteMap.find(spriteName);
	if (iter != spriteMap.end()) return iter->second;

	std::cerr << "RESOURCE_MANAGER can't find the texture: " << spriteName << std::endl;
	return nullptr;
}

std::shared_ptr<Background> ResourceManager::createBackground(const std::string& backgroundName, const std::string& textureName) {
	return backgroundMap.emplace(backgroundName, std::make_shared<Background>(getTexture2D(textureName), getShaderProgram("texture shader program"), getBuffer("buffer"))).first->second;
}

std::shared_ptr<Background> ResourceManager::getBackground(const std::string& backgroundName) {
	std::map<const std::string, std::shared_ptr<Background>>::const_iterator iter = backgroundMap.find(backgroundName);
	if (iter != backgroundMap.end()) return iter->second;

	std::cerr << "Resource manager can't find the background: " << backgroundName << std::endl;
	return nullptr;
}

std::shared_ptr<ParticleGenerator> ResourceManager::createParticleGenerator(const std::string& particleGeneratorName, const std::string& textureName, const unsigned int& amount) {
	return particleGeneratorMap.emplace(particleGeneratorName, std::make_shared<ParticleGenerator>(getTexture2D(textureName), amount)).first->second;
}

std::shared_ptr<ParticleGenerator> ResourceManager::getParticleGenerator(const std::string& particleGeneratorName) {
	std::map<const std::string, std::shared_ptr<ParticleGenerator>>::const_iterator iter = particleGeneratorMap.find(particleGeneratorName);
	if (iter != particleGeneratorMap.end()) return iter->second;

	std::cerr << "RESOURCE_MANAGER can't find the particle generator: " << particleGeneratorName << std::endl;
	return nullptr;
}