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

		if (!playing)
		{
			return;
		}

		timer += delta;
		currentFrame++;

		if (currentFrame >= frameCount)
		{
			if (loop)
			{
				currentFrame = 0;
			}
			else
			{
				currentFrame = frameCount - 1;
				playing = false;

			}// if(loop)

		} // if (currentFrame >= frameCount)


	}


};