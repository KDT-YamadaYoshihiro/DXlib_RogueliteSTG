#include "../src/GameMain/GameMain.h"

bool GameMain::Init()
{

	//InputKeyInit();
	//InputPadInit();

	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(WindowSetting::Instance().GetWindowMode());
	SetGraphMode(WindowSetting::Instance().GetWindowSizeW(), WindowSetting::Instance().GetWindowSizeH(), 32);

	if (WindowSetting::Instance().GetWindowMode() == TRUE)
	{
		SetWindowSize(WindowSetting::Instance().GetWindowSizeW(), WindowSetting::Instance().GetWindowSizeH());
	}

	SetBackgroundColor(0, 0, 0);

	SetMainWindowText("RogueliteSTG");

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenManager::Instance().Init();

}

void GameMain::Run()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//	リフレッシュレートを設定するための処理
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;
		SetMouseDispFlag(TRUE);

		clsDx();
		ClearDrawScreen();
		//InputKeyUpdate();
		//InputPadUpdate();

		this->Update();
		this->Render();

		//	リフレッシュレートが一定になるまで待つ処理
		while (clock() < check_fps) {}

		ScreenFlip();
	}

}

void GameMain::Update()
{
	ScreenManager::Instance().Update();
}

void GameMain::Render()
{
	ScreenManager::Instance().Render();
}

void GameMain::End()
{
	//InputKeyExit();
	//InputPadExit();
	DxLib_End();

}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	GameMain::Instance().Init();
	GameMain::Instance().Run();
	GameMain::Instance().End();

	return 0;
}