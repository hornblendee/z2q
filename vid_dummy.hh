#pragma once

#include "vid.hh"
#include "gl.hh"

class vid_dummy: public vid {
	public:
	gl get_gl(void);
};
