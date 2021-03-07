#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<ShaderProgram> shaderProgram, std::shared_ptr<Texture2D> texture, std::shared_ptr<Buffer> buffer)
    : shaderProgram(shaderProgram), texture(texture), buffer(buffer) {}

Sprite::Sprite(Sprite&& sprite) noexcept
    : shaderProgram(sprite.shaderProgram), texture(sprite.texture), buffer(sprite.buffer) {}

Sprite& Sprite::operator = (Sprite&& sprite) noexcept {
    shaderProgram = sprite.shaderProgram;
    texture = sprite.texture;
    buffer = sprite.buffer;

    texture = nullptr;
    shaderProgram = nullptr;
    buffer = nullptr;

    return *this;
}

void Sprite::draw(const glm::vec2& position, const glm::vec2& size, const float& rotate) {
    // ѕодготовка преобразований
    shaderProgram->use();
    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(position, .0f));
    //перемещаем точку начала поворота в центр пр€моугольника
    //model = glm::translate(model, glm::vec3(.5f * size.x, .5f * size.y, .0f));
    //производим поворот
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    //возвращаем точку поворота в исходную позицию
    //model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    //выполн€ем масштабирование
    model = glm::scale(model, glm::vec3(size, 1.f));

    shaderProgram->setMatrix4("model", model);

    //рендерим текстурированный пр€моугольник
    glActiveTexture(GL_TEXTURE0);
    texture->bind();
    buffer->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}