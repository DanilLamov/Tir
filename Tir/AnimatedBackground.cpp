#include "AnimatedBackground.h"

AnimatedBackground::AnimatedBackground(std::shared_ptr<Background> background, std::shared_ptr<Sprite> obj1, std::shared_ptr<Sprite> obj2) 
	: landscape(background), cloud1(obj1), cloud2(obj2) {}

AnimatedBackground::AnimatedBackground(AnimatedBackground&& animatedBackground) noexcept
	: landscape(animatedBackground.landscape), cloud1(animatedBackground.cloud1), cloud2(animatedBackground.cloud2),
	  positionCloud1(animatedBackground.positionCloud1), sizeCloud1(animatedBackground.sizeCloud1),
	  positionCloud2(animatedBackground.positionCloud1), sizeCloud2(animatedBackground.sizeCloud2) {}

AnimatedBackground& AnimatedBackground::operator = (AnimatedBackground&& animatedBackground) noexcept {
	landscape = animatedBackground.landscape;
	cloud1 = animatedBackground.cloud1;
	cloud2 = animatedBackground.cloud2;
	positionCloud1 = animatedBackground.positionCloud1;
	sizeCloud1 = animatedBackground.sizeCloud1;
	positionCloud2 = animatedBackground.positionCloud1;
	sizeCloud2 = animatedBackground.sizeCloud2;

	landscape = nullptr;
	cloud1 = cloud2 = nullptr;
	positionCloud1 = sizeCloud1 = positionCloud2 = sizeCloud2 = glm::vec2(0.f);

	return *this;
}

void AnimatedBackground::update(const float& dt) {
	
}

void AnimatedBackground::render() {
	landscape->draw();
	cloud1->draw(positionCloud1, sizeCloud1);
	cloud2->draw(positionCloud2, sizeCloud2);
}