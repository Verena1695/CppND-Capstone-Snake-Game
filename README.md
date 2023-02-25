# CPPND: Capstone Snake Game Extension

This project is an extension of the Snake Game introduced in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>


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

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## Description of the project

This project is an extension of the Snake Game where the user controls a snake with the arrow keys on the keyboard to collect food items.
With every food item the snake consumes the score increases and the body of the snake grows. Also, the speed with which the snake moves increases.
The game ends as soon as the snake bites itself.

In this extension poisonous food items were added to the game so that there are two possible reasons of death - biting itself and eating poisonous food.
Furthermore, this project enables the user to choose the desired level of difficulty by entering an integer of his or her choice at the beginning of the game which determines the number of poisonous food items on the screen. The higher the number, the more poisonous items will appear. To be able to distinguish between poisonous and non-poisonous food items, they are rendered in different colors (yellow = non-poisonous, pink = poisonous).

After every round the results are written to a .txt file which will make it possible to keep track of the different rounds and see if the user improves. The results include:
1. Level of difficulty
2. Score
3. Size of the snake at the end of the game
4. Reason of death
5. Time played


## Code structure

Generally speaking the code is organized following Object Oriented Programming principles. For every class there is a separate .h file with the class declaration and a corresponding .cpp file with the implementation of the class methods.
The following classes are part of the project:
1. Controller - Responsible for controlling the snake
2. Renderer - Determines for example how the snake and the different food items should look like
3. Snake - Responsible for updating the "status" of the snake (e.g. size or speed after eating food, or dying)
4. Game - Responsible for updating the game in general (e.g. updating the score and placing new food items)
5. Result - Collects all results of a round and is responsible for writing them to the .txt file.


## Rubric points which are addressed with this project

1. The project demonstrates an understanding of C++ functions and control structures
    - Newly added function to place poisonous food uses while, if and for statements in a nested way (game.cpp, lines 59-80).
    - This function is called repeatedly via a for loop based on the chosen level of difficulty by the user (game.cpp lines 13-15).
2. The project reads data from a file and processes the data, or the program writes data to a file
    - The program writes the results of the game to a .txt file (result.cpp, lines 8-21).
3. The project accepts user input and processes the input
    - At the beginning of the game the user is asked to enter an integer to specify the level of difficulty, i.e. the number of poisonous items (main.cpp, lines 19-20 and 23; game.cpp, lines 13-15).
4. The project uses Object Oriented Programming Techniques
    - Apart from extending some of the classes from the starter code by adding new data members and methods (e.g. game.h, lines 18, 23-25 and 35), a new class "Result" was created to store the results of the game in an external file (result.h).
5. Classes use appropriate access specifiers for class members
    - Data members or class methods which extended existing classes from the starter code were put to the appropriate "private" or "public" sections (game.h, lines 18, 23-25 and 35; snake.h, line 31).
    - In the newly created class "Result" all data members are specified as private whereas the constructor and the method to write the results to the external file are public (result.h).