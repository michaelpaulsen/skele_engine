#include <SDL.h>
#include <iostream>
#include <string>
#include <fstream>
#include "./headers/Window.hpp"
auto LOG_FILE = std::ofstream("log.txt");

auto init_SDL_sytem(){

  if (auto init_error_code = SDL_Init(SDL_INIT_VIDEO);
      init_error_code < 0){
        return -init_error_code;
      }
      return 0;

}
auto EventLoop(bool& quit, SDL_Event& e) {
  while(SDL_PollEvent(&e)){
    //TODO automatic event dispach and callback calling
    switch(e.type) {
      case SDL_QUIT: {
        quit = true;
      }
    }
  }
}
int main(int, char**) {
  // REM init sdl
  if(auto ret = init_SDL_sytem(); ret){
    LOG_FILE << "SDL ERROR ["  << SDL_GetError() << " (" << ret << ")]" << std::endl;
    return ret;
  }
  //REM create window
  auto window = SKC::SGE::Window();
  if(!window) {
    LOG_FILE << "SDL ERROR ["  << SDL_GetError() << "]" << std::endl;
    return 1;
  }
  //Event loop
  int x = 10, y = 10,xvel = 1, yvel = 1;
  int sw = window.GetWidth(), sh = window.GetHeight();
  bool exit_program = false;
  SDL_Event event;
  while(!exit_program) {
    EventLoop(exit_program, event);
    if(x <= 0 || x >= sw) xvel *= -1;
    if(y <= 0 || y >= sh) yvel *= -1;

    window.SetBrushColor(100,100,100);
    window.Clear();
    window.SetBrushColor(255,0,0);
    x+= xvel;
    y+= yvel;
    window.FillRect(x,y,20,20);

    window.Update();
  }
  SDL_Quit();
  return 0;

}
