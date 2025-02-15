#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string get_file_contents(const char *filename);

class Shader
{
public:
    // the program ID
    GLuint ID;

    // constructor reads and builds the shader
    Shader(const char *vertexPath, const char *fragmentPath);

    // use/ activate the shader
    void Activate();
    void Delete();
    // // utility uniform functions
    // void setBool(const std::string &name, bool value) const;
    // void setInt(const std::string &name, int value) const;
    // void setFloat(const std::string &name, float value) const;
};
#endif
