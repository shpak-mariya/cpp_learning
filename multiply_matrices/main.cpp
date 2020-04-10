#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<__uint16_t>> matrix_t;
matrix_t *create_matrix(const __uint16_t x, const __uint16_t y) {
  auto matrix = new matrix_t;

  srand(time(NULL));

  for (int i = 0; i < x; ++i) {
    std::vector<__uint16_t> tmp;
    for (int j = 0; j < y; ++j) {
      tmp.push_back(rand() % 10);
    }
    matrix->push_back(tmp);
  }

  return matrix;
}

std::ostream &operator<<(std::ostream &os, const matrix_t &matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      os << matrix[i][j] << " ";
    }
    os << std::endl;
  }

  return os;
}

matrix_t *multiply(const matrix_t &matrix_1, const matrix_t &matrix_2) {
  if (matrix_1.empty()) {
    std::cerr << "1th matrix of the matrices is empty!" << std::endl;
    return nullptr;
  }
  if (matrix_2.empty()) {
    std::cerr << "2th matrix of the matrices is empty!" << std::endl;
    return nullptr;
  }

  if (matrix_1[0].size() != matrix_2.size()) {
    std::cerr << "Cannot multiply matrices - 1th matrix's col count != 2th "
                 "matrix's row count."
              << std::endl;
    return nullptr;
  }

  auto matrix = new matrix_t;

  for (int i = 0; i < matrix_1.size(); ++i) {
    std::vector<__uint16_t> tmp;
    for (int j = 0; j < matrix_2[0].size(); ++j) {
      int m = 0;
      for (int k = 0; k < matrix_1[0].size(); ++k) {
        m += (matrix_1[i][k] * matrix_2[k][j]);
      }
      tmp.push_back(m);
    }
    matrix->push_back(tmp);
  }

  return matrix;
}

int main() {
  const __uint16_t x_1 = 3;
  const __uint16_t x_2 = 4;
  const __uint16_t y_1 = 4;
  const __uint16_t y_2 = 2;

  matrix_t *matrix_1 = create_matrix(x_1, y_1);
  matrix_t *matrix_2 = create_matrix(x_2, y_2);

  std::cout << "matrix_1: " << std::endl << *matrix_1;
  std::cout << "matrix_2: " << std::endl << *matrix_2;

  matrix_t *matrix = multiply(*matrix_1, *matrix_2);

  if (matrix != nullptr) {
    std::cout << "matrix: " << std::endl << *matrix;
  }

  return 0;
}
