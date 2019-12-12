/// @file IntCodeMachine.h
/// @class IntCodeMachine

#ifndef INTCODEMACHINE_H
#define INTCODEMACHINE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class IntCodeMachine {
public:
  IntCodeMachine();
  IntCodeMachine(std::vector<int> &vec) {
    program_ = vec;
    pos_ = 0;
  }

  inline void SetProgram(std::vector<int> &vec) {
    program_ = vec;
    pos_ = 0;
  }
  inline std::vector<int> GetProgram() { return program_; }

  void LoadProgramFromFile(std::ifstream &file);
  bool StepProgram();
  void SetProgramNounVerb(std::pair<int, int> &nounverb);

private:
  std::vector<int> program_;
  std::size_t pos_;
  int Compute(int opcode, int in1, int in2);
};

#endif // INTCODEMACHINE_H
