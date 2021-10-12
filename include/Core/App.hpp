#pragma once

#include <glad.h>
#include <glfw3.h>

#include "Maths.hpp"
#include "Constants.hpp"
#include "Camera.hpp"
#include "ResourcesManager.hpp"
#include "Scene.hpp"

namespace App
{
	GLFWwindow* initOpenGL(bool& initOK);
	class App
	{
	public:
		App(bool& initOK, GLFWwindow* inWindow);
		~App();

		//void processInput();

		void run();
		void processInput();

		inline float updateDeltaTime(float oldTime) { time = (float)glfwGetTime(); if (time - oldTime < 1.f / 15.f) return (time - oldTime); else return 1.f / 60.f; };
	private:
		Resources::Scene::Scene scenes[SCENES_NUMBER];
		GLFWwindow* window;
		Resources::ResourcesManager resourcesManager;
		Maths::Vector2 mousePos{};
		float time = 0;
		float deltaTime = 0;
		int currScene = 0;
		bool isCursorHidden = true;
	};
}