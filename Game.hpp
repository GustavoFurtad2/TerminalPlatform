#pragma once

#ifndef GAME_HPP

#define GAME_HPP

#include <iostream>
#include <chrono>
#include "Render.hpp"
#include "renderer_3d.hpp"

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

		Renderer3D::mesh cube;

		int x = 0;

};

#endif