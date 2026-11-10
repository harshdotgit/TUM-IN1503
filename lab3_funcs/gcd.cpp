#include <iostream>

// recursive

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int gcd_it(int a, int b) {
  unsigned int r{};
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() { std::cout << gcd_it(4, 6); }
