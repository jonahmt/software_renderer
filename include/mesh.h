#pragma once

#include <cstdint>
#include <vector>

#include "math.h"

namespace softrender {

// Class that represents an object in the scene.
class Mesh {
 public:
  // Adds a vertex with the specified attributes to the mesh. Returns the
  // id/index of the newly added vertex.
  uint32_t AddVertex(Vector<3> pos, Vector<2> uv, Vector<3> normal);
  // Adds a triangle defined by three vertex indices. Vertices should be in CCW
  // winding order for front-facing triangles.
  void AddTriangle(uint32_t v0, uint32_t v1, uint32_t v2);

  // Returns the position of the vertex specified by index.
  [[nodiscard]] Vector<3> GetVertexPosition(uint32_t v) const;
  // Returns the UV coordinates of the vertex specified by index.
  [[nodiscard]] Vector<2> GetVertexUV(uint32_t v) const;
  // Returns the normal of the vertex specified by index.
  [[nodiscard]] Vector<3> GetVertexNormal(uint32_t v) const;

  // Returns a read only reference to the entire list of vertex positions.
  [[nodiscard]] const std::vector<Vector<3>>& GetPositions() const;
  // Returns a read only reference to the entire list of vertex texture
  // coordinates.
  [[nodiscard]] const std::vector<Vector<2>>& GetUVs() const;
  // Returns a read only reference to the entire list of vertex normals.
  [[nodiscard]] const std::vector<Vector<3>>& GetNormals() const;

  // Returns a read only reference to the entire list of triangle vertex
  // indices.
  [[nodiscard]] const std::vector<uint32_t>& GetIndices() const;

 private:
  // Store data as a struct of arrays for cache efficiency
  struct VertexList {
    std::vector<Vector<3>> positions;
    std::vector<Vector<2>> uvs;
    std::vector<Vector<3>> normals;
  };

  // Store data as a struct of arrays for cache efficiency
  struct TriangleList {
    // Face f has vertex indices at vector elements 3f, 3f+1, 3f+2. Vertices
    // that are front facing should be in CCW winding order.
    std::vector<uint32_t> indices;
  };

  VertexList vertices_;
  TriangleList tri_list_;
};

}  // namespace softrender
