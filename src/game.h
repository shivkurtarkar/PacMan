#ifndef GAME_H
#define GAME_H

#include <random>
#include <SDL2/SDL.h>
#include "controller.h"
#include "gameState.h"

#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::string mapFilename);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
 private:

  std::string _mapFilename;
  GameState _gameState;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void Update();
};

#endif