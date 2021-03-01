#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <glad/glad.h>
#include <glm/vec2.hpp>

#include <string>
#include <map>

class Texture2D {
public:
	//������������ �� ���������
	Texture2D() = delete;
	//�����������
	Texture2D(const GLuint& width, 
			  const GLuint& height, 
			  const unsigned char* data,
			  const unsigned int& channels = 4, 
			  const GLenum& filter = GL_LINEAR, 
			  const GLenum& wrapMode = GL_CLAMP_TO_EDGE);
	//����������
	~Texture2D();
	//����������� �����������
	Texture2D(const Texture2D&) = delete;
	//����������� ������������
	Texture2D& operator = (const Texture2D&) = delete;
	//����������� ����������
	Texture2D(Texture2D&&) noexcept;
	//����������� ������������� ������������
	Texture2D& operator = (Texture2D&&) noexcept;

	//���������� ������
	unsigned getWidth() const;
	//���������� ������
	unsigned getHeight() const;

	//���������� ��������
	void bind() const;

private:
	GLuint ID;
	unsigned int width, height;

};

#endif