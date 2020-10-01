#include <iostream>
#include <vector>

#include "NumberConverter.h"

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

int main() {
  std::string converterInfoStr;
  std::cin >> converterInfoStr;
  std::vector converterInfo = readInVector(converterInfoStr);

  std::string outType;
  std::string value;
  std::string result;

  std::cin >> outType;
  std::cin >> value;

  NumberConverter numConverter(converterInfo[0], converterInfo[1], converterInfo[2], converterInfo[3], converterInfo[4], converterInfo[5]);
  switch (value[0]) {
  case '0':
    value = value.substr(2, value.length() - 2);
    if (outType == "b") {
      result = numConverter.hexStringToBinString(value);
    } else if (outType == "d") {
      result = std::to_string(numConverter.hexStringToDecimal(value));
    }
    break;
  case 'b':
    value = value.substr(1, value.length() - 1);
    if (outType == "d") {
      result = std::to_string(numConverter.binaryStringToDecimal(value));
    } else if (outType == "h") {
      result = numConverter.binaryStringToHexString(value);
    }
    break;
  default:
    if (outType == "b") {
      result = numConverter.decimalToBinString(std::stoi(value));
    } else if (outType == "h") {
      result = numConverter.decimalToHexString(std::stoi(value));
    }
    break;
  }

  std::cout << "input: " << value << std::endl;
  std::cout << "output type: " << outType << std::endl;

  std::cout << "result: " << result << std::endl;
}
