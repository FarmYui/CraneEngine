#pragma once

#include "Crane/Renderer/Shader.h"

typedef unsigned int GLenum;

namespace Crane
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string & filepath);
		OpenGLShader(const std::string& name, const std::string & vertexSource, const std::string & fragmentSource);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const std::string& GetName() const override { return m_Name; }

		void SetUniformInt(const std::string& name, int value);

		void SetUniformFloat(const std::string& name, float value);
		void SetUniformFloat2(const std::string& name, const glm::vec2& value);
		void SetUniformFloat3(const std::string& name, const glm::vec3& value);
		void SetUniformFloat4(const std::string& name, const glm::vec4& value);

		void SetUniformMat3(const std::string& name, const glm::mat3& matrix);
		void SetUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
	private:
		uint32_t m_RendererID = 0;
		std::string m_Name;
	};
}