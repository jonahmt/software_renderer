#pragma once

#include "math.h"

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
  const Pixelbuffer& GetPixelbuffer() const;

 private:
  int width_;
  int height_;
  Pixelbuffer pb_;
};

}  // namespace softrender