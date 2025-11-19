#pragma once
#include "ScreenBase.h"


class IngameScreen : public ScreenBase {

public:
	IngameScreen() = default;
	virtual ~IngameScreen() = default;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void End() override;
};