#include "pixelbuffer.h"

namespace softrender {

Pixelbuffer::Pixelbuffer(int width, int height)
    : width(width), height(height), data(width * height, 0) {}

void Pixelbuffer::SetPixel(int x, int y, uint32_t color) {}

uint32_t Pixelbuffer::GetPixel(int x, int y) const { return 0; }
}  // namespace softrender