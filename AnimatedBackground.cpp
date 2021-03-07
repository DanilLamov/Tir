#include "AnimatedBackground.h"

#include <math.h>

AnimatedBackground::AnimatedBackground(std::shared_ptr<Background> background, 
									   std::shared_ptr<Sprite> cloud1,
									   std::shared_ptr<Sprite> cloud2,
									   std::shared_ptr<Sprite> crown1,
									   std::shared_ptr<Sprite> crown2,
									   std::shared_ptr<Sprite> crown3,
									   std::shared_ptr<Sprite> crown4,
									   std::shared_ptr<Sprite> crown5,
									   std::shared_ptr<Sprite> shore)
	: landscape(background), cloud1(cloud1), cloud2(cloud2), crowns{ crown1, crown2, crown3, crown4, crown5 }, shore(shore) {}

AnimatedBackground::AnimatedBackground(AnimatedBackground&& animatedBackground) noexcept
	: landscape(animatedBackground.landscape), cloud1(animatedBackground.cloud1), cloud2(animatedBackground.cloud2), crowns{ *animatedBackground.crowns, *(animatedBackground.crowns + 1), *(animatedBackground.crowns + 2), *(animatedBackground.crowns + 3), *(animatedBackground.crowns + 5) }, shore(animatedBackground.shore) {}

AnimatedBackground& AnimatedBackground::operator = (AnimatedBackground&& animatedBackground) noexcept {
	landscape = animatedBackground.landscape;
	cloud1 = animatedBackground.cloud1;
	cloud2 = animatedBackground.cloud2;
	for (int i = 0; i < 5; ++i) {
		crowns[i] = animatedBackground.crowns[i];
		animatedBackground.crowns[i] = nullptr;
	}
	shore = animatedBackground.shore;

	landscape = nullptr;
	cloud1 = cloud2 = shore = nullptr;

	return *this;
}

void AnimatedBackground::update(const float& dt) {
	//обновление облаков
	for (int i = 0; i < 3; ++i) {
		//перемещение
		positionsClouds[i] += velocityClouds * dt;

		//проверка на выход за грань
		if (positionsClouds[i].x >= 1.f + sizesClouds[i].x)
			positionsClouds[i].x = -1.f - sizesClouds[i].x;
	}

	time += dt;
	//обновление кроны деревьев
	for (int i = 0; i < 5; ++i) {
		tiltsAnglesCrowns[i] = sin(time);
	}
}

void AnimatedBackground::render() {
	landscape->draw();

	cloud1->draw(positionsClouds[0], sizesClouds[0]);
	cloud2->draw(positionsClouds[1], sizesClouds[1]);
	cloud2->draw(positionsClouds[2], sizesClouds[2]);

	for (int i = 0; i < 5; ++i)
		crowns[i]->draw(positionsCrowns[i], sizesCrowns[i], tiltsAnglesCrowns[i]);

	shore->draw(shorePosition, shoreSize);
}