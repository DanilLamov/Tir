#include "Buffer.h"

Buffer::Buffer() {
	//�������� ������
	float vertices[] = {
		//����������    //���������� ����������
		 1.f,  1.f,     1.f, 1.f, // ������� ������ �������
		 1.f, -1.f,     1.f, .0f, // ������ ������ �������
		-1.f, -1.f,     .0f, .0f, // ������ ����� �������
		-1.f,  1.f,     .0f, 1.f  // ������� ����� ������� 
	};

	unsigned int indices[] = {
		0, 1, 3, // ������ �����������
		1, 2, 3  // ������ �����������
	};
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//������������ ��������
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	//�������� ���������� ���������
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

Buffer::~Buffer() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Buffer::bind() {
	glBindVertexArray(VAO);
}