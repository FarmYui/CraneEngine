#pragma once

#include <functional>

#include "Crane/Core/Core.h"


namespace Crane
{
	// rn the events are blocking the flow of the whole app
	
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyRelased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),// 1
		EventCategoryInput		 = BIT(1),// 2
		EventCategoryKeyboard	 = BIT(2),// 4
		EventCategoryMouse		 = BIT(3),// 8
		EventCategoryMouseButton = BIT(4) // 16

	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
							       virtual EventType GetEventType() const override { return GetStaticType(); }\
							       virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	public:
		bool Handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType()) 
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}