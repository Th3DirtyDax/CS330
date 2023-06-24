/* Ryan P. Gingery
* CS-330  Comp Graphic and Visualization 23EW5
* Course Project
* Professor Philip Enkema
*/



#pragma once
#include <vector>
#include <rendering/types.h>
#include <glad/glad.h>


class Mesh {
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indicies);
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec3& color);
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec2& uvScale, const glm::vec3& color = { 1.f, 1.f, 1.f });


	void Draw() const;
	glm::mat4 Transform{ 1.f };
private:
	void init(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);

private:

	uint32_t _elementCount{ 0 };
	GLuint _vertexArrayObject{};
	GLuint _vertexBufferObject{};
	GLuint _shaderProgram{};
	GLuint _elementBufferObject{};

};