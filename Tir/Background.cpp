#include "Background.h"

Background::Background(std::shared_ptr<Texture2D> texture, std::shared_ptr<ShaderProgram> shaderProgram, std::shared_ptr<Buffer> buffer) 
	: texture(texture), shaderProgram(shaderProgram), buffer(buffer) {}

Background::Background(Background&& background) noexcept
	: shaderProgram(background.shaderProgram), texture(background.texture), buffer(background.buffer) {}

Background& Background::operator = (Background& background) noexcept {
	shaderProgram = background.shaderProgram;
	texture = background.texture;
	buffer = background.buffer;

	texture = nullptr;
	shaderProgram = nullptr;
	buffer = nullptr;

	return *this;
}

void Background::draw() {
	glActiveTexture(GL_TEXTURE0);
	texture->bind();
	shaderProgram->use();
	buffer->bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}