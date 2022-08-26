#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

void framebuffer(GLFWwindow *window ,int W,int H) {
	glViewport(0, 0, W, H);
}

void Input(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window,true);
	}
}

int main(int, char**) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "glfw-demo", NULL, NULL);
    if (window == NULL) { std::cout << "Init glfw window failed!" << std::endl; return -1; }

    glfwMakeContextCurrent(window);

    if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0) { std::cout << "Init glad failed!" << std::endl; return -1; }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer);

    // render loop
    while (glfwWindowShouldClose(window) == 0) {
        Input(window);

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
		glfwSwapBuffers(window);

		glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
