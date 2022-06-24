#ifndef _PROGJOGOS_GRAPHICS_H_
#define -PROGJOGOS_GRAPHICS_H_

#include <dxgi.h>		// Infraestrutura gráfica do DirectX
#include <d3d11.h>		// Principais funções do Direct3D
#include "Window.h"
#include "Types.h"

class Graphics {
	private:
		IDXGISwapChain* swapChain;						// SwapChain
		ID3D11RenderTargetView* renderTargetView;		// Render Target View do BackBuffer
		ID3D11BlendState* blendState;					// Configuração de mistura de cores
		D3D_FEATURE_LEVEL	featureLevel;				// Nível de recursos D3D suportados pelo hardware
		float		bgColor[4];							// Cor de fundo do BackBuffer
		float		vSync;								// Vertical Sync

	public:
		Graphics();
		~Graphics();

		static ID3D11Device* device;					// Dispositivo gráfico
		static ID3D11DeviceContext* context;			// Contexto do dispositivo gráfico
		static D3D11_VIEWPORT * viewport;				// Viewport do dispositivo

		void VSync(bool state);							// Liga/desliga vertical Sync
		void Clear();									// Limpa o backbuffer com a cor de fundo
		void Present();									// Apresenta o desenho na tela
		bool Initialize(Window* window);				// Inicializa o Direct3D
};
// Métodos inline

inline void Graphics::VSync(bool state) {
	VSync = state;
}

inline void Graphics::Clear() {
	context->ClearRenderTargetView(renderTargetView, bgColor);
}

inline void Graphics::Present() {
	swapChain->Present(VSync, NULL);
	context->OMSetRenderTargets(1, &renderTargetView, nullptr);
}
#endif // !_PROGJOGOS_GRAPHICS_H_
