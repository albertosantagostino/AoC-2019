/// https://adventofcode.com/2019/day/2 (part 2)
/// @author Alberto Santagostino

#include "IntCodeMachine.h"
#include "utils.h"

int main()
{
    std::ifstream Pfile;
    Pfile.open("input.txt");
    std::pair<int, int> correct_seed;

    // Set target output
    const int target_value = 19690720;

    bool end{false};
    bool found{false};

    auto machine = new IntCodeMachine;
    machine->LoadProgramFromFile(Pfile);
    auto original_program = machine->GetProgram();

    for(int noun = 0; noun < 100 && !found; noun++)
        for(int verb = 0; verb < 100 && !found; verb++)
        {
            auto seed = std::make_pair(noun, verb);

            machine->SetProgram(original_program);
            machine->SetProgramNounVerb(seed);

            std::cout << "Testing with " << seed.first << "," << seed.second;

            // Run Intcode program
            do
            {
                end = machine->StepProgram();
            } while(!end);

            // Check outcome
            int out = machine->GetProgram()[0];
            std::cout << ". First value: " << out << std::endl;
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
