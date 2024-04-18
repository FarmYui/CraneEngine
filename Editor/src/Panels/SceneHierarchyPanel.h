#pragma once

#include "Crane/Core/Log.h"
#include "Crane/Scene/Scene.h"

#include "Crane/Scene/Entity.h"

namespace Crane
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& Scene);

		void SetScene(const Ref<Scene>& Scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

		template<typename T, typename F>
		void DrawComponent(const std::string& name, F func);
	private:
		Ref<Scene> m_Scene;
		Entity m_SelectedEntity;
	};
	
}