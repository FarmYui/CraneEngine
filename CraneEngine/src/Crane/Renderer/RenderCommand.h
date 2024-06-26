#pragma once

#include "RendererAPI.h"

#include <glm/glm.hpp>

namespace Crane
{
	class RenderCommand
	{
	public:
		inline static void Init()
		{
			s_RendererAPI->Init();
		}

		inline static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}

		inline static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color.r, color.g, color.b, color.a);
		}

		inline static void SetClearColor(float r, float g, float b, float a)
		{
			s_RendererAPI->SetClearColor(r, g, b, a);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed(const Ref<VertexArray>& VertexArray, uint32_t indexCount = 0)
		{
			s_RendererAPI->DrawIndexed(VertexArray, indexCount);
		}

	private:
		static Scope<RendererAPI> s_RendererAPI;
	};
}