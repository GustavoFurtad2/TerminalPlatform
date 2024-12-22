#pragma once

#ifndef RENDERER3D_HPP

#define RENDERER3D_HPP

#include "Render.hpp"
#include <vector>
#include <chrono>

namespace Renderer3D {

	struct vec3d {

		float x, y, z;
	};

	struct triangle {

		vec3d p[3];
	};

	struct mesh {

		std::vector<triangle> tris;
	};

	struct mat4x4 {

		float m[4][4] = { 0 };
	};

	void multiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m);

	void updateElapsedTime();

	void drawMesh(Render* renderer, mesh mesh);

}

#endif