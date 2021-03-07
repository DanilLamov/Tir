#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <memory>

#include "Texture2D.h"
#include "ShaderProgram.h"
#include "Buffer.h"

class Background {
public:
	//����������� �� ���������
	Background() = delete;
	//����������� �� ��������, ��������� ��������� � �������
	Background(std::shared_ptr<Texture2D> texture, 
			   std::shared_ptr<ShaderProgram> shaderProgram, 
			   std::shared_ptr<Buffer> buffer);
	//���������� �� ���������
	~Background() = default;

	//����������� �����������
	Background(const Background&) = delete;
	//����������� ������������
	Background& operator = (const Background&) = delete;
	//����������� �����������
	Background(Background&&) noexcept;
	//����������� ������������� ������������
	Background& operator = (Background&) noexcept;

	//����� ����
	void draw();

private:
	std::shared_ptr<ShaderProgram> shaderProgram;
	std::shared_ptr<Texture2D> texture;
	std::shared_ptr<Buffer> buffer;

};

#endif