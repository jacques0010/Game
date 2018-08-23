#include "Engine/Graphics/Window.h"
#include <iostream>
#include "Engine/ErrorHandler/ErrorHandlers.h"
#include "Engine/FileManager/FileLoader.h"
#include "Engine/Graphics/Buffers/IndexBuffer.h"
#include "Engine/Graphics/Buffers/VertexBuffer.h"
#include "Engine/Graphics/BasicShader.h"

#include "Engine/Math/Matrix4f.h"


using namespace Engine;

int main() {

	unsigned int index[6] = {
		0, 1, 2, 
		2, 3, 0

	};

	float positions[8] = 
	{
		 0.5f,  0.5f, 
		 0.5f, -0.5f,
		-0.5f, -0.5f,
		-0.5f,  0.5f

	};

	Math::Matrix4f projection = Math::Matrix4f::Ortho(16.0, -16.0, 9.0, -9.0, 1.0, 1.0);

//	Graphics::BasicShader shader("Shaders\basicFrag.glsl", "Shaders\basicVert.glsl");
	//shader.setUniformMat4("projection", projection);

	if (!glfwInit())
	{
		return -1;
	}
	Graphics::OGLWindow window = Graphics::OGLWindow(1280, 800, "Window");
	if (!window.init()) std::cin.get();

	Graphics::IndexBuffer indexBuffer(6, index);
	Graphics::VertexBuffer vertexBuffer(8, positions);
	vertexBuffer.bind();
	unsigned int vao;
	GLCall(glCreateVertexArrays(1, &vao));
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));



	while (!glfwWindowShouldClose(window.getWindow()))
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		vertexBuffer.bind();
		indexBuffer.bind();
		//shader.bind();
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
		glfwSwapBuffers(window.getWindow());

		glfwPollEvents();
	}

	glfwTerminate();
}
