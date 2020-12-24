#include <memory>

#include "vid.hh"
#include "vid_dummy.hh"
#include "vid_wl.hh"
//#include "vid_x.hh"
#include "gl.hh"

std::unique_ptr<vid> vid::make(void) {
	bool usedummy = false;

	try {
		return vid_wl::make();
	} catch (const vid_wl::connect_error &_) {}
	//try {
	//	return vid_x::make();
	//} catch (const vid_x::…_error &_) {}
	if (usedummy)
	try {
		return vid_dummy::make();
	}

	throw vid::setup_error();
}

vid::setup_error::setup_error(void):
	std::runtime_error("could not set up video") {}
