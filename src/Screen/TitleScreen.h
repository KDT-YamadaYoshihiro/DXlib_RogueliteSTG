#pragma once
#include "ScreenBase.h"

class TitleScreen : public ScreenBase {

public:

	TitleScreen() = default;
	virtual ~TitleScreen() = default;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void End() override;
};
