#pragma once

#ifndef RENDERER2D_HPP

#define RENDERER2D_HPP

#include "Render.hpp"
#include <string>
#include <cmath>

namespace Renderer2D {

	void drawRect(Render* renderer, wchar_t c, int x, int y, int width, int height);
	void drawText(Render* renderer, wchar_t *c, int x, int y);
	void drawLine(Render* renderer, wchar_t c, int x1, int y1, int x2, int y2);
	void drawTriangle(Render* renderer, wchar_t c, int x1, int y1, int x2, int y2, int x3, int y3);

}

#endif