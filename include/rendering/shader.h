/* Ryan P. Gingery
* CS-330  Comp Graphic and Visualization 23EW5
* Course Project
* Professor Philip Enkema
*/

#pragma once

#include <filesystem>
#include <string>
#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <rendering/textures.h>

using Path = std::filesystem::path;

class Shader {
public:
    static inline Path ShaderPath = std::filesystem::current_path() / "assets" / "shaders";

    Shader() = default;
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    Shader(const Path& vertexPath, const Path& fragmentPath);

    void Bind() const;

    void SetVec3(const std::string& uniformName, const glm::vec3& vec3) const;
    void SetMat4(const std::string& uniformName, const glm::mat4& mat4) const;
    void SetInt(const std::string& uniformName, int value) const;
    void SetFloat(const std::string& uniformName, float value) const;

    void AddTexture(const std::shared_ptr<Texture>& texture);
private:
    void load(const std::string& vertexSource, const std::string& fragmentSource);
   GLint getUniformLocation(const std::string& uniformName) const;

private:
    GLuint _shaderProgram {};

    std::vector<std::shared_ptr<Texture>> _textures;
};