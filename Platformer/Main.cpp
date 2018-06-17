#include "glfw3.h"

int main() {
	GLFWwindow* window;
	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(800, 600, "title", NULL, NULL);

	if (window == nullptr) 
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
