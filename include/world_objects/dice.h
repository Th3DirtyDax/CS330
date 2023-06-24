#pragma once


#include <world_objects/world_object.h>
#include <core/model.h>

class Dice : public WorldObject {
public:
    Dice();
    void Init() override;
    void Update(float deltaTime) override;
private:
    void createShaders();

    void createDSix0();
    void createDSix1();
    void createDSix2();
    void createDSix3();
    void createDFour0();
    void createDFour1();
    void createDFour2();
    void createDFour3();

private:
    std::shared_ptr<Shader> _basicLitShader;
    std::shared_ptr<Shader> _textureShader;
};