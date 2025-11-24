#pragma once
#include "DxLib.h"
#include <cmath>

class Camera2D
{

	//座標
	float m_camX = 0.0f;
	float m_camY = 0.0f;

	// 倍率
	float m_zoom = 1.0f;
    const float ZOOM_SPEED = 0.1f;

	// 追従値
	bool m_follow = false;
	float m_targetX = 0;
	float m_targetY = 0;
	float m_lerp = 0.1f;


	// シェイク値
	float m_shakePower = 0.0f;
	int m_shakeTime = 0;

public:

    // ===== コンストラクタ =====
    Camera2D() {}

    void Move(float arg_dx, float arg_dy) {
        m_camX += arg_dx;
        m_camY += arg_dy;
    }

    void UpZoom(float arg_dz) {
        m_zoom += ZOOM_SPEED;
        if (m_zoom >= arg_dz)
        {
            m_zoom = arg_dz;
        }
    }
    void SetZoom(float arg_z) {
        m_zoom = arg_z;
    }

    float GetZoom() const { return m_zoom; }

    // ===== 位置設定 =====
    void SetPos(float arg_x, float arg_y) {
        m_camX = arg_x;
        m_camY = arg_y;
    }

    float GetX() const { return m_camX; }
    float GetY() const { return m_camY; }

    void Follow(float arg_targetX, float arg_targetY, float arg_lerp = 0.1f) {
        m_follow = true;
        m_targetX = arg_targetX;
        m_targetY = arg_targetY;
        m_lerp = arg_lerp;
    }

    void StopFollow() {
        m_follow = false;
    }

    void Shake(float arg_power, int arg_time) {
        m_shakePower = arg_power;
        m_shakeTime = arg_time;
    }

    void Update() {

        // 追従処理
        if (m_follow) {
            m_camX += (m_targetX - m_camX) * m_lerp;
            m_camY += (m_targetY - m_camY) * m_lerp;
        }

        // シェイク処理
        if (m_shakeTime > 0) {
            m_camX += (rand() % 1000 / 1000.0f - 0.5f) * m_shakePower;
            m_camY += (rand() % 1000 / 1000.0f - 0.5f) * m_shakePower;
            m_shakeTime--;
        }
    }

    // 画面座標変換
    void WorldToScreen(float worldX, float worldY, int& outX, int& outY) const {
        outX = (int)((worldX - m_camX) * m_zoom);
        outY = (int)((worldY - m_camY) * m_zoom);
    }

    // 描画
    void DrawSprite(int x, int y, int graphHandle) const {
        int w, h;
        GetGraphSize(graphHandle, &w, &h);

        int sx = (int)((x - m_camX) * m_zoom);
        int sy = (int)((y - m_camY) * m_zoom);

        int ex = sx + (int)(w * m_zoom);
        int ey = sy + (int)(h * m_zoom);

        DrawExtendGraph(sx, sy, ex, ey, graphHandle, TRUE);
    }
};