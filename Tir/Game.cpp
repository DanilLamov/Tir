#include "Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ResourceManager.h"

Game::Game(const unsigned int& windowWidth, const unsigned int& windowHeight)
	: gameState(GameState::GAME_ACTIVE), keys(), windowWidth(windowWidth), windowHeight(windowHeight) {}

void Game::init() {
	//загрузка и создание шейдерных программ
	ResourceManager::createShaderProgram("texture shader program", 
										 "shaders\\texVertexShader.txt", 
										 "shaders\\texFragmentShader.txt");
	ResourceManager::createShaderProgram("texture with model matrix shader program",
										 "shaders\\texWithModelMatrixVertexShader.txt",
										 "shaders\\texWithModelMatrixFragmentShader.txt");

	//загрузка и создание текстур
	std::shared_ptr<Texture2D> landscape = ResourceManager::createTexture2D("landscape", "textures\\background.png"),
							   cloud1Tex = ResourceManager::createTexture2D("cloud 1", "textures\\cloud 1.png"),
							   cloud2Tex = ResourceManager::createTexture2D("cloud 2", "textures\\cloud 2.png");

	//создание вершмнного буфера
	ResourceManager::createBuffer("buffer");

	//создание фона
	std::shared_ptr<Background> background = ResourceManager::createBackground("landscape", "landscape");

	//создание спрайтов
	std::shared_ptr<Sprite> cloud1Sprite = ResourceManager::createSprite("cloud 1", cloud1Tex),
							cloud2Sprite = ResourceManager::createSprite("cloud 2", cloud2Tex);

	//создание анимированного фона
	ResourceManager::createAnimatedBackground("landscape with animated clouds", background, cloud1Sprite, cloud2Sprite);
}

void Game::input(const float& dt) {
	
}

void Game::update(const float& dt) {
	
}

void Game::render() {
	ResourceManager::getAnimatedBackground("landscape with animated clouds")->render();
}

void Game::pressKey(const size_t& key) {
	keys[key] = true;
}

void Game::releaseKey(const size_t& key) {
	keys[key] = false;
}