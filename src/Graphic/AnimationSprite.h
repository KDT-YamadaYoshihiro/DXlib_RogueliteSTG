#pragma once
#include "DxLib.h"
#include "Render.h"

class AnimationSprite
{
	int image;
	int frameWidth;
	int frameHeight;
	int frameCount;
	float frameTime;
	float timer = 0.0f;
	int currentFrame = 0;

	bool loop = true;
	bool playing = true;

public:

	AnimationSprite(int arg_image, int arg_frameW, int arg_frameH, int arg_frames, float fps = 8.0f, bool loopflag = true)
		:image(arg_image),
		frameWidth(arg_frameW),
		frameHeight(arg_frameH),
		frameCount(arg_frames),
		loop(loopflag)
	{
		frameTime = 1.0f / fps;
	}

	// アニメ更新
	void Update(float delta)
	{
		// 
		if (!playing)
		{
			return;
		}

		// 
		timer += delta;
		// 
		int advanse = (int)(timer / frameTime);
		if (advanse == 0)
		{
			return;
		}

		// 
		timer -= advanse * frameTime;
		currentFrame += advanse;

		if (loop)		// ループあり
		{
			if (currentFrame >= frameCount) {
				currentFrame %= frameCount;
			}
		}
		else {			// ループなし
			if (currentFrame >= frameCount)
			{
				currentFrame = frameCount - 1;
				playing = false;
			}
		}

	}


};