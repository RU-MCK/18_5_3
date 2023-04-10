#include <iostream>
#include <limits>
bool checkError() {
  if (std::cin.fail() || std::cin.peek() != '\n') {
    std::cerr << "Enter Error!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  } else
    return true;
}

int numberOfWays(int n, int k = 3) {
  static int _k = k;
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;
  return numberOfWays(n - _k) + numberOfWays(n - 1);
}

int main() {
  std::cout << "Input number of steps: " << std::endl;
  int n;
  std::cin >> n;
  if (checkError())
    std::cout << "Input the maximum jump length: " << std::endl;
  int k;
  std::cin >> k;
  if (checkError())
    std::cout << numberOfWays(n, k);
}
