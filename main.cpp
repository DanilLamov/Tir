#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "ResourceManager.h"
#include "Game.h"

// ���������
const unsigned int SCR_WIDTH = 1024;
const unsigned int SCR_HEIGHT = 768;

Game breakout(SCR_WIDTH, SCR_HEIGHT);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    // ����� ������������ �������� ������� Escape, �� ������������� ��� �������� WindowShouldClose �������� true, �������� ����������
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024)
        if (action == GLFW_PRESS) breakout.pressKey(key);
        else if (action == GLFW_RELEASE) breakout.releaseKey(key);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // ����������, ��� ���� ��������� ������������� ����� �������� ����.
    // �������� ��������, ������ � ������ ����� ����������� ������, ��� �������, �� Retina-��������
    glViewport(0, 0, width, height);
}

int main(int argc, char** argv) {
    //glfw: ������������� � ����������������    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glfwWindowHint(GLFW_SAMPLES, 4);
    //glfw: �������� ����
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Tir", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glad: �������� ���� ���������� �� OpenGL-�������
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // ������������ OpenGL
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    //���������� ����� ���������������
    //glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ResourceManager::setExecutablePath(*argv);

    breakout.init();

    float deltaTime = 0.f, lastFrame = 0.f;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // ���� ����������
    while (!glfwWindowShouldClose(window)) {
        // ���������� ������ �������
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // ������������ ���������������� ���� � ����������
        breakout.input(deltaTime);

        // ��������� ��������� ����
        breakout.update(deltaTime);


        // ���������
        glClear(GL_COLOR_BUFFER_BIT);

        breakout.render();

        // glfw: ����� ���������� front- � back- �������. ������������ ������� �����/������ (���� �� ������/�������� ������, ��������� ������ ���� � �.�.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: ����������, ������������ ���� ���������� ����� GLFW-�������
    glfwTerminate();
    return 0;
}