/// https://adventofcode.com/2019/day/2 (part 1)
/// @author Alberto Santagostino

#include "IntCodeMachine.h"
#include "utils.h"

int main()
{
    std::ifstream Pfile;
    Pfile.open("input.txt");
    bool end{false};

    auto machine = new IntCodeMachine;
    auto code = std::make_pair(12, 2);
    machine->LoadProgramFromFile(Pfile);
    machine->SetProgramNounVerb(code);

    // Run Intcode program
    do
    {
        end = machine->StepProgram();
    } while(!end);

    std::cout << "Solution (part 1): " << machine->GetProgram()[0] << std::endl;

    return EXIT_SUCCESS;
}
