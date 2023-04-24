#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  //////////////////////////////////////
  bool cycling{true};
  int level{0};
  int num{5};
  while(cycling){
    game.round++;
    game.Init(level);
    int gtype = renderer.StartWindowTitle();
    if(gtype == 1){
      game.SetGameType1();
    }else if(gtype == 2){
      game.SetGameType2();
    }
    game.Run(controller, renderer, kMsPerFrame);
    if(game.round < 5){
      bool flag = renderer.EndWindowTitle2();
      if(flag){
        game.inc *= 2;
        game.fac *= 2;
        level++;
      }
    }
    /////////////////////////////////////////////
    //if(game.GetMaxScore() < game.GetScore()){
    //  game.SetMaxScore();
    //  game.SetMaxSize();
    //  game.SetBestRound();
    //}
    //game.UpdateTotalg`)Score();
    game.MgData(level);
    if(game.round >= 5) cycling = false;
  } 
  
  std::cout << "Game has terminated successfully!\n";
  std::cout << "TotalScore : " << game.GetTotalScore() << "\n";
  std::cout << "Best Round : "  << game.GetBestRound() << " Score : " << game.GetMaxScore() << " Size : " << game.GetMaxSize() << "\n";
  //std::cout << "Score: " << game.GetScore() << "\n";
  //std::cout << "Size: " << game.GetSize() << "\n";
  game.Print(num);
  return 0;
}