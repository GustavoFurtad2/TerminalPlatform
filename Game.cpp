#include "Game.hpp"
#include "Graphics.hpp"

Game::Game() {}

void Game::quit() {

	delete renderer;
}

void Game::render() {

	renderer->clearScreen();

	Graphics::drawRect(renderer, L'█', 0, 0, 5, 5);

	wchar_t text[] = L"Teste";

	Graphics::drawText(renderer, text, 5, 10);

	renderer->draw();
}

void Game::update() {

}