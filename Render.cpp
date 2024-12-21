#include "Render.hpp"

Render::Render() {

	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleActiveScreenBuffer(hConsole);

	bufferSize = {
		(SHORT)SCREEN_WIDTH,
		(SHORT)SCREEN_HEIGHT
	};

	windowSize = {
		0, 0,
		(SHORT)(SCREEN_WIDTH - 1),
		(SHORT)(SCREEN_HEIGHT - 1)
	};

	SetConsoleScreenBufferSize(hConsole, bufferSize);
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_SIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

Render::~Render() {

	delete[] screen;
	CloseHandle(hConsole);
}

void Render::clearScreen() {

	for (int i = 0; i < SCREEN_PIXELS; i++) {
		screen[i] = L' ';
	}
}

void Render::draw() {

	WriteConsoleOutputCharacter(hConsole, screen, SCREEN_PIXELS, { 0, 0 }, &dwBytesWritten);
}

void Render::drawChar(int x, int y, wchar_t c) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
		screen[y * SCREEN_WIDTH + x] = c;
	}
}