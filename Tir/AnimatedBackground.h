#ifndef ANIMATED_BACKGROUND_H
#define ANIMATED_BACKGROUND_H

//#include "ResourceManager.h"

#include "Background.h"
#include "Sprite.h"

class AnimatedBackground {
public:
	//������������ �� ���������
	AnimatedBackground() = delete;
	//�����������
	AnimatedBackground(std::shared_ptr<Background> background, std::shared_ptr<Sprite> obj1, std::shared_ptr<Sprite> obj2);
	//����������
	~AnimatedBackground() = default;

	//����������� �����������
	AnimatedBackground(const AnimatedBackground&) = delete;
	//����������� ������������
	AnimatedBackground& operator = (const AnimatedBackground&) = delete;
	//����������� �����������
	AnimatedBackground(AnimatedBackground&&) noexcept;
	//����������� ������������ ������������
	AnimatedBackground& operator = (AnimatedBackground&&) noexcept;

	void update(const float& dt);

	void render();

private:
	std::shared_ptr<Background> landscape;
	std::shared_ptr<Sprite> cloud1, cloud2;
	glm::vec2 positionCloud1 = glm::vec2(0.f, 0.6f), sizeCloud1 = glm::vec2(.2f, .2f), positionCloud2 = glm::vec2(-.3f, 0.6f), sizeCloud2 = glm::vec2(.1f, .1f);
};

#endif