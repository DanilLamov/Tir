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
							   cloud2Tex = ResourceManager::createTexture2D("cloud 2", "textures\\cloud 2.png"),
							   crown1Tex = ResourceManager::createTexture2D("crown 1", "textures\\crown 1.png"),
							   crown2Tex = ResourceManager::createTexture2D("crown 2", "textures\\crown 2.png"),
							   crown3Tex = ResourceManager::createTexture2D("crown 3", "textures\\crown 3.png"),
							   crown4Tex = ResourceManager::createTexture2D("crown 4", "textures\\crown 4.png"),
							   crown5Tex = ResourceManager::createTexture2D("crown 5", "textures\\crown 5.png"),
							   shoreTex = ResourceManager::createTexture2D("shore", "textures\\shore.png");

	//создание вершмнного буфера
	ResourceManager::createBuffer("buffer");

	//создание фона
	std::shared_ptr<Background> background = ResourceManager::createBackground("landscape", "landscape");

	//создание спрайтов
	std::shared_ptr<Sprite> cloud1Sprite = ResourceManager::createSprite("cloud 1", cloud1Tex),
							cloud2Sprite = ResourceManager::createSprite("cloud 2", cloud2Tex),
							crown1Sprite = ResourceManager::createSprite("crown 1", crown1Tex),
							crown2Sprite = ResourceManager::createSprite("crown 2", crown2Tex), 
							crown3Sprite = ResourceManager::createSprite("crown 3", crown3Tex), 
							crown4Sprite = ResourceManager::createSprite("crown 4", crown4Tex), 
							crown5Sprite = ResourceManager::createSprite("crown 5", crown5Tex),
							shoreSprite = ResourceManager::createSprite("shore", shoreTex);

	//создание анимированного фона
	ResourceManager::createAnimatedBackground("landscape with animated clouds", background, 
																				cloud1Sprite, 
																				cloud2Sprite, 
																				crown1Sprite, 
																				crown2Sprite, 
																				crown3Sprite, 
																				crown4Sprite, 
																				crown5Sprite,
																				shoreSprite);
}

void Game::input(const float& dt) {
	
}

void Game::update(const float& dt) {
	ResourceManager::getAnimatedBackground("landscape with animated clouds")->update(dt);
}

void Game::render() {
	
	ResourceManager::getAnimatedBackground("landscape with animated clouds")->render();
	//ResourceManager::getSprite("crown 1")->draw(glm::vec2(-.5f, .5f), glm::vec2(-.3f, -.3f), 180.f);
}

void Game::pressKey(const size_t& key) {
	keys[key] = true;
}

void Game::releaseKey(const size_t& key) {
	keys[key] = false;
}