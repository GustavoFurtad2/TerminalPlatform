#pragma once

#ifndef GRAPHICS_HPP

#define GRAPHICS_HPP

#include "Render.hpp"
#include <string>

namespace Graphics {

	void drawRect(Render* renderer, wchar_t c, int x, int y, int width, int height);
	void drawText(Render* renderer, wchar_t *c, int x, int y);

}

#endif