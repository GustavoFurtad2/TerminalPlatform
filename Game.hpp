#pragma once

#ifndef GAME_HPP

#define GAME_HPP

#include <iostream>
#include <chrono>
#include "Render.hpp"

class Game {

	public:

		Game();
		
		void quit();
		void render();
		void update();
		
		bool isRunning() {
			return running;
		}

	private:

		Render* renderer = new Render();

		bool running = true;

		int x = 0;

};

#endif