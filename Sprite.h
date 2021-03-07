#ifndef SPRITE_H
#define SPRITE_H

#include <memory>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Buffer.h"

class Sprite {
public:
    //����������� �� ���������
    Sprite() = delete;
    //�����������
    Sprite(std::shared_ptr<ShaderProgram> shaderProgram, std::shared_ptr<Texture2D> texture, std::shared_ptr<Buffer> buffer);
    //����������
    ~Sprite() = default;
    //����������� �����������
    Sprite(const Sprite&) = delete;
    //����������� ������������
    Sprite& operator = (const Sprite&) = delete;
    //����������� �����������
    Sprite(Sprite&&) noexcept;
    //����������� ������������ ������������
    Sprite& operator = (Sprite&&) noexcept;

    //�������� ���������������� �������������
    void draw(const glm::vec2& position, const glm::vec2& size = glm::vec2(10.0f, 10.0f), const float& rotate = 0.0f);

private:
    std::shared_ptr <ShaderProgram> shaderProgram;
    std::shared_ptr <Texture2D> texture;
    std::shared_ptr <Buffer> buffer;

};

#endif