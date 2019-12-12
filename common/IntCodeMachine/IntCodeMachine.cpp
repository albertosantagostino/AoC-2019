/// @file IntCodeMachine.cpp
/// @class IntCodeMachine

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "IntCodeMachine.h"
#include "utils.h"

IntCodeMachine::IntCodeMachine() { program_ = {}; }

void IntCodeMachine::LoadProgramFromFile(std::ifstream &file) {
  std::string str;
  while (getline(file, str)) {
    std::stringstream ss(str);
    for (int i; ss >> i;) {
      program_.push_back(i);
      if (ss.peek() == ',')
        ss.ignore();
    }
  }
}
bool IntCodeMachine::StepProgram() {

  if (program_[pos_] == utils::EOP) {
    return true;
  }
  int in1 = program_[std::size_t(program_[pos_ + 1])];
  int in2 = program_[std::size_t(program_[pos_ + 2])];
  program_[std::size_t(program_[pos_ + 3])] =
      IntCodeMachine::Compute(program_[pos_], in1, in2);
  pos_ += 4;
  return false;
}

inline int IntCodeMachine::Compute(int opcode, int in1, int in2) {
  switch (opcode) {
  case (1):
    return in1 + in2;
  case (2):
    return in1 * in2;
  }
}

void IntCodeMachine::SetProgramNounVerb(std::pair<int, int> &nounverb) {
  program_[1] = nounverb.first;
  program_[2] = nounverb.second;
}
