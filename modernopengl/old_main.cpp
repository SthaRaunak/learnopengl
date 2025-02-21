// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>

// void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// void processInput(GLFWwindow *window);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "layout (location = 1) in vec3 aColor;\n"
//                                  "out vec3 ourColor;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos,1.0);\n"
//                                  "   ourColor = aColor;\n"
//                                  "}\0";

// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "in vec3 ourColor;\n"
//                                    //    "uniform vec4 ourColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(ourColor,1.0f);\n"
//                                    "}\n\0";

// int main()
// {
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Raunak Shrestha", NULL, NULL);

//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);

//     // load all opengl function pointers
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // build and compiler our shader program

//     GLuint vertexShader;
//     vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);

//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

//     if (!success)
//     {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
//                   << infoLog << std::endl;
//     }

//     unsigned int fragmentShader;
//     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

//     if (!success)
//     {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
//                   << infoLog << std::endl;
//     }

//     // link the shaders

//     unsigned int shaderProgram;
//     shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);

//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success)
//     {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
//                   << infoLog << std::endl;
//     }

//     // delete the shader objects after linking them
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     // setup vertext data and buffers and configure vertex attributes

//     GLfloat vertices[] = {
//         -0.5f,
//         -0.5f,
//         0.0f,             // left
//         1.0f, 0.0f, 0.0f, // red
//         0.5f,
//         -0.5f,
//         0.0f,             // right
//         0.0f, 1.0f, 0.0f, // green
//         0.0f,
//         0.5f,
//         0.0f,            // top
//         0.0f, 0.0f, 1.0f // blue
//     };

//     // GLfloat rectanglevertices[] = {
//     //     0.5f,
//     //     0.5f,
//     //     0.0f,
//     //     -0.5f,
//     //     0.5f,
//     //     -0.5f,
//     //     0.5f,
//     //     0.0f,
//     //     -0.5f, -0.5f, 0.0f};

//     //unsigned int indices[] = {0, 1, 2, 1, 2, 3};

//     unsigned int VBO,
//         VAO;

//     glGenVertexArrays(1, &VAO); // make sure generate VAO before the VBO
//     glGenBuffers(1, &VBO);
//     // glGenBuffers(1, &EBO);
//     // bind the vertex array object first
//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     // glBufferData(GL_ARRAY_BUFFER, sizeof(rectanglevertices), rectanglevertices, GL_STATIC_DRAW);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

//     //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//     //  then set the vertex attributes pointers
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
//     glEnableVertexAttribArray(0); // location of Verterx attribute pointer

//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3* sizeof(float)));
//     glEnableVertexAttribArray(1); // location of Verterx attribute pointer

//     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // do not unbind while VAO is active

//     // unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO
//     glBindVertexArray(0);

//     // render loop
//     while (!glfwWindowShouldClose(window))

//     {
//         // input
//         processInput(window);

//         // rendering commands
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // draw the triangle
//         glUseProgram(shaderProgram);

//         // setting that uniform variable that we set in fragment shader this will be calculated each frame giving random green value changing it with time
//         //float timeValue = glfwGetTime();
//         //float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//         //int vertextColorLocation = glGetUniformLocation(shaderProgram, "ourColor"); // finding uniform doesnt require usage of shader program but setting does
//         //glUniform4f(vertextColorLocation, 0.0, greenValue, 0.0, 1.0);               // sets the unform on currently active shaderProgram

//         glBindVertexArray(VAO);

//         // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         // check and call events and swap the buffers
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     // deallocating resources
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteProgram(shaderProgram);

//     glfwTerminate();
//     return 0;
// }

// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }

// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//     {
//         glfwSetWindowShouldClose(window, true);
//     }
// };
