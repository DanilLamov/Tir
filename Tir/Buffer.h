#ifndef BUFFER_H
#define BUFFER_H

#include <glad/glad.h>

class Buffer {
public:
    //����������� �� ���������
    Buffer();
    //����������
    ~Buffer();

    //�����������
    void bind();

private:
    GLuint VAO, VBO, EBO;

};

#endif