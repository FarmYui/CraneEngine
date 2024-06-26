#pragma once

#include "Crane/Renderer/Camera.h"
#include "Crane/Renderer/OrthographicCamera.h"
#include "Crane/Renderer/EditorCamera.h"

#include "Crane/Renderer/Texture.h"
#include "Crane/Renderer/TextureRegion2D.h"

#include "Crane/Scene/Components.h"

namespace Crane
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void BeginScene(const EditorCamera& camera);
		static void BeginScene(const OrthographicCamera& camera);

		static void EndScene();
		static void Flush();

		// ////////////////////
		// primitives
		// ////////////////////


		/* without rotation */
		//-- colored 
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color); 
		//-- textured
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec4& color = { 1.0f,1.0f,1.0f,1.0f});
		//-- subregion
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const Ref<TextureRegion2D>& textureRegion, const glm::vec4& color = { 1.0f,1.0f,1.0f,1.0f});
		
		/* with rotation */
		//-- colored 
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color); 
		//-- textured
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const glm::vec4& color = { 1.0f, 1.0f,1.0f,1.0f });
		//-- subregion
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const Ref<TextureRegion2D>& textureRegion, const glm::vec4& color = { 1.0f, 1.0f,1.0f,1.0f });


		// make changes only in these methods
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color, int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, const glm::vec4& color = { 1.0f, 1.0f,1.0f,1.0f }, int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, const Ref<TextureRegion2D>& textureRegion, const glm::vec4& color = { 1.0f, 1.0f,1.0f,1.0f }, int entityID = -1);

		static void DrawSprite(const glm::mat4& transform, SpriteRendererComponent& spriteRendererComponent, int entityID);

		// Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() const { return QuadCount * 4; };
			uint32_t GetTotalIndexCount() const { return QuadCount * 6; };

			
		};
		static void ResetStats();
		static Statistics GetStats();
	private:
		static void StartNewBatch();
	};
}