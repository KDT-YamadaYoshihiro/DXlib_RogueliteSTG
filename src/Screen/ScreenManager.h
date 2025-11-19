#pragma once
#include <vector>
#include <memory>
#include "ScreenBase.h"


class ScreenManager {

	// スクリーンポインター
	std::unique_ptr<ScreenBase> currentScreen = nullptr;


	ScreenManager() = default;
	virtual ~ScreenManager() = default;


public:

	// シングルトン　コピー、代入禁止
	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator = (const ScreenManager&) = delete;
	static ScreenManager& Instance() {
		static ScreenManager instance;
		return instance;
	}


	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
	// 終了
	void End();


	template<typename T>
	void ChengeScreen();

	// ゲット関数


};

// テンプレート関数の実装
template<typename T>
inline void ScreenManager::ChengeScreen()
{
	currentScreen = std::make_unique<T>();
}
