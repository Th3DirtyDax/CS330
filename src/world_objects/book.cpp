#include <world_objects/book.h>
#include <core/shapes.h>
#include <glm/gtc/matrix_transform.hpp>

DmgBook::DmgBook() {
    createShaders();
    createDmgBook();
    createDmgpages();
    createDmgSpine();
}

void DmgBook::Init() {

}

void DmgBook::Update(float deltaTime) {

}

void DmgBook::createShaders() {
    _basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void DmgBook::createDmgBook() {
    auto cover = std::make_shared<Mesh>(Shapes::coverVertices, Shapes::coverElements, glm::vec3(1.f, 1.f, 1.f));

    auto coverTexturePath = Path("DMG");
    auto coverTexture = std::make_shared<Texture>(coverTexturePath / "DMGBook.jpg");

    auto coverMaterial = std::make_shared<Material>(_basicLitShader);
    coverMaterial->AddTexture(coverTexture);
    coverMaterial->Shininess = 0.5f;

    _models.emplace_back(cover, coverMaterial);

}

void DmgBook::createDmgpages() {
    auto bookPages = std::make_shared<Mesh>(Shapes::paperVertices, Shapes::paperElements);

    auto paperTexturePath = Path("DMG");
    auto paperTexture = std::make_shared<Texture>(paperTexturePath / "bookpages.jpg");

    auto paperMaterial = std::make_shared<Material>(_basicLitShader);
    paperMaterial->AddTexture(paperTexture);
    paperMaterial->Shininess = 0.5f;

    _models.emplace_back(bookPages, paperMaterial);
}

void DmgBook::createDmgSpine() {
    auto spine = std::make_shared<Mesh>(Shapes::spineVertices, Shapes::spineElements, glm::vec3(1.f, 1.f, 1.f));

    auto spineTexturePath = Path("DMG");
    auto spineTexture = std::make_shared<Texture>(spineTexturePath / "DMGBookSpine.jpg");

    auto coverMaterial = std::make_shared<Material>(_basicLitShader);
    coverMaterial->AddTexture(spineTexture);
    coverMaterial->Shininess = 0.5f;

    _models.emplace_back(spine, coverMaterial);

}
