#pragma once

#include "Maths.hpp"
#include "Constants.hpp"
#include "Model.hpp"

class Particle
{
public:
	LowRenderer::Model models[PARTICLE_MAX_MODELS]{};
	Maths::Vector3 directions[PARTICLE_MAX_MODELS]{};
	float speeds[PARTICLE_MAX_MODELS]{};
	bool toDestroy = false;

	Particle(const Vector3 position = {}, const float lifeTime = 1.f);
	~Particle() {};
	virtual void update(float deltaTime);

protected:
	float timer; // particle lifetime (seconds)
	float currentTime = 0.f;

};