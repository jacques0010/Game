#include "VertexBuffer.h"

namespace Engine {
	namespace Graphics {
		VertexBuffer::VertexBuffer(const unsigned int& count, float* data)
			:size(size)
		{
			GLCall(glGenBuffers(1, &VBufferID));
			bind();
			GLCall(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW));
			unbind();

		}
		VertexBuffer::~VertexBuffer()
		{
			GLCall(glDeleteBuffers(1, &VBufferID));
		}

		void VertexBuffer::bind()
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBufferID));
		}
		void VertexBuffer::unbind()
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		}
	}
}