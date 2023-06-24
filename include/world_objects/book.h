#pragma once

#include <world_objects/world_object.h>

class DmgBook : public WorldObject {
public:
    DmgBook();
    void Init() override;

    void Update(float deltaTime) override;

private:
    void createShaders();
    
    void createDmgBook();
    void createDmgpages();
    void createDmgSpine();

private:
    std::shared_ptr<Shader> _basicLitShader;
    std::shared_ptr<Shader> _textureShader;

    
};