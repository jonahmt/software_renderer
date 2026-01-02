#include "mesh.h"

#include <vector>

#include "sr_math.h"

// TODO Implement.

namespace softrender {

uint32_t Mesh::AddVertex(Vector<3> pos, Vector<2> uv, Vector<3> normal) {
  return 0;
}

void Mesh::AddTriangle(uint32_t v0, uint32_t v1, uint32_t v2) {}

Vector<3> Mesh::GetVertexPosition(uint32_t v) const { return Vector<3>(); }

Vector<2> Mesh::GetVertexUV(uint32_t v) const { return Vector<2>(); }

Vector<3> Mesh::GetVertexNormal(uint32_t v) const { return Vector<3>(); }

const std::vector<Vector<3>>& Mesh::GetPositions() const {
  return *new std::vector<Vector<3>>();
}

const std::vector<Vector<2>>& Mesh::GetUVs() const {
  return *new std::vector<Vector<2>>();
}

const std::vector<Vector<3>>& Mesh::GetNormals() const {
  return *new std::vector<Vector<3>>();
}

const std::vector<uint32_t>& Mesh::GetIndices() const {
  return *new std::vector<uint32_t>();
}

}  // namespace softrender