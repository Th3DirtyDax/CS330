#include <world_objects/table.h>
#include <rendering/types.h>
#include <glm/gtc/matrix_transform.hpp>
#include <core/shapes.h>

Table::Table() {
    createShaders();
    createModel();
    createPCSheet();
}

void Table::Init() {

}

void Table::Update(float deltaTime) {
    
}

void Table::createShaders() {
    _basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Table::createModel() {
    //const float tableScale = 0.f;
    
    auto table = std::make_shared<Mesh>(Shapes::tableVertices, Shapes::tableElements, glm::vec2(2.f, 2.f));
    auto tableTexturePath = Path("table");
    auto tableTexture = std::make_shared<Texture>(tableTexturePath / "bolivian.jpg");


    auto tableMaterial = std::make_shared<Material>(_basicLitShader);
    tableMaterial->AddTexture(tableTexture);
    tableMaterial->Shininess = 0.1f;

    _models.emplace_back(table, tableMaterial);

    /*table->Transform = glm::translate(table->Transform, glm::vec3(0.f, 0.f, 0.f));
    table->Transform = glm::rotate(table->Transform, glm::radians(-90.f), glm::vec3(1, 0, 0));
    table->Transform = glm::scale(table->Transform, glm::vec3(tableScale, tableScale, tableScale));*/

}

void Table::createPCSheet() {
    auto dmPapers = std::make_shared<Mesh>(Shapes::dmPaperVertices, Shapes::dmPaperElements, glm::vec2(1.f, 1.f));

    auto dmPapersTexturePath = Path("dmscreen");
    auto dmPapersTexture = std::make_shared<Texture>(dmPapersTexturePath / "player_sheet.jpg");

    auto dmPapersMaterial = std::make_shared <Material>(_basicLitShader);
    dmPapersMaterial->AddTexture(dmPapersTexture);
    dmPapersMaterial->Shininess = 0.4f;
    dmPapersMaterial->Roughness = 0.5f;

    _models.emplace_back(dmPapers, dmPapersMaterial);
    dmPapers->Transform = glm::translate(dmPapers->Transform, glm::vec3(0.2f, 0.01f, 1.7f));
    dmPapers->Transform = glm::rotate(dmPapers->Transform, glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f));
    //dmPapers->Transform = glm::rotate(dmPapers->Transform, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));

}