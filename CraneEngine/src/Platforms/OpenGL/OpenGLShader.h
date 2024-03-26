#pragma once

#include "Crane/Renderer/Shader.h"

namespace Crane
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string & vertexSource, const std::string & fragmentSource);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Un�bind() const override;

		void SetUniformInt(const std::string& name, int value);

		void SetUniformFloat(const std::string& name, float value);
		void SetUniformFloat2(const std::string& name, const glm::vec2& value);
		void SetUniformFloat3(const std::string& name, const glm::vec3& value);
		void SetUniformFloat4(const std::string& name, const glm::vec4& value);

		void SetUniformMat3(const std::string& name, const glm::mat3& matrix);
		void SetUniformMat4(const std::string& name, const glm::mat4& matrix);

	private:
		uint32_t m_RendererID;
	};
}