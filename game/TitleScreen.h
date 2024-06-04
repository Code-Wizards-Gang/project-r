#ifndef LOGOSCREEN_H
#define LOGOSCREEN_H

#include "Screen.h"

class TitleScreen : public Screen {
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Unload() override;
	virtual bool IsFinished() const override;

private:
	bool finished;
};

#endif // LOGOSCREEN_H