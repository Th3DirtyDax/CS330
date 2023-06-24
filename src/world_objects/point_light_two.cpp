#include <world_objects/point_light_two.h>
#include <core/shapes.h>
#include <glm/ext/matrix_transform.hpp>

PointLightTwo::PointLightTwo() {
    createShader();
    createMesh();
}

void PointLightTwo::Init() {
}

void PointLightTwo::Update(float deltaTime) {

}

void PointLightTwo::ProcessLighting(SceneParameters& sceneParams) {
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

void PointLightTwo::createShader() {
    _basicUnlitShader = std::make_shared<Shader>(Path("basic_unlit_color.vert"), Path("basic_unlit_color.frag"));
}

void PointLightTwo::createMesh() {
    /*auto cube = std::make_shared<Mesh>(Shapes::cubeTwoVertices, Shapes::cubeTwoElements, glm::vec3(1.f, 1.f, 1.f));

    auto lightMaterial = std::make_shared<Material>(_basicUnlitShader);
    auto& cubeModel = _models.emplace_back(cube, lightMaterial);
    cubeModel.GetMesh()->Transform = glm::scale(cubeModel.GetMesh()->Transform, glm::vec3(0.5f, 0.5f, 0.5f));*/
}