#pragma once

#include <cstdint>
#include <vector>

namespace softrender {

class Texture {
 public:
  Texture(int width, int height);
  ~Texture();

  // Gets the pixel color at the specified coordinates (x, y) as an RGBA
  // uint32_t.
  [[nodiscard]] uint32_t GetPixel(int x, int y) const;
  // Sets the pixel color at the specified coordinates (x, y) to the given RGBA
  // color.
  void SetPixel(int x, int y, uint32_t color);

  // Returns the width of the texture in pixels.
  [[nodiscard]] int GetWidth() const;
  // Returns the height of the texture in pixels.
  [[nodiscard]] int GetHeight() const;

 private:
  // Width of the texture in pixels.
  int width_;
  // Height of the texture in pixels.
  int height_;
  // Data stored as RGBA pixels in row major order.
  std::vector<uint32_t> data_;
};

}  // namespace softrender