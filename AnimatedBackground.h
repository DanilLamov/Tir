#ifndef ANIMATED_BACKGROUND_H
#define ANIMATED_BACKGROUND_H

//#include "ResourceManager.h"

#include "Background.h"
#include "Sprite.h"

class AnimatedBackground {
public:
	//конструкктор по умолчанию
	AnimatedBackground() = delete;
	//конструктор
	AnimatedBackground(std::shared_ptr<Background> background, 
					   std::shared_ptr<Sprite> cloud1,
					   std::shared_ptr<Sprite> cloud2,
					   std::shared_ptr<Sprite> crown1,
					   std::shared_ptr<Sprite> crown2,
					   std::shared_ptr<Sprite> crown3,
					   std::shared_ptr<Sprite> crown4,
					   std::shared_ptr<Sprite> crown5,
					   std::shared_ptr<Sprite> shore);
	//деструктор
	~AnimatedBackground() = default;

	//конструктор копирования
	AnimatedBackground(const AnimatedBackground&) = delete;
	//конструктор присваивания
	AnimatedBackground& operator = (const AnimatedBackground&) = delete;
	//конструктор перемещения
	AnimatedBackground(AnimatedBackground&&) noexcept;
	//конструктор присваивания перемещением
	AnimatedBackground& operator = (AnimatedBackground&&) noexcept;

	void update(const float& dt);

	void render();

private:
	std::shared_ptr<Background> landscape;
	std::shared_ptr<Sprite> cloud1, cloud2, crowns[5], shore;
	glm::vec2 positionsClouds[3]{ glm::vec2(.56f, .545f), glm::vec2(-.54f, 0.7f), glm::vec2(-1.12f, 0.59f) },
			  sizesClouds[3]{ glm::vec2(.33f, .3f), glm::vec2(.2f, .15f), glm::vec2(.25f, .185f) },
			  velocityClouds = glm::vec2(.01f, .0f),

			  positionsCrowns[5]{ glm::vec2(-.72f, -.13f), glm::vec2(.692f, -.24f), glm::vec2(.392f, -.536f), glm::vec2(-.315f, -.56f), glm::vec2(-.44f, -.565f) },
			  sizesCrowns[5]{ glm::vec2(.25f, .5f), glm::vec2(.25f, .5f), glm::vec2(.13f, .27f), glm::vec2(.125f, .25f), glm::vec2(.125f, .25f) },
		
			  shorePosition = glm::vec2(-.505f, -.755f), shoreSize = glm::vec2(.25f, .25f);
	float tiltsAnglesCrowns[5]{ .0f, .0f, .0f, .0f, .0f }, time = 0.f;

};

#endif