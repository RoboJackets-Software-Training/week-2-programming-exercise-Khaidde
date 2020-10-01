#include <string>
#include <algorithm>
#include <iostream>

#include "NumberConverter.h"

/*decimal_inputs: 1
binary_inputs: 2
hex_inputs: 4
decimal_outputs: 5
binary_outputs: 5
hex_outputs: 6
*/
NumberConverter::NumberConverter(int decimalInputs, int binInputs, int hexInputs, int decimalOutputs, int binOutputs, int hexOutputs) {
	mDecimalInputs = decimalInputs;
	mBinInputs = binInputs;
	mHexInputs = hexInputs;

	mDecimalOutputs = decimalOutputs;
	mBinOutputs = binOutputs;
	mHexOutputs = hexOutputs;
}

NumberConverter::~NumberConverter() {
  std::cout << "decimal_inputs: " << mDecimalInputs << std::endl;
  std::cout << "binary_inputs: " << mBinInputs << std::endl;
  std::cout << "hex_inputs: " << mHexInputs << std::endl;

  std::cout << "decimal_outputs: " << mDecimalOutputs<< std::endl;
  std::cout << "binary_outputs: " << mBinOutputs << std::endl;
  std::cout << "hex_outputs: " << mHexOutputs << std::endl;
}

int NumberConverter::hexStringToDecimal(std::string hexString) {
  mHexInputs++;
  mDecimalOutputs++;

  std::reverse(hexString.begin(), hexString.end());

  int decimal = 0;
  for (int i = 0; i < hexString.length(); i++) {
  	int placeValue = 1 << (4 * i);
  	decimal += hexCharToNumber(hexString[i]) * placeValue;
  }
  return decimal;
}

int NumberConverter::binaryStringToDecimal(std::string binString) {
  mBinInputs++;
  mDecimalOutputs++;

  std::reverse(binString.begin(), binString.end());

  int decimal = 0;
  for (int i = 0; i < binString.length(); i++) {
   	char binDigit = binString[i];
  	if (binDigit == 49) {
  	  decimal += 1 << i;
  	}
  }
  return decimal;
}

std::string NumberConverter::decimalToHexString(int num) {
  mDecimalInputs++;
  mHexOutputs++;

  std::string hexString;
  int value = num;
  while (value != 0) {
  	hexString += numberToHexChar(value % 16);
  	value /= 16;
  }
  std::reverse(hexString.begin(), hexString.end());
  return hexString;
}

std::string NumberConverter::binaryStringToHexString(std::string binString) {
  mBinInputs++;
  mHexOutputs++;

  std::string hexString;
  for (int i = binString.length() - 1; i >= 0; i -= 4) {
  	std::string binSub = binString.substr(std::max(0, i - 3), std::min(4, i + 1));
  	int num = 0;
  	for (int b = 0; b < 4; b++) {
  		if (binSub[3 - b] == 49) {
  			num += (1 << b);
  		}
  	}
  	hexString += numberToHexChar(num);
  }
  std::reverse(hexString.begin(), hexString.end());
  return hexString;
}


std::string NumberConverter::decimalToBinString(int num) {
  mDecimalInputs++;
  mBinOutputs++;

  std::string binString;
  int value = num;
  while (value != 0) {
  	binString += std::to_string(value % 2);
  	value /= 2;
  }
  std::reverse(binString.begin(), binString.end());
  return binString;
}

std::string NumberConverter::hexStringToBinString(std::string hexString) {
  mHexInputs++;
  mBinOutputs++;

  std::string binString;
  for (int i = 0; i < hexString.length(); i++) {
  	std::string binSection;
  	int num = hexCharToNumber(hexString[i]);
  	while (num != 0) {
  		binSection += std::to_string(num % 2);
  		num /= 2;
  	}
  	std::reverse(binSection.begin(), binSection.end());

  	int binSectionLen = binSection.length();
  	for (int b = 0; b < 4 - binSectionLen; b++) {
  		binSection = "0" + binSection;
  	}
  	binString += binSection;
  }
  return binString;
}

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}