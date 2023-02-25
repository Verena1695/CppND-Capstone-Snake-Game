#ifndef RESULT_H
#define RESULT_H

#include "game.h"
#include <string>
#include <iostream>
#include <fstream>

// Class to write the results to a file

class Result {

    private:
        double time_played;
        int score;
        int size;
        int difficulty;
        std::string reason_of_death;

    public:
        Result(double time_played, int score, int size, int difficulty, std::string reason_of_death);
        void WriteToFile();

};

#endif