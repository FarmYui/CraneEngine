#pragma once

#include "Crane/Renderer/Texture.h"

#include <glad/glad.h>

namespace Crane
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height, uint32_t channels);
		OpenGLTexture2D(const std::string& path);

		~OpenGLTexture2D();

		virtual uint32_t GetRendererID() const override { return m_RendererID; }

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }

		virtual const std::string& GetPath() const override { return m_Path; }
		virtual void SetPath(const std::string& path) override { m_Path = path; };

		virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind(uint32_t slot = 0) const override;

	private:
		uint32_t m_RendererID;

		std::string m_Path = "";
		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_NrChannels;
		GLenum m_InternalFormat, m_DataFormat;
	};
}