/* Ryan P. Gingery
* CS-330  Comp Graphic and Visualization 23EW5
* Course Project
* Professor Philip Enkema
*/

#pragma once

//glad.h comes first as GLFW will supply glad if it is not found, causing errors if glad comes after
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <core/camera.h>
#include <rendering/textures.h>
#include <world_objects/world_object.h>


class Application {
public:
	Application(std::string WindowTitle, int width, int height);

	void Run();

private:
	bool openWindow();
	void SetUpInputs();
	void setupScene();
	bool update(float deltaTime);
	bool draw();

	void handleInput(float deltaTime);
	void mousePositionCallback(double xpos, double ypos);

private:

	std::string _applicationName{};
	int _width{};
	int _height{};
	GLFWwindow* _window{ nullptr };


	float _moveSpeed{ 5.f };
	Camera _camera;
	std::vector<std::unique_ptr<WorldObject>> _objects{};

	Shader _shader;
	bool _running{ false };

	bool _firstMouse{ false };
	glm::vec2 _lastMousePosition{};
	glm::vec2 _cameraLookSpeed{};

	float _lastFrameTime{ -1.f };

	GLuint _shaderProgram{};


	// lighting variables
	float _ambientStrength{ 0.1f };
	glm::vec3 _ambientLightColor{ 1.f, 1.f, 1.f };
};