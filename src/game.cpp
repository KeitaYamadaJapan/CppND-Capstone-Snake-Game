#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  /*
  Add
  */
 Uint32 curr_time;
 start_time = SDL_GetTicks();

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
    /*
    Add
    */
    curr_time = SDL_GetTicks();
    //////////////////////////////////////////////////////
    int cntDown{20};
    int cdBase{20};
    cntDown = cdBase - (curr_time - start_time)/1000;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      //renderer.UpdateWindowTitle(score, frame_count);
      if(gameType == 1){
        renderer.UpdateWindowTitle1(round, cntDown, score, frame_count);
      }else if(gameType == 2){
        renderer.UpdateWindowTitle2(round, lastFoodTry, score, frame_count);
      }
      frame_count = 0;
      title_timestamp = frame_end;
    }

    /*
    Modify
    */
    if(!snake.stayStage){
      lastFoodTry--;
      snake.stayStage = true;
    }else if(gameType == 2 && lastFoodTry <= 0){
      snake.alive = false;
    }
    if(gameType ==1 && cntDown <= 0 ) snake.alive = false;



    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    /*
    Add
    */
    if(snake.alive == false) running = false;
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score += inc*fac;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02*fac*fac;
    /*
    Add
    */
    //lastFoodTry = 10;
    start_time = SDL_GetTicks();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

/*
Add
*/

//bool Game::IsContPlay() const { return playing; }
void Game::SetGameType1(){ gameType = 1; }
void Game::SetGameType2(){ gameType = 2; }
int Game::GetGameType() const { return gameType; }

/////////////////////////////////////////////////////
int Game::GetMaxScore() const { return maxScore;}
void Game::SetMaxScore() { maxScore = score; }
void Game::SetMaxSize() { maxSize = GetSize(); }
int Game::GetMaxSize() const { return maxSize; }
void Game::SetBestRound() { bestRound = round; }
int Game::GetBestRound() const { return bestRound; }

void Game::Init(int level){ 
  ////////////////////////////////////
  lastFoodTry = 10;
  score = 0;
  ///////////////////////////////////////////
  Game::snake.Init(level); 
}

//////////////////////////////////////////////////////
void Game::UpdateTotalScore(){ TotalScore += score; }
int Game::GetTotalScore() const { return TotalScore; }

void Game::MgData(int l){
  levels.emplace_back(l);
  int s{score};
  scores.emplace_back(s);
  if(GetMaxScore() < GetScore()){
    SetMaxScore();
    SetMaxSize();
    SetBestRound();
  }
  UpdateTotalScore();
}
void Game::Print(int n){
  for(int i = 0; i < n; i++){
    std::cout << "Rnd : " << i+1 << " level: " << levels[i] << " Score : " << scores[i] << "\n";
  }
}


