#include "pixelbuffer.h"

#include <cassert>

namespace softrender {

Pixelbuffer::Pixelbuffer(int width, int height)
    : width(width), height(height), data(width * height, 0) {}

void Pixelbuffer::SetPixel(int x, int y, uint32_t color) {
  assert(x >= 0 && x < width);
  assert(y >= 0 && y < height);
  data[y * width + x] = color;
}

uint32_t Pixelbuffer::GetPixel(int x, int y) const {
  assert(x >= 0 && x < width);
  assert(y >= 0 && y < height);
  return data[y * width + x];
}
}  // namespace softrender
