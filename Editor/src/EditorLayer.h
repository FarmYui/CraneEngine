#pragma once
#include "Crane.h"

namespace Crane
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		void OnAttach() override;
		void OnDetach() override;

		void OnEvent(Event& e) override;
		void OnUpdate(Timestep ts) override;
		void OnImGuiRender() override;

	private:
		glm::vec3 m_QuadPosition = { 0.0f, 0.0f, 0.0f };
		float m_QuadRotation = 0.0f;
		glm::vec3 m_QuadSize = { 1.0f, 0.2f, 1.0f };
		glm::vec3 m_QuadColor = { 1.0f, 0.8f, 0.0f };

		glm::vec4 m_ClearColor = { 0.1f, 0.1f, 0.1f, 1.0f };

		Timestep m_Timestep;
		OrthographicCameraController m_CameraController;
		Ref<Framebuffer> m_Framebuffer;
		Ref<Scene> m_ActiveScene;

		Entity m_CameraEntity;

		bool m_ViewportFocused = false, m_ViewportHovered = false;

		glm::vec2 m_ViewportSize;
	};
}