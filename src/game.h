#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

#include <vector>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  /*
  Add
  */
  //void EndPlay();
  //bool IsContPlay() const;
  void SetGameType1();
  void SetGameType2();
  int GetGameType() const;

  void SetMaxScore();
  int GetMaxScore() const;
  void SetMaxSize();
  int GetMaxSize() const;
  void SetBestRound();
  int GetBestRound() const;

  void Init(int level);

  Uint32  start_time;

  int inc{1};
  int fac{1};
  //////////////////////
  int round{0};
  int lastFoodTry{10};
  void UpdateTotalScore();
  int GetTotalScore() const;
  //////////////////////////////////
  void MgData(int l);
  void Print(int n);


 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();

  /*
  Add
  */
  //bool playing{true};
  //int round{0};
  int gameType{0};

  int maxScore{0};
  int maxSize{0};
  int bestRound{0};

  //int lastFoodTry{0};
  //////////////////////////////////
  int TotalScore{0};
  //////////////////////////////////
  std::vector<int> levels;
  std::vector<int> scores;

};

#endif