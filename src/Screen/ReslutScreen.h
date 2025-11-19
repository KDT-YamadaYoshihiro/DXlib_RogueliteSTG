#pragma once
#include "ScreenBase.h"

class ReslutScreen : public ScreenBase {

public:
	ReslutScreen() = default;
	virtual ~ReslutScreen() = default;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void End() override;
};