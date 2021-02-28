#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
public:
	//����������� �� ���������
	ShaderProgram() = delete;
	//����������� �� ���������� � ��������� ���������
	ShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, const std::string& geometryShaderSource = "");
	//����������
	~ShaderProgram();

	//����������� �����������
	ShaderProgram(ShaderProgram&) = delete;
	//����������� ������������
	ShaderProgram& operator = (const ShaderProgram&) = delete;
	//����������� �����������
	ShaderProgram(ShaderProgram&&) noexcept;
	//���������� ������������ ������������
	ShaderProgram& operator = (ShaderProgram&&) noexcept;

	//���������� ��������� ����������
	void use() const;

	//��������� �������� ������� ���������� ���� int
	void setInt(const std::string& name, const GLint& value);
	//��������� �������� ������� ���������� ���� vec2 ���������� ���� vec2
	void setVec2(const std::string& name, const glm::vec2& value);
	//��������� �������� ������� ���������� ���� vec2 ����� ����������� ���� float
	void setVec2(const std::string& name, const float& x, const float& y);
	//��������� �������� ������� ���������� ���� vec3 ���������� ���� vec3
	void setVec3(const std::string& name, const glm::vec3& value);
	//��������� �������� ������� ���������� ���� vec3 ����� ����������� ���� float
	void setVec3(const std::string& name, const float& x, const float& y, const float& z);
	//��������� �������� ������� ���������� ���� vec4 ���������� ���� vec4
	void setVec4(const std::string& name, const glm::vec4& value);
	//��������� �������� ������� ���������� ���� vec4 �������� ����������� ���� float
	void setVec4(const std::string& name, const float& x, const float& y, const float& z, const float& w);
	//��������� �������� ������� ���������� ���� mat4
	void setMatrix4(const std::string& name, const glm::mat4& matrix);


private:
	GLuint ID = 0;

	//��������������� ������� ��� �������� ������� ��������� ����
	static bool createShader(const std::string& shaderSource, const GLenum shaderType, GLuint& shaderID);

};

#endif