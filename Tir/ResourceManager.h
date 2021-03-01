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
	//����������� �� ���������
	ResourceManager() = delete;
	//����������
	~ResourceManager() = delete;
	//����������� �����������
	ResourceManager(const ResourceManager&) = delete;
	//����������� ������������
	ResourceManager& operator = (const ResourceManager&) = delete;
	//����������� �����������
	ResourceManager(ResourceManager&&) = delete;
	//����������� ������������ ������������
	ResourceManager& operator = (ResourceManager&&) = delete;

	//��������� ���� �� ������������ �����
	static void setExecutablePath(const std::string& executablePath);
	//��������� ���� ������������ �����
	static std::string getExecutablePath();

	//�������� ���� ��������
	static void clearResources();

	//���������� ���������� ���������� ����� �� ���������� ����
	static std::string getFileString(const std::string& relativeFilePath);

	//������� ��������� ���������
	static std::shared_ptr<ShaderProgram> createShaderProgram(const std::string& shaderProgramName, 
															  const std::string& vertexShaderPath, 
															  const std::string& fragmentShaderPath, 
															  const std::string& geometryShaderPath = "");
	//���������� ��������� ��������� �� �� �����
	static std::shared_ptr<ShaderProgram> getShaderProgram(const std::string& shaderProgramName);

	//������ 2� ��������
	static std::shared_ptr<Texture2D> createTexture2D(const std::string& textureName, const std::string& texturePath);
	//���������� �������� �� �� �����
	static std::shared_ptr<Texture2D> getTexture2D(const std::string& textureName);

	//������� ������� � ���������
	static std::shared_ptr<Buffer> createBuffer(const std::string& BufferName);
	//���������� ������ �� ��� �����
	static std::shared_ptr<Buffer> getBuffer(const std::string& BufferName);

	//������� ������
	static std::shared_ptr<Sprite> createSprite(const std::string& spriteName, const std::string& textureName);
	static std::shared_ptr<Sprite> createSprite(const std::string& spriteName, std::shared_ptr<Texture2D> texture);
	//���������� ������ �� ��� �����
	static std::shared_ptr<Sprite> getSprite(const std::string& spriteName);

	//������� ���
	static std::shared_ptr<Background> createBackground(const std::string& backgroundName, const std::string& textureName);
	static std::shared_ptr<Background> createBackground(const std::string& backgroundName, std::shared_ptr<Texture2D> texture);
	//���������� ��� �� �����
	static std::shared_ptr<Background> getBackground(const std::string& backgroundName);

	//������� ������������� ���
	static std::shared_ptr<AnimatedBackground> createAnimatedBackground(const std::string& animatedBackgroundName, const std::string& backgroundName, const std::string& sprite1Name, const std::string& sprite2Name);
	static std::shared_ptr<AnimatedBackground> createAnimatedBackground(const std::string& animatedBackgroundName, std::shared_ptr<Background> background, std::shared_ptr<Sprite> sprite1, std::shared_ptr<Sprite> sprite2);
	//���������� �������������  ��� �� �����
	static std::shared_ptr<AnimatedBackground> getAnimatedBackground(const std::string& animatedBackgroundName);

	//�������� ���������� ������
	static std::shared_ptr<ParticleGenerator> createParticleGenerator(const std::string& particleGeneratorName, const std::string& textureName, const unsigned int& amount);
	//���������� ���������� ������ �� ��� �����
	static std::shared_ptr<ParticleGenerator> getParticleGenerator(const std::string& particleGeneratorName);

private:
	//����� ��������� ��������
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