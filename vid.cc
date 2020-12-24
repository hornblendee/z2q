#include <memory>

#include "vid.hh"
#include "vid_dummy.hh"
#include "gl.hh"

std::unique_ptr<vid> vid::make(void) {
	return std::make_unique<vid_dummy>();
}
