#pragma once
#include <glfw3.h>

#include "Model.hpp"
#include "Maths.hpp"
#include "Entity.hpp"
#include "Weapon.hpp"

namespace LowRenderer
{
	struct Camera;
}

class Enemy;

class Player : public Entity
{
public:
	LowRenderer::Camera* p_camera = nullptr;
	Maths::Sphere collider = {model.position, 1.f};
	Player(const LowRenderer::Model& model, LowRenderer::Camera* camera, GLFWwindow* inWindow = nullptr);
	Player() : Entity() {};
	~Player();
	void update(float deltaTime , const std::vector<Platform>& platforms, std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Particle>>& particles, Weapon& weapon) override;
	
	Vector3 respawn = {};

	float maxHorizontalSpeed = 0.25f;
	float maxVerticalSpeed = 5.f;
	float jumpForce = 1.f;
	float maxShootTimer = 0.5f;
	float maxReloadTimer = 4.f;

	int forward = 'W';
	int left = 'A';
	int backward = 'S';
	int right = 'D';
	int reload = 'R';

private:
	Vector3 playerDir = { 0.f ,0.f ,0.f };

	float inertia = 10.f;
	float save = 0.f;
	float rangeShoot = 100.f;
	int bulletNumber = 5;

	float shootTimer = 0.f;

	float reloadTimer = 0.f;

	bool forwardPressed = false;
	bool backwardPressed = false;
	bool leftPressed = false;
	bool rightPressed = false;
	bool downPressed = false;

	bool RPressed = false;

	bool isDown = false;
	bool canFire = true;

	bool isColiding = false;

	GLFWwindow* window = nullptr;
	
	void checkEvents();
};
