#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "gl.hh"

class vid {
	public:
	static std::unique_ptr<vid> make(void);

	virtual gl get_gl(void) = 0;

	class setup_error;
};

class vid::setup_error: public std::runtime_error {
	public:
	setup_error(void);
	setup_error(const std::string &) = delete;
};
