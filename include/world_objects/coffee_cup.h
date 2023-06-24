#pragma once


#include <world_objects/world_object.h>
#include <core/model.h>

class CoffeeCup : public WorldObject {
public:
    CoffeeCup();
    void Init() override;
    void Update(float deltaTime) override;
private:
    void createShaders();

    void createCoffeeCup();
    void createPencilPoint();

private:
    std::shared_ptr<Shader> _basicLitShader;
    std::shared_ptr<Shader> _textureShader;
};