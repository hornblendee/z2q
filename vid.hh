#pragma once

#include <memory>

#include "gl.hh"

class vid {
	public:
	virtual gl get_gl(void) = 0;

	static std::unique_ptr<vid> make(void);
};
