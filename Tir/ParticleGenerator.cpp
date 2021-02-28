#include "ParticleGenerator.h"

const char* particlesVertexShader =
"#version 330 core\n"

"layout(location = 0) in vec2 position;"
"layout(location = 1) in vec2 textureCoord;"

"out vec2 TexCoords;"
"out vec4 ParticleColor;"

"uniform mat4 model;"
"uniform vec4 color;"

"void main() {"
"TexCoords = textureCoord;"
"ParticleColor = color;"
"gl_Position = model * vec4(position, 0., 1.);"
"}";

const char* particleFragmentShader =
"#version 330 core\n"

"in vec2 TexCoords;"
"in vec4 ParticleColor;"

"out vec4 color;"

"uniform sampler2D sprite;"

"void main() {"
"color = texture(sprite, TexCoords) * ParticleColor;"
"}";


ParticleGenerator::ParticleGenerator(std::shared_ptr<Texture2D> texture, const unsigned int& amount)
	: texture(texture), amount(amount), shaderProgram(particlesVertexShader, particleFragmentShader) {
	// �������� ������ (� ������(��)) � ��������� ��������� ���������
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

	// ������������ ��������
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	// �������� ���������� ���������
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	//������� �������� ���������� ���������
	for (int i = 0; i < amount; ++i)
		particles.push_back(Particle());
}

ParticleGenerator::~ParticleGenerator() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

/*
void ParticleGenerator::draw() {
	// ���������� ���������� ����� ���������� ��� �������� ������� ��������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	shaderProgram.use();
	for (const Particle& particle : particles)
		if (particle.getLife() > .0f) {
			glm::mat4 model(1.0f);
			model = glm::translate(model, glm::vec3(particle.getPosition(), .0f));
			model = glm::scale(model, glm::vec3(particle.getSize(), 1.f));
			shaderProgram.setMatrix4("model", model);
			shaderProgram.setVec4("color", particle.getColor());
			texture->bind();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	// �� �������� �������� ����� ���������� � ����������� ����������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//��������������� ������� ��� ���������� ������� ������� ��������������� ��������
unsigned int lastUsedParticle = 0;
unsigned int ParticleGenerator::firstUnusedParticle() {
	// ����� �� ��������� �������������� �������. ��� �������, ��������� ������������ ����� ���������
	for (unsigned int i = lastUsedParticle; i < 500; ++i)
		if (particles[i].getLife() <= 0.0f) return i;

	// � ��������� ������ ��������� �������� �����
	for (unsigned int i = 0; i < lastUsedParticle; ++i)
		if (particles[i].getLife() <= 0.0f) return i;

	// �������������� ������ �������, ���� ��� ��������� ����
	return 0;
}

void respawnParticle(std::shared_ptr<GameObject> gameObject, const glm::vec2 velocity, Particle& particle, const glm::vec2& offset) {
	float random = static_cast<float>((rand() % 200) - 100) / 5000.f;
	float rColor = .5f + (rand() % 100) / 100.0f;
	particle.setPosition(gameObject->getPosition() + random + offset);
	particle.setSize(gameObject->getSize() * .6f);
	particle.setVelocity(velocity * .1f);
	particle.setColor(glm::vec4(rColor, rColor, rColor, 1.0f));
	particle.setLife(1.f);
}

void ParticleGenerator::update(const float& dt, std::shared_ptr<GameObject> gameObject, const unsigned int& amountNewParticles, const glm::vec2& velocity, const glm::vec2& offset) {
	// ��������� ����� �������
	for (unsigned int i = 0; i < amountNewParticles; ++i) {
		int unusedParticle = firstUnusedParticle();
		respawnParticle(gameObject, velocity, particles[unusedParticle], offset);
	}

	// ��������� ��� �������
	for (unsigned int i = 0; i < this->amount; ++i) {
		Particle& p = particles[i];
		// ��������� ����� �����
		p.setLife(p.getLife() - dt);
		// ���� ������� ����, �� ��������� �
		if (p.getLife() > 0.0f) {
			p.setPosition(p.getPosition() - p.getVelocity() * dt);
			p.setColor(p.getColor() - 2.5f * dt);
		}
	}
}
*/