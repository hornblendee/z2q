#include <memory>
#include <stdexcept>
#include <wayland-client.h>

#include "vid"
#include "vid_wl.hh"
#include "gl.hh"

std::unique_ptr<vid> vid_wl::make(void) {
	return std::make_unique<vid_wl>();
}

vid_wl::vid_wl(void) {
	disp = wl_display_connect(NULL);
	if (disp == NULL) {
		throw vid_wl::connect_error();
	}
}
vid_wl::~vid_wl(void) {
	wl_display_disconnect(disp);
}
gl vid_wl::get_gl(void) {
	return gl {};
}

vid_wl::connect_error::connect_error(void):
	std::runtime_error("could not connect to Wayland display") {}
