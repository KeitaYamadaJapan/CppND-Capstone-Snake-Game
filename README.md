# CPPND: Capstone Snake Game

This is for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

This game code is modified from code from below URL.
    https://github.com/udacity/CppND-Capstone-Snake-Game

In this game, player .

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Open New Terminal.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## How to play.

  (1) Player graded by total score of 5 rounds.
  (2) At each round, player will sellect 2 game type.
      a. TimeLimit type (enter key "1")
        Snake can live for 20 seconds. CountDown show player rest time witch snake can keep to live.
        But when snake eate food, CountDown reset to 20 seconds.
      b. FoodTrial type (enter key "2")
        Snake can live for 10 Trial.Each Trial begin when snake enter into stage, and end when snake get out from stage.
  (3) After each round, player will choose Up game level
      (enter key "y") or keep prev Trial level(enter key "n")


## class structure

controller class
game class
main class
snake class

Player start game. 
Call main class.
main class call game class and run game.
game class control snake run and eat food, and control render to make display.
After 5 rounds game runnuing, Total score, best score and best round,each rounds scores will be shown at terminal. 

## Covered Rubic points

A README with instructions is included with the project
The README indicates which project is chosen.
The README includes information about each rubric point addressed.
The submission must compile and run.
The project demonstrates an understanding of C++ functions and control structures.
The project accepts user input and processes the input.
The project uses Object Oriented Programming techniques.
Classes use appropriate access specifiers for class members.
Class constructors utilize member initialization lists.
Classes encapsulate behavior.
Classes follow an appropriate inheritance hierarchy.
Derived class functions override virtual base class functions.
The project makes use of references in function declarations.
The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
The project follows the Rule of 5.
The project uses move semantics to move data, instead of copying it, where possible.


## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
