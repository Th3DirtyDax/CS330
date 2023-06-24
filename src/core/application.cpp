/* Ryan P. Gingery
* CS-330  Comp Graphic and Visualization 23EW5
* Course Project
* Professor Philip Enkema
*/

#include <core/application.h>
#include <iostream>
#include <rendering/types.h>
#include <vector>
#include <rendering/Mesh.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <glm/gtx/transform.hpp>
#include <world_objects/dm_screen.h>
#include <world_objects/table.h>
#include <world_objects/point_light.h>
#include <world_objects/dir_light.h>
#include <world_objects/book.h>
#include <world_objects/pyramid.h>
#include <world_objects/point_light_two.h>
#include <world_objects/coffee_cup.h>
#include <world_objects/dice.h>

Application::Application(std::string WindowTitle, int width, int height) : _applicationName{ WindowTitle }, _width{ width }, _height{ height }, _camera{ width, height, {0.f, 1.f, 3.f}, true }, _cameraLookSpeed{0.15f, 0.15f} {}



void Application::Run() {
	//Open the window
	if (!openWindow()) {
		return;
	}

	SetUpInputs();

	_running = true;

	//Setup scene
	setupScene();

	//Run application
	while (_running) {

		float currentTime = glfwGetTime();
		if (_lastFrameTime == -1.f) {
			_lastFrameTime = currentTime;
		}

		auto deltaTime = currentTime - _lastFrameTime;
		_lastFrameTime = currentTime;

		if (glfwWindowShouldClose(_window)) {
			_running = false;
			continue;
		}

		//Update
		update(deltaTime);
		//Draw
		draw();


	}
	//terminate glfw
	glfwTerminate();

}

bool Application::openWindow() {

	//Initializes the window
	glfwInit();
	//which version of OpenGL we want it to be compatible with
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	//Use these values when opening window to initialize everything
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Set the parameters and values for the size of the window with the title
	_window = glfwCreateWindow(800, 600, "LearnOpenGL: Ryan P. Gingery", nullptr, nullptr);

	//if statement to terminate or show console error if window failed to create
	// !window is same as window == nullptr, nullptr resolves to 0 and 0 resolves to boolean, 0 == false, not false then true.
	if (!_window) {
		std::cerr << "Failed to create GLFW window!" << std::endl;
		//terminate GLFW
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);

	//call window, give a vcoid pointer to retrieve from inside callback. 
	glfwSetWindowUserPointer(_window, (void*)this);

	//Window resized or initialized will set callback frame buffer resize. 
	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
		//This gets called whenever the window is resized
		glViewport(0, 0, width, height);

		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->_width = width;
		app->_height = height;

		app->_camera.SetSize(width, height);
	});

	//Load OpenGL functions with GLAD loader
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD!" << std::endl;
		//terminate GLFW
		glfwTerminate();
		//kills openGL
		return false;
	}

	//enable depth
	glEnable(GL_DEPTH_TEST);

	// cull back faces and show if any triangles are set up incorrectly
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	// enable MSAA
	glEnable(GL_MULTISAMPLE);

	return true;

}

void Application::SetUpInputs() {

	glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		//if escape key is hit, close window
	if (key == GLFW_KEY_ESCAPE) {
		if (action == GLFW_PRESS) {
			app->_running = false;
		}
		}
	if (key == GLFW_KEY_P) {
		if (action == GLFW_PRESS) {
			app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
		}
	}
	});

	glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xpos, double ypos) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->mousePositionCallback(xpos, ypos);
	});

	glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->_moveSpeed += static_cast<float>(yOffset * 0.5f);
		app->_moveSpeed = std::clamp(app->_moveSpeed, 0.5f, 40.f);

		std::cout << "New move speed: " << app->_moveSpeed << " units per second." << std::endl;
	});

	glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT: 
				if (action == GLFW_PRESS) {
					std::cout << "Left Mouse Button Pressed" << std::endl;
				}
				else {
					std::cout << "Left Mouse Button Released" << std::endl;
				}
				break;
			
			case GLFW_MOUSE_BUTTON_MIDDLE: 
				if (action == GLFW_PRESS) {
					std::cout << "Middle Mouse Button Pressed" << std::endl;
				}
				else {
					std::cout << "Middle Mouse Button Released" << std::endl;
				}
				break;
			
			case GLFW_MOUSE_BUTTON_RIGHT: 
				if (action == GLFW_PRESS) {
					std::cout << "Right Mouse Button Pressed" << std::endl;
				}
				else {
					std::cout << "Right Mouse Button Released" << std::endl;
				}
				break;
			
			default:
				std::cout << "Unhandled Mouse Button Event." << std::endl;
		}
	});
}



