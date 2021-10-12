
#include "Maths.hpp"
#include "Model.hpp"
#include "Constants.hpp"
#include "Particles.hpp"
#include <stdlib.h>

Particle::Particle(const Vector3 position, const float lifeTime)
{
	timer = lifeTime;
	for (int i = 0; i < PARTICLE_MAX_MODELS; i++)
	{
		models[i] = LowRenderer::Model("../resources/blank.png", "../resources/blank.obj", "../resources/skybox", position,
			{}, 1.f);
	}
}

void Particle::update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime >= timer) toDestroy = true;
}