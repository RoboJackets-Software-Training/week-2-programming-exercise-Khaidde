#include <vector>

#include "convolution.h"

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
  std::vector<double> y;

  int w_offset = (w.size() - 1) / 2; //round down if w.size is even
  double sum, x_val;
  int x_index;
  for (int i = 0; i < x.size(); i++) {
    sum = 0;
    for (int j = 0; j < w.size(); j++) {
      x_index = i + j - w_offset;

      //Deal with missing data
      if (x_index < 0 || x_index >= x.size()) {
        if (pack_with_zeros) {
          x_val = 0;
        } else {
          x_val = x[x_index - w_offset * ((0 < x_index) - (x_index < 0))];
        }
      } else {
        x_val = x[x_index];
      }
      sum += w[j] * x_val;
    }
    y.push_back(sum);
  }

  return y;
}