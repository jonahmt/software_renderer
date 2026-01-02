#pragma once

#include <cstdint>
#include <vector>

#include "mesh.h"
#include "sr_math.h"
#include "texture.h"

namespace softrender {

// Represents an instance of an object in the scene.
struct RenderObject {
  // Special id value for invalid object IDs (those that have been deleted).
  static constexpr uint32_t kInvalidObjectId = 0xFFFFFFFF;

  // ID of the mesh for this object.
  uint32_t mesh_id;
  // ID of the texture for this object.
  uint32_t texture_id;
  // Matrix that takes this object from local space to world space.
  Matrix<4, 4> transform;

  // Whether or not this object is valid. For deleted objects, this will be
  // false.
  [[nodiscard]] bool IsValid() const;
};

class Scene {
 public:
  // Adds a mesh to the scene and returns its ID.
  uint32_t AddMesh(const Mesh& mesh);
  // Adds a texture to the scene and returns its ID.
  uint32_t AddTexture(const Texture& texture);
  // Registers a render object with the specified mesh ID, texture ID, and
  // transform matrix. Returns the ID of the registered object.
  uint32_t RegisterObject(uint32_t mesh_id, uint32_t texture_id,
                          const Matrix<4, 4>& transform);

  // Returns a read only reference to the list of all meshes in the scene.
  [[nodiscard]] const std::vector<Mesh>& GetMeshes() const;
  // Returns a read only reference to the list of all textures in the scene.
  [[nodiscard]] const std::vector<Texture>& GetTextures() const;
  // Returns a read only reference to the list of all render objects in the
  // scene.
  [[nodiscard]] const std::vector<RenderObject>& GetObjects() const;

  // Updates the transform of the specified render object.
  void UpdateObjectTransform(uint32_t object_id, const Matrix<4, 4>& transform);
  // Removes the specified render object from the scene.
  void RemoveObject(uint32_t object_id);

 private:
  // List of all meshes in the scene, indexed by mesh ID.
  std::vector<Mesh> meshes_;
  // List of all textures in the scene, indexed by texture ID.
  std::vector<Texture> textures_;
  // List of all render objects in the scene, each referencing a mesh and
  // texture by ID.
  std::vector<RenderObject> objects_;

  // List of object IDs that are no longer in use and can be reused for a newly
  // created object.
  std::vector<uint32_t> free_object_ids_;
};

}  // namespace softrender