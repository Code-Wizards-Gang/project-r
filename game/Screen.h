#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
	virtual ~Screen() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;
	virtual bool IsFinished() const = 0;
};


#endif // SCREEN_H