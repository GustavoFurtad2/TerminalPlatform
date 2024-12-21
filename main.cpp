#include <iostream>
#include "Game.hpp"

int main() {

    Game game;

    while (game.isRunning()) {

        game.update();
        game.render();
        /*
        auto startTime = std::chrono::high_resolution_clock::now();

        if (GetAsyncKeyState(VK_ESCAPE)) {
            isRunning = false;
        }

        static int x = 0;
        static int y = 0;

        y++;
        if (y > screenHeight) {
            y = 0;
        }

        // Renderização
        for (int i = 0; i < screenWidth * screenHeight; i++) {
            screen[i] = L' ';
        }
        screen[y * screenWidth + x] = L'@';

        // Desenha na tela
        WriteConsoleOutputCharacter(hConsole, screen, screenWidth * screenHeight, { 0, 0 }, &dwBytesWritten);

        // Controle de FPS (60 FPS)
        std::this_thread::sleep_until(startTime + std::chrono::milliseconds(16));
    }

    delete[] screen;
    CloseHandle(hConsole);
    */
    }

    std::cout << game.isRunning();

    game.quit();

    return 0;
}
