#include "Buffer.h"

Buffer::Buffer() {
	//указание вершин
	float vertices[] = {
		//координаты    //текстурные координаты
		 1.f,  1.f,     1.f, 1.f, // верхняя правая вершина
		 1.f, -1.f,     1.f, .0f, // нижняя правая вершина
		-1.f, -1.f,     .0f, .0f, // нижняя левая вершина
		-1.f,  1.f,     .0f, 1.f  // верхняя левая вершина 
	};

	unsigned int indices[] = {
		0, 1, 3, // первый треугольник
		1, 2, 3  // второй треугольник
	};
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//координатные атрибуты
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	//атрибуты текстурных координат
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