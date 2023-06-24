#include <world_objects/point_light.h>
#include <core/shapes.h>
#include <glm/ext/matrix_transform.hpp>

PointLight::PointLight() {
    createShader();
    createMesh();
}

void PointLight::Init() {
}

void PointLight::Update(float deltaTime) {

}

void PointLight::ProcessLighting(SceneParameters& sceneParams) {
    if (sceneParams.PointLights.size() < MAX_POINT_LIGHTS) {
        PointLightStruct pointLight{
            .Position = glm::vec3(Transform[3]),
            .AmbientColor = AmbientColor,
            .DiffuseColor = DiffuseColor,
            .SpecularColor = SpecularColor,
            .Constant = Constant,
            .Linear = Linear,
            .Quadratic = Quadratic
        };

        sceneParams.PointLights.emplace_back(pointLight);
    }
}

void PointLight::createShader() {
    _basicUnlitShader = std::make_shared<Shader>(Path("basic_unlit_color.vert"), Path("basic_unlit_color.frag"));
}

void PointLight::createMesh() {
    auto cube = std::make_shared<Mesh>(Shapes::cubeVertices, Shapes::cubeElements, glm::vec3(1.f, 1.f, 1.f));

    auto lightMaterial = std::make_shared<Material>(_basicUnlitShader);
    auto& cubeModel = _models.emplace_back(cube, lightMaterial);
    cubeModel.GetMesh()->Transform = glm::scale(cubeModel.GetMesh()->Transform, glm::vec3(0.5f, 0.5f, 0.5f));

    auto cube2 = std::make_shared<Mesh>(Shapes::cubeTwoVertices, Shapes::cubeTwoElements, glm::vec3(1.f, 1.f, 1.f));

    auto lightMaterial2 = std::make_shared<Material>(_basicUnlitShader);
    auto& cubeModel2 = _models.emplace_back(cube2, lightMaterial2);
    cubeModel2.GetMesh()->Transform = glm::scale(cubeModel2.GetMesh()->Transform, glm::vec3(0.5f, 0.5f, 0.5f));
}