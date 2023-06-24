#pragma once
#include <world_objects/world_object.h>
#include <core/model.h>

#include <rendering/shader.h>
#include <rendering/mesh.h>

class PointLightTwo : public WorldObject {
public:
    PointLightTwo();

    void Init() override;

    void Update(float deltaTime) override;

    void ProcessLighting(SceneParameters& sceneParameters) override;

public:
    glm::vec3 AmbientColor{ };
    glm::vec3 DiffuseColor{ 1.f, 1.f, 1.f };
    glm::vec3 SpecularColor{ 1.f, 1.f, 1.f };

    float Constant{ 1.f };
    float Linear{ 0.045f };
    float Quadratic{ 0.0075f };

private:
    void createShader();
    void createMesh();

private:
    std::shared_ptr<Shader> _basicUnlitShader{};
    std::shared_ptr<Mesh> _lightMesh{};
};