/// https://adventofcode.com/2019/day/2 (part 2)
/// @author Alberto Santagostino

#include "utils.h"

int main()
{
    std::ifstream Pfile;
    std::vector<int> program;
    std::vector<int> modified_program;
    std::size_t pos{0};
    std::pair<int, int> correct_seed;
    bool end{false};
    bool found{false};

    // Set target output
    const int target_value = 19690720;

    Pfile.open("input.txt");
    LoadFromFile(Pfile, program);

    for(int noun = 0; noun < 100 && !found; noun++)
        for(int verb = 0; verb < 100 && !found; verb++)
        {
            auto seed = std::make_pair(noun, verb);
            SetProgram(program, modified_program, seed, pos, end);
            std::cout << "Testing with " << seed.first << "," << seed.second;

            // Run Intcode program
            do
                ExecuteStep(modified_program, pos, end);
            while(!end);

            // Check outcome
            int out = modified_program[0];
            std::cout << "... out: " << out << std::endl;
            if(out == target_value)
            {
                found = true;
                correct_seed = seed;
            }
        }

    if(found)
    {
        std::cout << "Winning (noun,verb) pair: " << correct_seed.first << "," << correct_seed.second << std::endl;
        std::cout << "Solution (part 2): " << correct_seed.first * 100 + correct_seed.second << std::endl;
    }
    else
        std::cout << "No (noun,verb) pair found for the given output" << std::endl;

    return EXIT_SUCCESS;
}
