#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Model.hpp"
#include "Maths.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "ResourcesManager.hpp"
#include "Constants.hpp"
#include "Interface.hpp"

#include "Player.hpp"
#include "Enemy.hpp"
#include "Platform.hpp"
#include "Particles.hpp"
#include "Weapon.hpp"

namespace Resources
{
	namespace Scene
	{
		struct ShaderData
		{
			LowRenderer::Light lights[LIGHTS_NUMBER];
			float camPos[4];
		};

		class Scene
		{
		public:
			Scene();
			Scene(ResourcesManager* inResourcesManager, GLFWwindow* window);
			Scene(ResourcesManager* inResourcesManager, GLFWwindow* window, const std::string filePath);
			~Scene() {};

			LowRenderer::Camera camera;
			LowRenderer::CameraInputs camInputs{};
			ResourcesManager* resourcesManager;

			void update(float deltaTime, GLFWwindow* window, Maths::Vector2& mousePos, int& currScene);
			void render();
			void renderModel(int model, const Maths::mat4x4& modelMat, const Maths::mat4x4& viewProj);
			void renderModel(LowRenderer::Model& model, const Maths::mat4x4& modelMat, const Maths::mat4x4& viewProj);
		private:
			bool isPressed = false;
			bool loadOnce = false;

			bool isMenu = false;
			Interface m_interface;
			Player player;
			Weapon weapon;
			ShaderData shaderData = {};
			unsigned int UBO;
			std::vector<Platform> platforms;
			std::vector<std::shared_ptr<Particle>> particles;
			std::vector<std::shared_ptr<Enemy>> enemies;
			std::vector<LowRenderer::Model> models;
			std::vector<LowRenderer::Model> ui;
			void processInput(GLFWwindow* window, Maths::Vector2& mousePos, int& currScene);
			void updateCollisions();
			void updateShaderData();
			void bindModelResources(const LowRenderer::Model& model);
			void parseLineModel(std::string& line, const std::string& path);
			void parseLineCamera(std::string& line);
			void parseLineLight(std::string& line);
			void checkGameState(GLFWwindow* window, int& currScene);
		};
	}
}
