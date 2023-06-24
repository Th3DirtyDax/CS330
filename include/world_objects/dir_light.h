#pragma once
#include <world_objects/world_object.h>

#include <rendering/shader.h>
#include <rendering/mesh.h>

class DirLight : public WorldObject {
public:
    DirLight();

    void Init() override;

    void Update(float deltaTime) override;

    void ProcessLighting(SceneParameters& sceneParameters) override;

    void SetRenderColor(const glm::vec3& renderColor);

    void Draw(const SceneParameters& sceneParameters) override;

public:
    glm::vec3 AmbientColor{};
    glm::vec3 DiffuseColor{};
    glm::vec3 SpecularColor{};

    float AmbientIntensity{ 0.f };
    float SpecularIntensity{ 0.f };
    float DiffuseIntensity{ 0.f };

private:
    void createShader();
    void createMesh();

private:
    std::shared_ptr<Shader> _basicUnlitShader{};
    std::shared_ptr<Mesh> _lightMesh{};

    glm::vec3 _renderColor{ 1.f, 1.f, 1.f };
};