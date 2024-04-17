#pragma once

#include "Crane/Renderer/Camera.h"

namespace Crane
{
	class SceneCamera : public Camera
	{
	public:
		SceneCamera() = default;
		virtual ~SceneCamera() = default;

		void SetOrthographic(float size, float nearClip, float farClip);
		void SetViewportSize(uint32_t width, uint32_t height);

		float GetOrthographicSize() const { return m_OrthographicSize; }
		void SetOrthographicSize(float size) { m_OrthographicSize = size; CalculateProjection();	 }
	private:
		void CalculateProjection();
	private:
		float m_OrthographicSize = 10.0f;
		float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;

		float m_AspectRatio = 0.0f;
	};
}