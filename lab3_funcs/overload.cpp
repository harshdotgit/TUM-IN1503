#include <assert>
#include <iostream>
#include <vector>

std::vector<double> operator*(const std::vector<std::vector<double>> &Matrix,
                              const std::vector<double> &vec) {
  std::vector<double> result(Matrix.size());
  for (size_t i{0}; i < Matrix.size(); ++i) {
    double sum{0.0};
    for (size_t j{0}; j < vec.size(); ++j) {
      sum += Matrix[i][j] * vec[j];
    }
    result[i] = sum;
  }
  return result;
}

std::vector<int> operator*(const std::vector<std::vector<int>> &Matrix,
                           const std::vector<int> &vec) {
  std::vector<int> result(Matrix.size());
  for (size_t i{0}; i < Matrix.size(); ++i) {
    int sum{0};
    for (size_t j{0}; j < vec.size(); ++j) {
      sum += Matrix[i][j] * vec[j];
    }
    result[i] = sum;
  }
  return result;
}
void printVec(const std::vector<double> &vec) {
  std::cout << "{ ";
  for (auto &v : vec)
    std::cout << v << " ";
  std::cout << '}';
}

void printVec(const std::vector<int> &vec) {
  std::cout << "{ ";
  for (auto &v : vec)
    std::cout << v << " ";
  std::cout << '}';
}

bool test_matrix_vector_product() {
  // test1
  std::vector<std::vector<int>> testM{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::vector<int> testV{1, 2, 3};
  if (testM * testV != std::vector<int>{1, 2, 3})
    return false;

  return true;
}

int main() {

  std::vector<std::vector<int>> testM{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::vector<int> testV{1, 2, 3};
  printVec(testM * testV);
}
