#include "crpch.h"

#include "Renderer.h"
#include "Platforms/OpenGL/OpenGLBuffer.h"

namespace Crane
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			CR_CORE_ASSERT(false, "RendererAPI::None not supported!");
			return nullptr;

		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexBuffer>(vertices, size);

		default:
			CR_CORE_ASSERT(false, "RendererAPI unknown!");
			return nullptr;
		}
	}


	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			CR_CORE_ASSERT(false, "RendererAPI::None not supported!");
			return nullptr;

		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLIndexBuffer>(indices, count);

		default:
			CR_CORE_ASSERT(false, "RendererAPI unknown!");
			return nullptr;
		}
	}
}