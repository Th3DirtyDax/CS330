

#include <core/camera.h>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

Camera::Camera(int width, int height, glm::vec3 initialPosition, bool isPerspective) 
	: _isPerspective{ isPerspective }, _position{ initialPosition }, _lookDirection{ 0.f, 0.f, 1.f }, _width {
	width }, _height{ height } {


	recalculateVectors();
}

glm::mat4 Camera::GetViewMatrix() {

	return glm::lookAt(_position, _position + _lookDirection, _upDirection);
}

glm::mat4 Camera::GetProjectionMatrix() const {
	auto aspectRatio = (float)_width / (float)_height;
	if (_isPerspective) {
		return glm::perspective(glm::radians(_fieldOfView), aspectRatio, _nearClip, _farClip);
	}
	else {
		return glm::ortho(-aspectRatio, aspectRatio, -1.f, 1.f, _nearClip, _farClip);
	}
}

void Camera::moveCamera(MoveDirection direction, float moveAmount) {
	glm::vec3 moveDirection{};
	//switch for camera movement. W = forward, S = back, A = left, D = right, Q = up, E = down
	switch (direction) {

		case MoveDirection::Forward:
			moveDirection = _lookDirection;
			break;
		case MoveDirection::Backward:
			moveDirection = -_lookDirection;
			break;
		case MoveDirection::Left:
			moveDirection = -glm::normalize(glm::cross(_lookDirection, _upDirection));
			break;
		case MoveDirection::Right:
			moveDirection = glm::normalize(glm::cross(_lookDirection, _upDirection));
			break;
		case MoveDirection::Up:
			moveDirection = _upDirection;
			break;
		case MoveDirection::Down:
			moveDirection = _downDirection;
			break;
	}

	//direction camera moves, add percentage of direction to camera
	_position += moveDirection * moveAmount;
}

void Camera::RotateBy(float yaw, float pitch) {
	//left right
	_yaw += yaw;
	//up down
	_pitch += pitch;

	//clamps values between -89 and 89. 
	_pitch = std::clamp(_pitch, -89.f, 89.f);

	recalculateVectors();
}


void Camera::IncrementZoom(float zoomAmount) {
	_fieldOfView -= zoomAmount;

	_fieldOfView = std::clamp(_fieldOfView, 1.f, 75.f);
}

void Camera::recalculateVectors() {
	_lookDirection = glm::normalize(glm::vec3{
		// X
		std::cos(glm::radians(_yaw)) * std::cos(glm::radians(_pitch)), 
		//Y
		std::sin(glm::radians(_pitch)),
		//Z
		std::sin(glm::radians(_yaw)) * std::cos(glm::radians(_pitch))
	});

	auto rightDirection = glm::normalize(glm::cross(_lookDirection, glm::vec3(0.f, 1.f, 0.f)));
	_upDirection = glm::normalize(glm::cross(rightDirection, _lookDirection));
}
