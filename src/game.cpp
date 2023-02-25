#include "game.h"
#include <iostream>
#include "SDL.h"
#include <algorithm>

Game::Game(std::size_t grid_width, std::size_t grid_height, int difficulty)
    : snake(grid_width, grid_height),
      difficulty(difficulty),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
  for (auto i=0; i<difficulty; i++){
    PlacePoisonousFood();
  }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, vector_poisonous_food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

// Method to place poisonous food
void Game::PlacePoisonousFood() {
  int x, y;
  bool placeable;
  while(true){
    x = random_w(engine);
    y = random_h(engine);
    if (!snake.SnakeCell(x, y) && x != food.x && y != food.y) {
      for (auto i=0; i<vector_poisonous_food.size(); i++){
          placeable = false;
          if (x != vector_poisonous_food[i].x && y != vector_poisonous_food[i].y){
            placeable = true;
          }
        }
      if (placeable == true){
        single_poisonous_food.x = x;
        single_poisonous_food.y = y;
        vector_poisonous_food.push_back(single_poisonous_food);
        return;
      }
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  bool placeable;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or poisonous item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      for (auto i=0; i<vector_poisonous_food.size(); i++){
        placeable = false;
        if (x != vector_poisonous_food[i].x && y != vector_poisonous_food[i].y){
          placeable = true;
        }
      }
      if (placeable == true){
        food.x = x;
        food.y = y;
        return;
      }
    }
  }
}

void Game::Update() {
  // Check if snake ate poisonous food
  for (auto i=0; i<vector_poisonous_food.size(); i++){
    if (static_cast<int>(snake.head_x) == vector_poisonous_food[i].x && static_cast<int>(snake.head_y) == vector_poisonous_food[i].y) {
        snake.alive = false;
        snake.reason_of_death = "Snake ate poisonous food";
        return;
      }
  }
  if (!snake.alive){
    return;
  }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
    // Newly place poisonous food
    vector_poisonous_food.clear();
    for (auto i=0; i<difficulty; i++){
      PlacePoisonousFood();
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
std::string Game::GetReasonOfDeath() const { return snake.reason_of_death; }