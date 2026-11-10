#include <iostream>
#include <string>
#include "board_io.h"
#include "uci.h"

// Don't remove the ARTEMIS_TESTING directive
#ifndef ARTEMIS_TESTING

// You can test everything within the main function.
int main() {
  Board board;
  initBoard(board);

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line == "quit") {
      break;
    }
    handleUciCommand(line, board);
  }

  return 0;
}

#endif
