#include "Renderer_2d.hpp"
#include <cmath>

namespace Renderer2D {

    void drawRect(Render* renderer, wchar_t c, int x, int y, int width, int height) {

        for (int charY = y; charY < y + height; charY++) {

            for (int charX = x; charX < x + width; charX++) {
                renderer->drawChar(charX, charY, c);
            }
        }
    }

    void drawText(Render* renderer, wchar_t* c, int x, int y) {

        size_t len = wcslen(c);

        for (int charX = x; charX < x + len; charX++, c++) {

            renderer->drawChar(charX, y, *c);
        }
    }

    void drawLine(Render* renderer, wchar_t c, int x1, int y1, int x2, int y2) {

        int distanceX = x2 - x1;
        int distanceY = y2 - y1;

        float distanceBetweenPoints = sqrt(distanceX * distanceX + distanceY * distanceY);

        float x = x1;
        float y = y1;

        for (float i = 0; i < distanceBetweenPoints; i++) {

            renderer->drawChar(round(x), round(y), c);

            x += distanceX / distanceBetweenPoints;
            y += distanceY / distanceBetweenPoints;
        }
    }

    void drawTriangle(Render* renderer, wchar_t c, int x1, int y1, int x2, int y2, int x3, int y3) {

        drawLine(renderer, c, x1, y1, x2, y2);
        drawLine(renderer, c, x2, y2, x3, y3);
        drawLine(renderer, c, x3, y3, x1, y1);
    }

}
