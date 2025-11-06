#include "arcpch.h"
#include "LayerStack.h"

namespace ARC
{
	LayerStack::LayerStack()
	{

	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)	// popping a layer doesn't destroy it! only destroying the layer stack
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			// here we don't touch m_layerinsert because we only use it as an "index" of where the next layer should go
			// Since we're popping overlays, and overlays should alwayd be higher 
			//		(at the bottom of the vector wrt layers) than layers, it's unaffected
		}
	}
}