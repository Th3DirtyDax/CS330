#include <world_objects/coffee_cup.h>
#include <core/shapes.h>
#include <glm/gtc/matrix_transform.hpp>

CoffeeCup::CoffeeCup() {
    createShaders();
    createCoffeeCup();
    createPencilPoint();
}

void CoffeeCup::Init() {

}

void CoffeeCup::Update(float deltaTime) {

}

void CoffeeCup::createShaders() {
    _basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}


/// <summary>
/// Changed to a pencil instead but no eraser and point added. 
/// </summary>
void CoffeeCup::createCoffeeCup() {
    auto [cylinderVertices, cylinderIndices] = Shapes::BuildSmoothCylinder(50, 1.2f, 0.3f);
    auto cup = std::make_shared<Mesh>(cylinderVertices, cylinderIndices, glm::vec2{ 1.f, 1.f });

    auto cupTexturePath = Path("extras");

    auto cupMaterial = std::make_shared<Material>(_basicLitShader);
    cupMaterial->AddTexture(std::make_shared<Texture>(cupTexturePath / "pencil.jpg",
        Texture::SamplerSettings{
             .S = Texture::SamplerTileMode::MirroredRepeat,
             .T = Texture::SamplerTileMode::MirroredRepeat,
        }));
    cupMaterial->Shininess = 0.5f;

    _models.emplace_back(cup, cupMaterial);

    cup->Transform = glm::translate(cup->Transform, glm::vec3(0.3f, 0.01f, 1.f));
    cup->Transform = glm::rotate(cup->Transform, glm::radians(90.f), glm::vec3(1.5f, 0.f, 0.f));
    cup->Transform = glm::rotate(cup->Transform, glm::radians(90.f), glm::vec3(0.f, 1.5f, 0.f));
    cup->Transform = glm::rotate(cup->Transform, glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f));
    cup->Transform = glm::scale(cup->Transform, glm::vec3(0.01f, 0.01f, 2.5f));

}

void CoffeeCup::createPencilPoint() {
    auto point = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto pointTexturePath = Path("extras");
    auto pointTexture = std::make_shared<Texture>(pointTexturePath / "pencilpoint.jpg");

    auto pointMaterial = std::make_shared<Material>(_basicLitShader);
    pointMaterial->AddTexture(pointTexture);
    pointMaterial->Shininess = 0.2f;
    pointMaterial->Roughness = 0.5f;

    _models.emplace_back(point, pointMaterial);
    point->Transform = glm::translate(point->Transform, glm::vec3(-0.085f, 0.01f, 1.f));
    point->Transform = glm::rotate(point->Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
    //point->Transform = glm::rotate(point->Transform, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
    point->Transform = glm::rotate(point->Transform, glm::radians(90.f), glm::vec3(0.f, 0.f, 2.f));
    point->Transform = glm::scale(point->Transform, glm::vec3(0.02f, 0.02f, 0.02f));
}


