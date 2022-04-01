#pragma once

#include <vector>
#include "glm/glm.hpp"

namespace xentu
{
   using Vertex = glm::mat3;
   
   struct Mesh
   {
      std::vector<Vertex> vertices;
   };
} // namespace xentu
