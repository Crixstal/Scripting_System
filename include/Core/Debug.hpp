#pragma once
#include <vector>
#include "Maths.hpp"
#include "Mesh.hpp"
#include "ResourcesManager.hpp"

namespace Debug
{
	// PARSING DEBUG
	void printVectors(const std::vector<Maths::Vector3>& pos, const std::vector<Maths::Vector2>& uvc, const std::vector<Maths::Vector3>& norm, const std::vector<Resources::Face3>& faces);
	void printVertexBufferRaw(const std::vector<float>& buffer);
	void printVertexBufferParse(const std::vector<float>& buffer);
}