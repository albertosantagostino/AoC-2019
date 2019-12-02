/// @file TracksMap.h
/// @class TracksMap

#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline void LoadFromFile(std::ifstream& file, std::vector<int>& vec)
{
    std::string str;
    while(getline(file, str))
    {
        std::stringstream ss(str);
        for(int i; ss >> i;)
        {
            vec.push_back(i);
            if(ss.peek() == ',') ss.ignore();
        }
    }
}

inline int Compute(int opcode, int in1, int in2)
{
    switch(opcode)
    {
        case(1):
            return in1 + in2;
        case(2):
            return in1 * in2;
    }
}

inline void SetProgram(const std::vector<int>& program,
                       std::vector<int>& new_program,
                       std::pair<int, int>& nounverb,
                       std::size_t& pos,
                       bool& end)
{
    pos = 0;
    end = false;
    new_program = program;
    new_program[1] = nounverb.first;
    new_program[2] = nounverb.second;
}

inline void ExecuteStep(std::vector<int>& vec, std::size_t& pos, bool& endofprogram)
{
    if(vec[pos] == 99)
    {
        endofprogram = true;
        return;
    }
    int in1 = vec[std::size_t(vec[pos + 1])];
    int in2 = vec[std::size_t(vec[pos + 2])];
    vec[std::size_t(vec[pos + 3])] = Compute(vec[pos], in1, in2);
    pos += 4;
}

#endif  // UTILS_H
