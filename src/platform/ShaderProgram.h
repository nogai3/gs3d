#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

class ShaderProgram {
public:
    GLuint ID;

    ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
    void checkCompileErrors(GLuint shader, const std::string& type);
};

#endif