void Application::setupScene() {

	// Create the table
	auto& table = _objects.emplace_back(std::make_unique<Table>());
	//_objects.emplace_back(std::make_unique<Table>());

	//Generate the Dungeon Master Screen
	auto& dmScreen = _objects.emplace_back(std::make_unique<DmScreen>());
	
	//Generate Dungeon Masters Guide
	auto& cover = _objects.emplace_back(std::make_unique<DmgBook>());
	cover->Transform = glm::translate(cover->Transform, glm::vec3(-0.4f, 0.f, 0.f));

	//Make the coffee cup
	auto& coffeeCup = _objects.emplace_back(std::make_unique<CoffeeCup>());
	coffeeCup->Transform = glm::translate(coffeeCup->Transform, glm::vec3(-0.2f, 0.01f, 1.3f));
	coffeeCup->Transform = glm::rotate(coffeeCup->Transform, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	coffeeCup->Transform = glm::scale(coffeeCup->Transform, glm::vec3(0.5f, 0.5f, 0.5f));

	//Make the dice
	auto& dice = _objects.emplace_back(std::make_unique<Dice>());
	dice->Transform = glm::translate(dice->Transform, glm::vec3(-1.f, 0.05f, 1.f));
	dice->Transform = glm::scale(dice->Transform, glm::vec3(0.1f, 0.1f, 0.1f));

	// add the first light 
	auto& pointLight = _objects.emplace_back(std::make_unique<PointLight>());
	//set the location of the light. 
	pointLight->Transform = glm::translate(pointLight->Transform, glm::vec3(0.f, 5.f, 2.f));
	auto* castLight = reinterpret_cast<PointLight*>(pointLight.get());
	// overriding the constant to make it brighter
	castLight->Constant = 1.f; 
	castLight->Linear = 1.f;
	castLight->Quadratic = 1.f;

	//// add the second light to the right of the pyramid
	//auto& pointLight1 = _objects.emplace_back(std::make_unique<PointLightTwo>());
	////set the location of the light. 
	//pointLight1->Transform = glm::translate(pointLight1->Transform, glm::vec3(3.f, 0.4f, 0.f));
	//auto* castLight1 = reinterpret_cast<PointLight*>(pointLight1.get());
	//// overriding the constant to make it brighter
	//castLight1->Constant = .01f;
	//castLight1->Linear = 0.01f;
	//castLight1->Quadratic = 0.01f;



	auto& ambientDirLight = _objects.emplace_back(std::make_unique<DirLight>());
	ambientDirLight->Transform = glm::translate(ambientDirLight->Transform, glm::vec3(-2.f, 1.5f, 0.f));

	auto* dirLightObj = reinterpret_cast<DirLight*>(ambientDirLight.get());
	dirLightObj->AmbientIntensity = 0.15f;
	dirLightObj->AmbientColor = { 1.f, 1.f, 1.f };

	////////////////////
	//Pyramid for assignment
	//auto& pyramid = _objects.emplace_back(std::make_unique<Pyramid>());


}


bool Application::update(float deltaTime) {
	glfwPollEvents();

	handleInput(deltaTime);

	// Call the update function on all of the objects in scene
	for (auto& object : _objects) {
		object->Update(deltaTime);
	}

	return false;
}

bool Application::draw() {


	//Clear colors on the screen using the GL clear color.
	glClearColor(0.0f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //camera   
	glm::mat4 view = _camera.GetViewMatrix();
	glm::mat4 projection = _camera.GetProjectionMatrix();

	// Scene parameters that will hold data required by shaders.
	SceneParameters sceneParameters{
		.ProjectionMatrix = projection,
		.ViewMatrix = view,
		.CameraPosition = _camera.GetPosition(),
	};

	// Gather the lighting data within the scene and then store it in sceneParameters
	for (auto& model : _objects) {
		model->ProcessLighting(sceneParameters);
	}

	// Draw all models into the scene
	for (auto& model : _objects) {
		model->Draw(sceneParameters);
	}

	glfwSwapBuffers(_window);

	return false;

}

void Application::handleInput(float deltaTime) {

	//if statements to control up, down, left, and right movement with WASDQE
	auto moveAmount = _moveSpeed * deltaTime;
	if (glfwGetKey(_window, GLFW_KEY_W)) {
		_camera.moveCamera(Camera::MoveDirection::Forward, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_S)) {
		_camera.moveCamera(Camera::MoveDirection::Backward, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_A)) {
		_camera.moveCamera(Camera::MoveDirection::Left, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_D)) {
		_camera.moveCamera(Camera::MoveDirection::Right, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_Q)) {
		_camera.moveCamera(Camera::MoveDirection::Up, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_E)) {
		_camera.moveCamera(Camera::MoveDirection::Down, moveAmount);
	}

	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);

	mousePositionCallback(xpos, ypos);
}

void Application::mousePositionCallback(double xpos, double ypos) {
	if (!_firstMouse) {
		_lastMousePosition.x = static_cast<float>(xpos);
		_lastMousePosition.y = static_cast<float>(ypos);
		_firstMouse = true;
	}
	glm::vec2 moveAmount{
		xpos - _lastMousePosition.x,
		_lastMousePosition.y- ypos
	};

	_lastMousePosition.x = static_cast<float>(xpos);
	_lastMousePosition.y = static_cast<float>(ypos);

	_camera.RotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}
