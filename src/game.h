#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int difficulty);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  std::string GetReasonOfDeath() const;

 private:
  Snake snake;
  SDL_Point food;
  SDL_Point single_poisonous_food;
  std::vector<SDL_Point> vector_poisonous_food;
  int difficulty;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void PlacePoisonousFood();
  void Update();
};

#endif