#include "Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ResourceManager.h"

Game::Game(const unsigned int& windowWidth, const unsigned int& windowHeight)
	: gameState(GameState::GAME_ACTIVE), keys(), windowWidth(windowWidth), windowHeight(windowHeight) {}

void Game::init() {
	//�������� � �������� ��������� ��������
	ResourceManager::createShaderProgram("texture shader program", 
										 "shaders\\texVertexShader.txt", 
										 "shaders\\texFragmentShader.txt");
	ResourceManager::createShaderProgram("texture with model matrix shader program",
										 "shaders\\texWithModelMatrixVertexShader.txt",
										 "shaders\\texWithModelMatrixFragmentShader.txt");

	//�������� � �������� �������
	ResourceManager::createTexture2D("landscape", "textures\\background.png");

	//�������� ���������� ������
	ResourceManager::createBuffer("buffer");

	//�������� ����
	ResourceManager::createBackground("landscape", "landscape");

}

void Game::input(const float& dt) {
	
}

void Game::update(const float& dt) {
	
}

void Game::render() {
	ResourceManager::getBackground("landscape")->draw();
}

void Game::pressKey(const size_t& key) {
	keys[key] = true;
}

void Game::releaseKey(const size_t& key) {
	keys[key] = false;
}