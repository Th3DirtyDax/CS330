#include <world_objects/dm_screen.h>
#include <core/material.h>
#include <rendering/types.h>
#include <glm/gtc/matrix_transform.hpp>
#include <core/shapes.h>

DmScreen::DmScreen() {
    createShaders();
    createDmScreen();;
    createFaceBolts();
    createStraps();
    createDMPapers();
    createDMPapers1();
    createDMPapers2();
    createDMPapers3();
    createMagnet();
    createMagnet1();
}

void DmScreen::Init() {

}

void DmScreen::Update(float deltaTime) {

}

void DmScreen::createShaders() {
    _basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void DmScreen::createDmScreen() {
    auto mainBoard = std::make_shared<Mesh>(Shapes::dmScreenMainVertices, Shapes::dmScreenMainElements, glm::vec3(1.f, 1.f, 1.f));
    auto leftBoard = std::make_shared<Mesh>(Shapes::dmScreenLeftVertices, Shapes::dmScreenLeftElements, glm::vec3(1.f, 1.f, 1.f));
    auto rightBoard = std::make_shared<Mesh>(Shapes::dmScreenRightVertices, Shapes::dmScreenRightElements, glm::vec3(1.f, 1.f, 1.f));

    auto boardTexturePath = Path("dmscreen");
    auto boardTexture = std::make_shared<Texture>(boardTexturePath / "wood.jpg");

    auto woodMaterial = std::make_shared <Material>(_basicLitShader);
    woodMaterial->AddTexture(boardTexture);
    woodMaterial->Shininess = 0.1f;
    woodMaterial->Roughness = 1.f;
    
    _models.emplace_back(mainBoard, woodMaterial);
    _models.emplace_back(leftBoard, woodMaterial);
    _models.emplace_back(rightBoard, woodMaterial);

}

void DmScreen::createFaceBolts() {
    auto centerFaceBolts = std::make_shared<Mesh>(Shapes::centerBoltVertices, Shapes::centerBoltElement, glm::vec3(1.f, 1.f, 1.f));
    auto leftFaceBolts = std::make_shared<Mesh>(Shapes::farLeftBoltVertices, Shapes::farLeftBoltElement, glm::vec3(1.f, 1.f, 1.f));
    auto rightFaceBolts = std::make_shared<Mesh>(Shapes::farRightBoltVertices, Shapes::farRightBoltElement, glm::vec3(1.f, 1.f, 1.f));
    auto leftSmallFaceBolts = std::make_shared<Mesh>(Shapes::smallLeftBoltVertices, Shapes::smallLeftBoltElement, glm::vec3(1.f, 1.f, 1.f));
    auto rightSmallFaceBolts = std::make_shared<Mesh>(Shapes::smallRightBoltVertices, Shapes::smallRightBoltElement, glm::vec3(1.f, 1.f, 1.f));

    auto boltTexturePath = Path("dmscreen");
    auto boltTexture = std::make_shared<Texture>(boltTexturePath / "stud.jpg");

    auto boltMaterial = std::make_shared <Material>(_basicLitShader);
    boltMaterial->AddTexture(boltTexture);
    boltMaterial->Shininess = 0.5f;
    boltMaterial->Roughness = 1.f;

    _models.emplace_back(centerFaceBolts, boltMaterial);
    _models.emplace_back(leftFaceBolts, boltMaterial);
    _models.emplace_back(rightFaceBolts, boltMaterial);
    _models.emplace_back(leftSmallFaceBolts, boltMaterial);
    _models.emplace_back(rightSmallFaceBolts, boltMaterial);
}

void DmScreen::createStraps() {
    auto straps = std::make_shared<Mesh>(Shapes::strapsVertices, Shapes::strapsElements, glm::vec3(1.f, 1.f, 1.f));
        
    auto strapTexturePath = Path("dmscreen");
    auto strapTexture = std::make_shared<Texture>(strapTexturePath / "leather.jpg");

    auto strapMaterial = std::make_shared <Material>(_basicLitShader);
    strapMaterial->AddTexture(strapTexture);
    strapMaterial->Shininess = 0.1f;
    strapMaterial->Roughness = 2.f;

    _models.emplace_back(straps, strapMaterial);
}

void DmScreen::createDMPapers() {
    auto dmPapers = std::make_shared<Mesh>(Shapes::dmPaperVertices, Shapes::dmPaperElements, glm::vec2(1.f, 1.f));

    auto dmPapersTexturePath = Path("dmscreen");
    auto dmPapersTexture = std::make_shared<Texture>(dmPapersTexturePath / "beholder_page.jpg");

    auto dmPapersMaterial = std::make_shared <Material>(_basicLitShader);
    dmPapersMaterial->AddTexture(dmPapersTexture);
    dmPapersMaterial->Shininess = 0.4f;
    dmPapersMaterial->Roughness = 0.5f;

    _models.emplace_back(dmPapers, dmPapersMaterial);
}

void DmScreen::createDMPapers1() {
    auto dmPapers1 = std::make_shared<Mesh>(Shapes::dmPaper1Vertices, Shapes::dmPaper1Elements, glm::vec2(1.f, 1.f));

    auto dmPapers1TexturePath = Path("dmscreen");
    auto dmPapers1Texture = std::make_shared<Texture>(dmPapers1TexturePath / "red_dragon.jpg");

    auto dmPapers1Material = std::make_shared <Material>(_basicLitShader);
    dmPapers1Material->AddTexture(dmPapers1Texture);
    dmPapers1Material->Shininess = 0.4f;
    dmPapers1Material->Roughness = 0.5f;

    _models.emplace_back(dmPapers1, dmPapers1Material);
}

void DmScreen::createDMPapers2() {

    auto dmPapers2 = std::make_shared<Mesh>(Shapes::dmPaper2Vertices, Shapes::dmPaper2Elements, glm::vec2(1.f, 1.f));

    auto dmPapers2TexturePath = Path("dmscreen");
    auto dmPapers2Texture = std::make_shared<Texture>(dmPapers2TexturePath / "random_names.png");

    auto dmPapers2Material = std::make_shared <Material>(_basicLitShader);
    dmPapers2Material->AddTexture(dmPapers2Texture);
    dmPapers2Material->Shininess = 0.4f;
    dmPapers2Material->Roughness = 0.5f;

    _models.emplace_back(dmPapers2, dmPapers2Material);


}

void DmScreen::createDMPapers3() {
    auto dmPapers = std::make_shared<Mesh>(Shapes::dmPaperVertices, Shapes::dmPaperElements, glm::vec2(1.f, 1.f));

    auto dmPapersTexturePath = Path("dmscreen");
    auto dmPapersTexture = std::make_shared<Texture>(dmPapersTexturePath / "dmnotes.jpg");

    auto dmPapersMaterial = std::make_shared <Material>(_basicLitShader);
    dmPapersMaterial->AddTexture(dmPapersTexture);
    dmPapersMaterial->Shininess = 0.4f;
    dmPapersMaterial->Roughness = 0.5f;

    _models.emplace_back(dmPapers, dmPapersMaterial);
    dmPapers->Transform = glm::translate(dmPapers->Transform, glm::vec3(1.f, 0.f, 0.f));
}

//////////////////////////////////////
// MAGNETS ONLY USED ON MAIN DM         
// SCREEN BOARD DUE TO NOT BEING        
// ABLE TO GET THEM TO GENERATE     
// AT A SLANT TO MATCH SIDE BOARDS  
/////////////////////////////////////
void DmScreen::createMagnet() {

    auto [cylinderVertices, cylinderIndices] = Shapes::BuildSmoothCylinder(50, 1.2f, 0.3f);
    auto magnet = std::make_shared<Mesh>(cylinderVertices, cylinderIndices, glm::vec2{ 1.f, 1.f });

    auto magnetTexturePath = Path("dmscreen");

    auto magnetMaterial = std::make_shared<Material>(_basicLitShader);
    magnetMaterial->AddTexture(std::make_shared<Texture>(magnetTexturePath / "metal.jpg",
        Texture::SamplerSettings{
             .S = Texture::SamplerTileMode::MirroredRepeat,
             .T = Texture::SamplerTileMode::MirroredRepeat,
        }));
    magnetMaterial->Shininess = 0.8f;

    _models.emplace_back(magnet, magnetMaterial);

    magnet->Transform = glm::translate(magnet->Transform, glm::vec3(0.55f, 0.93f, 0.01f));
    magnet->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
    magnet->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
    //magnet->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(0.f, 0.f, 2.f));
    magnet->Transform = glm::scale(magnet->Transform, glm::vec3(0.02f, 0.02f, .08f));

}

void DmScreen::createMagnet1() {

    auto [cylinderVertices, cylinderIndices] = Shapes::BuildSmoothCylinder(50, 1.2f, 0.3f);
    auto magnet = std::make_shared<Mesh>(cylinderVertices, cylinderIndices, glm::vec2{ 1.f, 1.f });

    auto magnetTexturePath = Path("dmscreen");

    auto magnetMaterial = std::make_shared<Material>(_basicLitShader);
    magnetMaterial->AddTexture(std::make_shared<Texture>(magnetTexturePath / "metal.jpg",
        Texture::SamplerSettings{
             .S = Texture::SamplerTileMode::MirroredRepeat,
             .T = Texture::SamplerTileMode::MirroredRepeat,
        }));
    magnetMaterial->Shininess = 0.8f;

    _models.emplace_back(magnet, magnetMaterial);

    magnet->Transform = glm::translate(magnet->Transform, glm::vec3(-0.45f, 0.93f, 0.01f));
    magnet->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
    magnet->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
    //cup->Transform = glm::rotate(magnet->Transform, glm::radians(90.f), glm::vec3(0.f, 0.f, 2.f));
    magnet->Transform = glm::scale(magnet->Transform, glm::vec3(0.02f, 0.02f, .08f));

}


