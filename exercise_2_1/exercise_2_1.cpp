#include <iostream>
#include <vector>

#include "convolution.h"

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

void printVector(std::vector<double> vec) {
  std::cout << "{";
  for (int i = 0; i < vec.size() - 1; i++) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[vec.size() - 1] << "}" << std::endl;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  std::cout << "x: ";
  printVector(x);

  std::cout << "w: ";
  printVector(w);

  std::vector<double> y = applyConvolution(x, w, pack_with_zeros);

  printVector(y);

  return 0;
}

