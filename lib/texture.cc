#include "texture.h"

#include <cassert>

namespace softrender {

Texture::Texture(int width, int height)
    : width_(width), height_(height), data_(width * height, 0) {}

int Texture::GetWidth() const { return width_; }

int Texture::GetHeight() const { return height_; }

uint32_t Texture::GetPixel(int x, int y) const {
  assert(x >= 0 && x < width_);
  assert(y >= 0 && y < height_);
  return data_[y * width_ + x];
}

void Texture::SetPixel(int x, int y, uint32_t color) {
  assert(x >= 0 && x < width_);
  assert(y >= 0 && y < height_);
  data_[y * width_ + x] = color;
}
}  // namespace softrender
