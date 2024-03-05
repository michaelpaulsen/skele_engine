#include <SDL.h>
#include <cstdint>

namespace SKC::SGE {
// REM: int SDL_RenderFillRect(SDL_Renderer * renderer,
// const SDL_Rect * rect);
class Window {
  using color_t = uint8_t;
  // TODO create color class
  // TODO implement "CSS" colors
  constexpr static auto NOPOS = SDL_WINDOWPOS_UNDEFINED;
  constexpr static auto WINFLAG = 0;
  constexpr static auto RENDERFLAGS = SDL_RENDERER_ACCELERATED;
  constexpr static int W = 640, H = 480;
  /// TODO make varible

  bool isValidWindow = false;
  SDL_Window *window;
  SDL_Renderer *w_renderer;
  int w_height, w_width;
  int windowSizeResult = 0;

public:
  Window() {
    window = SDL_CreateWindow("test", NOPOS, NOPOS, W, H, WINFLAG);
    w_renderer = SDL_CreateRenderer(window, -1, RENDERFLAGS);
    windowSizeResult =
        SDL_GetRendererOutputSize(w_renderer, &w_width, &w_height);
    isValidWindow = window && w_renderer;
    isValidWindow = isValidWindow && !windowSizeResult;
  }
  ~Window() {
    SDL_DestroyRenderer(w_renderer);
    SDL_DestroyWindow(window);
  }
  bool operator!() { return !this->isValidWindow; }
  // functions
  int GetWidth(){return w_width;}
  int GetHeight(){return w_height;}

  void Update() { SDL_RenderPresent(w_renderer); }
  int SetBrushColor(color_t r, color_t g, color_t b) {
    return SDL_SetRenderDrawColor(w_renderer, r, g, b, SDL_ALPHA_OPAQUE);
  }
  void FillRect(int x, int y, int w, int h) {
      SDL_Rect rect = {x, y, w, h};
      // TODO make class property
      SDL_RenderFillRect(w_renderer, &rect);
}
  void Clear() {
    SDL_Rect screenRect = {0, 0, w_width, w_height};
    // TODO make class property
    SDL_RenderFillRect(w_renderer, &screenRect);
  }
};
} // namespace SKC::SGE
