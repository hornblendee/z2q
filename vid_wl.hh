#pragma once

#include <stdexcept>
#include <string>
#include <wayland-client.h>

#include "vid.hh"
#include "gl.hh"

class vid_wl: public vid {
	public:
	static std::unique_ptr<vid> make(void);

	vid_wl(void);
	~vid_wl(void);

	gl get_gl(void);

	class connect_error;

	private:
	wl_display *disp;
};

class vid_wl::connect_error: public std::runtime_error {
	public:
	connect_error(void);
	connect_error(const std::string &) = delete;
};
