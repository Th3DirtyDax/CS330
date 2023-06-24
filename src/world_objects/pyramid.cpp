

#include <core/shapes.h>
#include <world_objects/pyramid.h>

Pyramid::Pyramid() {
	createShaders();
	createPyramid();
}

void Pyramid::Init() {

}

void Pyramid::Update(float deltaTime) {

}

void Pyramid::createShaders() {
	_basicLitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Pyramid::createPyramid() {
    auto pyramidBrick = std::make_shared<Mesh>(Shapes::pyramidVertices, Shapes::pyramidElements, glm::vec3(1.f, 1.f, 1.f));

    auto brickTexturePath = Path("extras");
    auto brickTexture = std::make_shared<Texture>(brickTexturePath / "brick.jpg");

    auto brickMaterial = std::make_shared<Material>(_basicLitShader);
    brickMaterial->AddTexture(brickTexture);
    brickMaterial->Shininess = 0.1f;
    brickMaterial->Roughness = 0.5f;

    _models.emplace_back(pyramidBrick, brickMaterial);
}
