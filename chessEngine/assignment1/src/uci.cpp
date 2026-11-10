#include "uci.h"
#include <iostream>
#include <sstream>
#include "board_io.h"

Move parseMove(const std::string& moveStr) {
  Move m;
  m.from = stringToSquare(moveStr.substr(0, 2));
  m.to = stringToSquare(moveStr.substr(2, 2));
  m.promotion = (moveStr.size() == 5) ? charToPiece(moveStr[4]) : Piece::Empty;
  return m;
}

std::string moveToString(const Move& move) {
  std::string s{squareToString(move.from) + squareToString(move.to)};
  if (move.promotion != Piece::Empty)
    s += static_cast<char>(std::tolower(static_cast<unsigned char>(pieceToChar(move.promotion))));
  return s;
}

void applyMove(Board& board, const Move& move) {
  Piece moving{board[move.from.row][move.from.col]};
  board[move.from.row][move.from.col] = Piece::Empty;
  if (move.promotion == Piece::Empty) {
    board[move.to.row][move.to.col] = moving;
    return;
  }
  unsigned char c{static_cast<unsigned char>(pieceToChar(move.promotion))};
  char fixed{isWhitePiece(moving) ? static_cast<char>(std::toupper(c)) : static_cast<char>(std::tolower(c))};
  board[move.to.row][move.to.col] = charToPiece(fixed);
}

void handleUciCommand(const std::string& line, Board& board) {
  std::stringstream ss{line};
  std::string cmd;
  if (!(ss >> cmd)) return;

  if (cmd == "uci") {
    std::cout << "id name MyChessEngine\n"
              << "id author YourName\n"
              << "uciok" << std::endl;
  } else if (cmd == "isready") {
    std::cout << "readyok" << std::endl;
  } else if (cmd == "ucinewgame") {
    initBoard(board);
  } else if (cmd == "position") {
    std::string token;
    ss >> token;
    if (token == "startpos") {
      initBoard(board);
      if (!(ss >> token)) token.clear();
    } else if (token == "fen") {
      std::string fenStr;
      token.clear();
      while (ss >> token && token != "moves") {
        if (!fenStr.empty()) fenStr += ' ';
        fenStr += token;
      }
      loadFen(board, fenStr);
    }
    if (token == "moves") {
      std::string mv;
      while (ss >> mv) applyMove(board, parseMove(mv));
    }
  } else if (cmd == "go") {
    std::cout << "bestmove 0000" << std::endl;
  } else if (cmd == "stop") {
    // nothing yet
  } else if (cmd == "d" || cmd == "display") {
    printBoard(board);
  }
}
