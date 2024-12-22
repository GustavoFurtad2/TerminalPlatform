#pragma once

#ifndef RENDER_HPP

#define RENDER_HPP

#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

#define SCREEN_WIDTH 140
#define SCREEN_HEIGHT 105
#define SCREEN_PIXELS SCREEN_WIDTH * SCREEN_HEIGHT

class Render {

	public:

		Render();
		~Render();

		void draw();
		void clearScreen();

		void drawChar(int x, int y, wchar_t c);

		int getScreenWidth() {
			return SCREEN_WIDTH;
		}

		int getScreenHeight() {
			return SCREEN_HEIGHT;
		}

	private:

		wchar_t* screen = new wchar_t[SCREEN_WIDTH * SCREEN_HEIGHT];

		HANDLE hConsole;

		COORD bufferSize;

		SMALL_RECT windowSize;

		DWORD dwBytesWritten = 0;

};

#endif