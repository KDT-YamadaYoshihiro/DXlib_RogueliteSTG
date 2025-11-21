#pragma once
#include <cmath>

class Camera2D
{

	//座標
	float m_camX = 0.0f;
	float m_camY = 0.0f;

	// 倍率
	float m_zoom = 1.0f;

	// 追従値
	bool m_follow = false;
	float m_targetX = 0;
	float m_targetY = 0;
	float m_lerp = 0.1f;


	// シェイク値
	float m_shakePower = 0.0f;
	int m_shakeTime = 0;

public:

	// 追尾

	// アップ

	// クローズ

	// シェイク

};