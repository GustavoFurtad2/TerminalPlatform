#include "Graphics.hpp"

namespace Graphics {

	void drawRect(Render* renderer, wchar_t c, int x, int y, int width, int height) {

		for (int charY = y; charY < height; charY++) {

			for (int charX = x; charX < width; charX++) {

				renderer->drawChar(charX, charY, c);
			}
		}
	}

	void drawText(Render* renderer, wchar_t *c, int x, int y) {

		size_t len = wcslen(c);

		for (int charX = x; charX < x + len; charX++, c++) {

			renderer->drawChar(charX, y, *c);
		}
	}

}