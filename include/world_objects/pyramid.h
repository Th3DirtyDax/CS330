#pragma once

#include <world_objects/world_object.h>

class Pyramid : public WorldObject {
public:
    Pyramid();
    void Init() override;

    void Update(float deltaTime) override;

private:
    void createShaders();

    void createPyramid();

private:
    std::shared_ptr<Shader> _basicLitShader;
    std::shared_ptr<Shader> _textureShader;


};