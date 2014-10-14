#include "common/scummsys.h"

#if defined(SDL_BACKEND)

#include "resvm-sdl-events.h"

bool ResVmSdlEventSource::handleJoyButtonDown(SDL_Event &ev, Common::Event &event) {
	event.type = Common::EVENT_JOYBUTTON_DOWN;
	event.joystick.button = ev.jbutton.button;
	return true;
}

bool ResVmSdlEventSource::handleJoyButtonUp(SDL_Event &ev, Common::Event &event) {
	event.type = Common::EVENT_JOYBUTTON_UP;
	event.joystick.button = ev.jbutton.button;
	return true;
}

bool ResVmSdlEventSource::handleJoyAxisMotion(SDL_Event &ev, Common::Event &event) {
	event.type = Common::EVENT_JOYAXIS_MOTION;
	event.joystick.axis = ev.jaxis.axis;
	event.joystick.position = ev.jaxis.value;
	return true;
}

bool ResVmSdlEventSource::handleJoyHatMotion(SDL_Event &ev, Common::Event &event) {
	event.type = Common::EVENT_JOYHAT_MOTION;
	event.joystick.hat = ev.jhat.hat;
	event.joystick.hat_value = 0;
	if (ev.jhat.value & SDL_HAT_UP) {
		event.joystick.hat_value |= Common::JOYHAT_UP;
	}
	if (ev.jhat.value & SDL_HAT_DOWN) {
		event.joystick.hat_value |= Common::JOYHAT_DOWN;
	}
	if (ev.jhat.value & SDL_HAT_LEFT) {
		event.joystick.hat_value |= Common::JOYHAT_LEFT;
	}
	if (ev.jhat.value & SDL_HAT_RIGHT) {
		event.joystick.hat_value |= Common::JOYHAT_RIGHT;
	}
	return true;
}

#endif
