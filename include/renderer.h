#pragma once

#include <vector>

#include "camera.h"
#include "pixelbuffer.h"
#include "scene.h"
#include "sr_math.h"

namespace softrender {

// The main renderer class. Users will instantiate this class, call various
// setup functions to load their scene objects, and then per frame draw
// functions.
class Renderer {
 public:
  Renderer(int width, int height);
  ~Renderer();

  // Provides read-only access to the underlying pixelbuffer containing the
  // rendered image.
  [[nodiscard]] const Pixelbuffer& GetPixelbuffer() const;

  // Renders the specified scene using the specified camera. Updates the stored
  // pixelbuffer with the rendered image.
  void Render(const Scene& scene, const Camera& camera);

 private:
  int width_;
  int height_;
  Pixelbuffer pb_;
  // Depth buffer for the current frame. Same dimensions as the pixelbuffer.
  // Each element is the depth value for the pixel at the corresponding index in
  // the pixelbuffer (larger is further from the camera).
  std::vector<Real> depth_buffer_;
};

}  // namespace softrender