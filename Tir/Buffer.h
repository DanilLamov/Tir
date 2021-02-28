#ifndef BUFFER_H
#define BUFFER_H

#include <glad/glad.h>

class Buffer {
public:
    //конструктор по усолчанию
    Buffer();
    //деструктор
    ~Buffer();

    //подключение
    void bind();

private:
    GLuint VAO, VBO, EBO;

};

#endif