#pragma once
#include "DxLib.h"
#include <memory>

#include "../GameMain/CameraManager.h"

class Render
{

	std::shared_ptr<Camera2D> camera;

public:
	
	Render(std::shared_ptr<Camera2D> arg_camera):camera(arg_camera){}

	// 左上基準
    void DrawSprite(int arg_x, int arg_y, int arg_graph)
    {
        int w, h;
        GetGraphSize(arg_graph, &w, &h);

        int sx = (int)((arg_x - camera->GetX()) * camera->GetZoom());
        int sy = (int)((arg_y - camera->GetY()) * camera->GetZoom());
        int ex = sx + (int)(w * camera->GetZoom());
        int ey = sy + (int)(h * camera->GetZoom());

        DrawExtendGraph(sx, sy, ex, ey, arg_graph, TRUE);
    }

    // ===== 画像（中心基準） =====
    void DrawSpriteCenter(int arg_x, int arg_y, int arg_graph)
    {
        int w, h;
        GetGraphSize(arg_graph, &w, &h);

        int left = arg_x - w / 2;
        int top = arg_y - h / 2;

        DrawSprite(left, top, arg_graph);
    }

    // ===== 四角形描画（デバッグ用） =====
    void DrawBox(int arg_x, int arg_y, int arg_w, int arg_h, unsigned int arg_color, bool arg_fill = false)
    {
        int sx1 = (int)((arg_x - camera->GetX()) * camera->GetZoom());
        int sy1 = (int)((arg_y - camera->GetY()) * camera->GetZoom());
        int sx2 = sx1 + (int)(arg_w * camera->GetZoom());
        int sy2 = sy1 + (int)(arg_h * camera->GetZoom());

        DrawBox(sx1, sy1, sx2, sy2, arg_color, arg_fill);
    }

    // ===== テキスト描画（カメラに影響しない UI 用） =====
    void DrawUI(int arg_x, int arg_y, const char* arg_text, unsigned int arg_color)
    {
        DrawString(arg_x, arg_y, arg_text, arg_color);
    }
};