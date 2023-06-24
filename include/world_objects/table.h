#pragma once
#include <world_objects/world_object.h>
#include <core/model.h>

class Table : public WorldObject {
public:
    Table();
    void Init() override;
    void Update(float deltaTime) override;
private:
    void createShaders();

    void createModel();
    void createPCSheet();

private:
    std::shared_ptr<Shader> _basicLitShader;
};