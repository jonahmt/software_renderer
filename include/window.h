#pragma once

#include <string>

#include "pixelbuffer.h"

namespace softrender {

// Class that handles actually displaying the rendered scene onto the user's
// screen. Owns the display and simply fetches the Pixelbuffer to draw from a
// Renderer.
class Window {
 public:
  Window(std::string name, int width, int height);
  ~Window();

  // Displays the content of the pixel buffer on the screen.
  void Display(Pixelbuffer& pixelbuffer);

  // Polls for user events such as closing the window. Updates the internal
  // state of the Window.
  void PollEvents();

  // Returns whether or not the window should close and terminate the rendering
  // loop.
  bool ShouldClose() const;

 private:
  // Class is not copyable
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  bool should_close_;
  int width_;
  int height_;
};

}  // namespace softrender