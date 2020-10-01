#pragma once

class NumberConverter {
public:

  NumberConverter(int decimalInputs, int binInputs, int hexInputs, int decimalOutputs, int binOutputs, int hexOutputs);
  ~NumberConverter();

  int hexStringToDecimal(std::string hexString);

  int binaryStringToDecimal(std::string binString);

  std::string decimalToHexString(int num);

  std::string binaryStringToHexString(std::string binString);

  std::string decimalToBinString(int num);

  std::string hexStringToBinString(std::string hexString);

private:

  int mDecimalInputs;
  int mBinInputs;
  int mHexInputs;

  int mDecimalOutputs;
  int mBinOutputs;
  int mHexOutputs;

  int hexCharToNumber(char input);

  char numberToHexChar(int input);

};
