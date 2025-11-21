#pragma once

class WindowSetting
{

	bool m_window_mode = true;
	// ウィンドウサイズ
	static const int m_WIDTH = 1920;
	static const int m_HEIGHT = 1080;

	WindowSetting() = default;
	virtual ~WindowSetting() = default;

public:

	// シングルトン　コピー、代入禁止
	WindowSetting(const WindowSetting&) = delete;
	WindowSetting& operator = (const WindowSetting&) = delete;
	static WindowSetting& Instance() {
		static WindowSetting instance;
		return instance;
	}

	// ウィンドウモードの取得
	bool GetWindowMode() const { return m_window_mode; }

	//　ウィンドウサイズの取得
	int GetWindowSizeW() { return m_WIDTH; }
	int GetWindowSizeH() { return m_HEIGHT; }


};