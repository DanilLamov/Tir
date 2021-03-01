#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>
#include <memory>

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Buffer.h"
#include "Sprite.h"
#include "Background.h"
#include "ParticleGenerator.h"
#include "AnimatedBackground.h"

class ResourceManager {
public:
	//конструктор по умолчанию
	ResourceManager() = delete;
	//деструктор
	~ResourceManager() = delete;
	//конструктор копирования
	ResourceManager(const ResourceManager&) = delete;
	//конструктор присваивания
	ResourceManager& operator = (const ResourceManager&) = delete;
	//конструктор перемещения
	ResourceManager(ResourceManager&&) = delete;
	//конструктор присваивания перемещением
	ResourceManager& operator = (ResourceManager&&) = delete;

	//установка пути до исполняемого файла
	static void setExecutablePath(const std::string& executablePath);
	//получение пути исполняемого файла
	static std::string getExecutablePath();

	//удаление всех ресурсов
	static void clearResources();

	//возвращает содержимое текстового файла по указанному пути
	static std::string getFileString(const std::string& relativeFilePath);

	//создает шейдерную программу
	static std::shared_ptr<ShaderProgram> createShaderProgram(const std::string& shaderProgramName, 
															  const std::string& vertexShaderPath, 
															  const std::string& fragmentShaderPath, 
															  const std::string& geometryShaderPath = "");
	//возвращает шейдерную программу по ее имени
	static std::shared_ptr<ShaderProgram> getShaderProgram(const std::string& shaderProgramName);

	//созает 2Д текстуру
	static std::shared_ptr<Texture2D> createTexture2D(const std::string& textureName, const std::string& texturePath);
	//возвращает текстуру по ее имени
	static std::shared_ptr<Texture2D> getTexture2D(const std::string& textureName);

	//создает буфферы с вершинами
	static std::shared_ptr<Buffer> createBuffer(const std::string& BufferName);
	//возвращает буффер по его имени
	static std::shared_ptr<Buffer> getBuffer(const std::string& BufferName);

	//создает спрайт
	static std::shared_ptr<Sprite> createSprite(const std::string& spriteName, const std::string& textureName);
	static std::shared_ptr<Sprite> createSprite(const std::string& spriteName, std::shared_ptr<Texture2D> texture);
	//возвращает спрайт по его имени
	static std::shared_ptr<Sprite> getSprite(const std::string& spriteName);

	//создает фон
	static std::shared_ptr<Background> createBackground(const std::string& backgroundName, const std::string& textureName);
	static std::shared_ptr<Background> createBackground(const std::string& backgroundName, std::shared_ptr<Texture2D> texture);
	//возвращает фон по имени
	static std::shared_ptr<Background> getBackground(const std::string& backgroundName);

	//создает анимированный фон
	static std::shared_ptr<AnimatedBackground> createAnimatedBackground(const std::string& animatedBackgroundName, const std::string& backgroundName, const std::string& sprite1Name, const std::string& sprite2Name);
	static std::shared_ptr<AnimatedBackground> createAnimatedBackground(const std::string& animatedBackgroundName, std::shared_ptr<Background> background, std::shared_ptr<Sprite> sprite1, std::shared_ptr<Sprite> sprite2);
	//возвращает анимированный  фон по имени
	static std::shared_ptr<AnimatedBackground> getAnimatedBackground(const std::string& animatedBackgroundName);

	//создание генератора частиц
	static std::shared_ptr<ParticleGenerator> createParticleGenerator(const std::string& particleGeneratorName, const std::string& textureName, const unsigned int& amount);
	//возвращает генератора частиц по его имени
	static std::shared_ptr<ParticleGenerator> getParticleGenerator(const std::string& particleGeneratorName);

private:
	//карта шейдерных программ
	static std::map<std::string, std::shared_ptr<ShaderProgram>> shaderProgramMap;
	static std::map<std::string, std::shared_ptr<Texture2D>> texture2DMap;
	static std::map<std::string, std::shared_ptr<Buffer>> bufferMap;
	static std::map<std::string, std::shared_ptr<Sprite>> spriteMap;
	static std::map<std::string, std::shared_ptr<Background>> backgroundMap;
	static std::map<std::string, std::shared_ptr<ParticleGenerator>> particleGeneratorMap;
	static std::map<std::string, std::shared_ptr<AnimatedBackground>> animatedBackgroundMap;
	static std::string exePath;

};

#endif