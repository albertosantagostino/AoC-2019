/// @file IntCodeMachine.h
/// @class IntCodeMachine

#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace utils {

inline std::string PrintVector(std::vector<int> const &input) {
  std::ostringstream oss;
  for (auto const &i : input) {
    oss << i << " ";
  }
  return oss.str();
}

const uint8_t EOP = 99;

} // namespace utils

#endif // UTILS_H
