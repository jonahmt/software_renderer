#include <expected>

namespace softrender {

// A simple pixelbuffer. Data is in row major order. Each element is a color in
// RGBA format.
struct Pixelbuffer {
  int width;
  int height;
  std::vector<uint32_t> data;

  Pixelbuffer(int width, int height)
      : width(width), height(height), data(width * height, 0) {}

  // Set the pixel at the given coordinates to the given color. Requires that 0
  // <= x < width and 0 <= y < height.
  void SetPixel(int x, int y, uint32_t color) {
    assert(x >= 0 && x < width && y >= 0 && y < height);
    data[y * width + x] = color;
  }

  // Retrieve the color value at the given coordinates. Requires that 0 <= x <
  // width and 0 <= y < height.
  uint32_t GetPixel(int x, int y) const {
    assert(x >= 0 && x < width && y >= 0 && y < height);
    return data[y * width + x];
  }
};

}  // namespace softrender