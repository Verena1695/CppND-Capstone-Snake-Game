#include "result.h"


Result::Result(double time_played, int score, int size, int difficulty, std::string reason_of_death)
    : time_played(time_played), score(score), size(size), difficulty(difficulty), reason_of_death(reason_of_death) {};

// Write results of the game to a file
void Result::WriteToFile() {
    if (std::ifstream("results.txt")){
        std::ofstream output("results.txt", std::ios_base::app);
        output << difficulty << "   |   " << score << "   |   " << size << "   |   " << reason_of_death << "   |   " << time_played << " seconds\n";
        output.close();
    }
    else {
        std::ofstream output("results.txt");
        output << "Difficulty   |   Score   |   Snake size  |   Reason of death   |   Time played\n";
        output << "-------------------------------------------------------------------------------\n";
        output << difficulty << "   |   " << score << "   |   " << size << "   |   " << reason_of_death << "   |   " << time_played << " seconds\n";
        output.close();
    }
}