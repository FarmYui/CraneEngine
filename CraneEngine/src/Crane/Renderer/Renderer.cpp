#include "crpch.h"
#include "Renderer.h"

#include "Platforms/OpenGL/OpenGLShader.h"

namespace Crane
{
	Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData();

	void Renderer::Init()
	{
		RenderCommand::Init();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjMatrix = camera.GetViewProjMatrix();
	}

	void Renderer::Submit(const Ref<VertexArray>& VertexArray, const Ref<Shader>& shader, const glm::mat4& transform = glm::mat4(1.0f))
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniformMat4("u_ViewProjection", s_SceneData->ViewProjMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniformMat4("u_Model", transform);

		VertexArray->Bind();
		RenderCommand::DrawIndexed(VertexArray);
	}
}