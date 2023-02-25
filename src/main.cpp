#include <iostream>
#include "controller.h"
#include "game.h"
#include "result.h"
#include "renderer.h"
#include "time.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int difficulty;
  double time_played = 0;
  time_t start, end;
  std::cout << "Please enter an integer for your desired level of difficulty: ";
  std::cin >> difficulty;
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, difficulty);
  time(&start);
  game.Run(controller, renderer, kMsPerFrame);
  time(&end);
  Result result(difftime(end, start), game.GetScore(), game.GetSize(), difficulty, game.GetReasonOfDeath());
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  std::cout << "Time played = " << difftime(end, start) << " seconds" << std::endl;
  std::cout << "Reason of death: " << game.GetReasonOfDeath() << "\n";
  result.WriteToFile();
  return 0;
}