#pragma once
#include <glm/glm.hpp>
#include <rendering/types.h>
#include <core/model.h>

// 3D World objects,
class WorldObject {
public:
    ~WorldObject() = default;
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(const SceneParameters& sceneParameters) {
        for (auto& model : _models) {
            auto* mesh = model.GetMesh();

            model.GetMaterial()->Bind(sceneParameters, Transform * mesh->Transform);
            mesh->Draw();
        }
    };

    virtual void ProcessLighting(SceneParameters& sceneParameters) {};
public:
    // default model matrix
    glm::mat4 Transform{ 1.f }; 
    std::vector<Model> _models{};
};