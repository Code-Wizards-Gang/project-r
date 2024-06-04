#include "TitleScreen.h"

void TitleScreen::Init() {
	finished = false;
}

void TitleScreen::Update() {
	if (IsFinished() /*Or some other condition*/) {
		finished = true;
	}
}

void TitleScreen::Draw() {
	// Draw the title screen
}

void TitleScreen::Unload() {
	// Unload the title screen
}

bool TitleScreen::IsFinished() const {
	return finished;
}