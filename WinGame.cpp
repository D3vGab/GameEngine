#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	HDC		hdc;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init()
{
	hdc = GetDC(window->Id());
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

	MoveToEx(hdc, 10, 10, NULL);
}

// ------------------------------------------------------------------------------

void WinGame::Draw()
{
	LineTo(hdc, 100, 100);
}

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------
