#include "Renderer_3d.hpp"
#include "Renderer_2d.hpp"
#include <cmath>
#include <string>
#include <iostream>

namespace Renderer3D {

	float fTheta;

	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();

	float fElapsedTime = 0.0f;

	void multiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m) {

		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];

		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

		if (w != 0.0f) {

			o.x /= w; o.y /= w; o.z /= w;
		}
	}

	void updateElapsedTime() {

		auto currentTime = std::chrono::steady_clock::now();

		std::chrono::duration<float> deltaTime = currentTime - lastTime;

		fElapsedTime = deltaTime.count();

		lastTime = currentTime;
	}

	void drawMesh(Render* renderer, mesh mesh) {

		mat4x4 matProj;

		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.0f;
		float fAspectRatio = (float)renderer->getScreenWidth() / (float)renderer->getScreenHeight();
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;

		mat4x4 matRotZ, matRotX;
		fTheta += 1.0f * fElapsedTime;

		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;

		for (auto tri : mesh.tris) {

			triangle triProjected, triTranslated, triRotatedZ, triRotatedZX;

			multiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
			multiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
			multiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

			multiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
			multiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
			multiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);

			triTranslated = triRotatedZX;
			triTranslated.p[0].z = tri.p[0].z + 3.0f;
			triTranslated.p[1].z = tri.p[1].z + 3.0f;
			triTranslated.p[2].z = tri.p[2].z + 3.0f;


			multiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
			multiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
			multiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);

			triProjected.p[0].x += 1.0f;
			triProjected.p[1].x += 1.0f;
			triProjected.p[2].x += 1.0f;

			triProjected.p[0].y += 1.0f;
			triProjected.p[1].y += 1.0f;
			triProjected.p[2].y += 1.0f;

			triProjected.p[0].x *= 0.25f * (float)renderer->getScreenWidth();
			triProjected.p[0].y *= 0.25f * (float)renderer->getScreenHeight();
			triProjected.p[1].x *= 0.25f * (float)renderer->getScreenWidth();
			triProjected.p[1].y *= 0.25f * (float)renderer->getScreenHeight();
			triProjected.p[2].x *= 0.25f * (float)renderer->getScreenWidth();
			triProjected.p[2].y *= 0.25f * (float)renderer->getScreenHeight();

			
			Renderer2D::drawTriangle(renderer, L'█',
				round(triProjected.p[0].x),
				round(triProjected.p[0].y),
				round(triProjected.p[1].x),
			    round(triProjected.p[1].y),
				round(triProjected.p[2].x),
				round(triProjected.p[2].y)
			);
			
		}

	}
}