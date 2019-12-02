/// https://adventofcode.com/2019/day/2 (part 1)
/// @author Alberto Santagostino

#include "utils.h"

int main()
{
    std::ifstream Pfile;
    std::vector<int> program;
    std::vector<int> modified_program;
    std::size_t pos{0};
    bool end{false};

    // Set code 1202
    auto code = std::make_pair(12, 2);

    Pfile.open("input.txt");
    LoadFromFile(Pfile, program);
    SetProgram(program, modified_program, code, pos, end);

    // Run Intcode program
    do
    {
        ExecuteStep(modified_program, pos, end);
    } while(!end);

    std::cout << "Solution (part 1): " << modified_program[0] << std::endl;

    return EXIT_SUCCESS;
}
