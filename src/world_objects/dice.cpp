
#include <world_objects/dice.h>
#include <core/shapes.h>
#include <glm/gtc/matrix_transform.hpp>

Dice::Dice() {
    createShaders();
    createDSix0();
    createDSix1();
    createDSix2();
    createDSix3();
    createDFour0();
    createDFour1();
    createDFour2();
    createDFour3();

}

void Dice::Init() {

}

void Dice::Update(float deltaTime) {

}

void Dice::createShaders() {
    _basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Dice::createDSix0() {
    auto dSix = std::make_shared<Mesh>(Shapes::dSixVertices, Shapes::dSixElements, glm::vec3(1.f, 1.f, 1.f));

    auto dSixTexturePath = Path("extras");
    auto dSixTexture = std::make_shared<Texture>(dSixTexturePath / "dice.jpg");

    auto dSixMaterial = std::make_shared<Material>(_basicLitShader);
    dSixMaterial->AddTexture(dSixTexture);
    dSixMaterial->Shininess = 0.5f;

    _models.emplace_back(dSix, dSixMaterial);

}

void Dice::createDSix1() {
    auto dSix = std::make_shared<Mesh>(Shapes::dSix1Vertices, Shapes::dSix1Elements, glm::vec3(1.f, 1.f, 1.f));

    auto dSixTexturePath = Path("extras");
    auto dSixTexture = std::make_shared<Texture>(dSixTexturePath / "dice.jpg");

    auto dSixMaterial = std::make_shared<Material>(_basicLitShader);
    dSixMaterial->AddTexture(dSixTexture);
    dSixMaterial->Shininess = 0.5f;

    _models.emplace_back(dSix, dSixMaterial);
    dSix->Transform = glm::translate(dSix->Transform, glm::vec3(1.f, 0.1f, 2.f));
}

void Dice::createDSix2() {
    auto dSix = std::make_shared<Mesh>(Shapes::dSix2Vertices, Shapes::dSix2Elements, glm::vec3(1.f, 1.f, 1.f));

    auto dSixTexturePath = Path("extras");
    auto dSixTexture = std::make_shared<Texture>(dSixTexturePath / "dice.jpg");

    auto dSixMaterial = std::make_shared<Material>(_basicLitShader);
    dSixMaterial->AddTexture(dSixTexture);
    dSixMaterial->Shininess = 0.5f;

    _models.emplace_back(dSix, dSixMaterial);
    dSix->Transform = glm::translate(dSix->Transform, glm::vec3(3.f, 0.1f, 0.3f));
}

void Dice::createDSix3() {
    auto dSix = std::make_shared<Mesh>(Shapes::dSix3Vertices, Shapes::dSix3Elements, glm::vec3(1.f, 1.f, 1.f));

    auto dSixTexturePath = Path("extras");
    auto dSixTexture = std::make_shared<Texture>(dSixTexturePath / "dice.jpg");

    auto dSixMaterial = std::make_shared<Material>(_basicLitShader);
    dSixMaterial->AddTexture(dSixTexture);
    dSixMaterial->Shininess = 0.5f;

    _models.emplace_back(dSix, dSixMaterial);
    dSix->Transform = glm::translate(dSix->Transform, glm::vec3(-4.f, 0.1f, 0.3f));
}

void Dice::createDFour0() {
    auto dFour = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto dFourTexturePath = Path("extras");
    auto dFourTexture = std::make_shared<Texture>(dFourTexturePath / "dice.jpg");

    auto dFourMaterial = std::make_shared<Material>(_basicLitShader);
    dFourMaterial->AddTexture(dFourTexture);
    dFourMaterial->Shininess = 0.5f;

    _models.emplace_back(dFour, dFourMaterial);
    dFour->Transform = glm::translate(dFour->Transform, glm::vec3(0.f, 0.1f, 1.4f));
}

void Dice::createDFour1() {
    auto dFour = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto dFourTexturePath = Path("extras");
    auto dFourTexture = std::make_shared<Texture>(dFourTexturePath / "dice.jpg");

    auto dFourMaterial = std::make_shared<Material>(_basicLitShader);
    dFourMaterial->AddTexture(dFourTexture);
    dFourMaterial->Shininess = 0.5f;

    _models.emplace_back(dFour, dFourMaterial);
    dFour->Transform = glm::translate(dFour->Transform, glm::vec3(3.f, 0.1f, -0.8f));
}

void Dice::createDFour2() {
    auto dFour = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto dFourTexturePath = Path("extras");
    auto dFourTexture = std::make_shared<Texture>(dFourTexturePath / "dice.jpg");

    auto dFourMaterial = std::make_shared<Material>(_basicLitShader);
    dFourMaterial->AddTexture(dFourTexture);
    dFourMaterial->Shininess = 0.5f;

    _models.emplace_back(dFour, dFourMaterial);
    dFour->Transform = glm::translate(dFour->Transform, glm::vec3(-6.f, 0.1f, 1.4f));
}

void Dice::createDFour3() {
    auto dFour = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto dFourTexturePath = Path("extras");
    auto dFourTexture = std::make_shared<Texture>(dFourTexturePath / "dice.jpg");

    auto dFourMaterial = std::make_shared<Material>(_basicLitShader);
    dFourMaterial->AddTexture(dFourTexture);
    dFourMaterial->Shininess = 0.5f;

    _models.emplace_back(dFour, dFourMaterial);
    dFour->Transform = glm::translate(dFour->Transform, glm::vec3(-1.5f, 0.1f, 1.1f));
}