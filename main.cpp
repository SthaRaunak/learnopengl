#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "VAO.hpp"
#include "shaders.hpp"

// Vertices coordinates

// GLfloat vertices[] = {
//     -0.5f,
//     -0.5f,
//     0.0f,             // left
//     1.0f, 0.0f, 0.0f, // red
//     0.5f,
//     -0.5f,
//     0.0f,             // right
//     0.0f, 1.0f, 0.0f, // green
//     0.0f,
//     0.5f,
//     0.0f,            // top
//     0.0f, 0.0f, 1.0f // blue
// };
GLfloat vertices[] = {
    -0.5f,
    -0.5f,
    0.0f, // left
    0.5f,
    -0.5f,
    0.0f, // right
    0.0f,
    0.5f,
    0.0f, // top
};
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(800, 600, "Open GL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 800, 600);

    Shader shaderProgram("ResourceFiles/Shaders/default.vert", "ResourceFiles/Shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    // Generates Vetrx BUffer Object and links it to veritices
    VBO VBO1(vertices, sizeof(vertices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);

    // Unbind all to prevent accidentally modifying them
    VBO1.Unbind();
    VAO1.Unbind();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.612f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();
        VAO1.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
