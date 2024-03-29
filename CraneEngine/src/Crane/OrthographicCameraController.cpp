#include "crpch.h"
#include "OrthographicCameraController.h"

#include "Crane/Core.h"
#include "Crane/Input.h"
#include "Crane/KeyCodes.h"
#include "Crane/MouseButtonCodes.h"

namespace Crane
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(CR_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
		dispatcher.Dispatch<MouseScrolledEvent>(CR_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		if (Input::IsKeyPressed(CR_KEY_W))
		{
			m_CameraPosition.y += sin(glm::radians(m_CameraRotation + 90)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.x += cos(glm::radians(m_CameraRotation + 90)) * m_CameraTranslationSpeed * ts;
		}
		if (Input::IsKeyPressed(CR_KEY_S))
		{
			m_CameraPosition.y -= sin(glm::radians(m_CameraRotation + 90)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.x -= cos(glm::radians(m_CameraRotation + 90)) * m_CameraTranslationSpeed * ts;
		}
		if (Input::IsKeyPressed(CR_KEY_A))
		{
			m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}
		if (Input::IsKeyPressed(CR_KEY_D))
		{
			m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}

		if (m_Rotation)
		{
			if (Input::IsMouseButtonPressed(CR_MOUSE_BUTTON_3))
			{
				float currentMouseX = Input::GetMouseX();
				m_CameraRotation += (m_PrevMouseX) ? ((currentMouseX - m_PrevMouseX) * m_CameraRotationSpeed) : 0;
				m_PrevMouseX = currentMouseX;
			}
			else
			{
				m_PrevMouseX = 0;
			}
			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel * 2.0f;
		
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	
}