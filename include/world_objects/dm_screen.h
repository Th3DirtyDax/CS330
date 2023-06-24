#pragma once
#include <world_objects/world_object.h>
#include <core/model.h>

class DmScreen : public WorldObject {
public:
    DmScreen();
    void Init() override;
    void Update(float deltaTime) override;
private:
    void createShaders();

    void createDmScreen();;
    void createFaceBolts();
    void createStraps();
    void createDMPapers();
    void createDMPapers1();
    void createDMPapers2();
    void createDMPapers3();
    void createMagnet();
    void createMagnet1();


private:
    std::shared_ptr<Shader> _basicLitShader;
    std::shared_ptr<Shader> _textureShader;
};