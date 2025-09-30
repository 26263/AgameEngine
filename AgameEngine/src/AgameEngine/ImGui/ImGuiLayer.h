#pragma once

#include "AgameEngine/Layer.h"
#include "AgameEngine/Event/ApplicationEvent.h"
#include "AgameEngine/Event/MouseEvent.h"
#include "AgameEngine/Event/KeyEvent.h"

namespace AgameEngine
{
	class AGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach();
		void OnDetach();	
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressed& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleased& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);

	private: 
		float m_Time = 0.0f;
	};
}