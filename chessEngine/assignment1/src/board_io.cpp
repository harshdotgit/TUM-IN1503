#include "board_io.h"
#include <cctype>
#include <iostream>
#include <sstream>

void initBoard(Board& board) {
  for (auto& row : board) row.fill(Piece::Empty);
  std::array<Piece, 8> whiteStart{Piece::WRook, Piece::WKnight, Piece::WBishop, Piece::WQueen,
                                  Piece::WKing, Piece::WBishop, Piece::WKnight, Piece::WRook};
  std::array<Piece, 8> blackStart{Piece::BRook, Piece::BKnight, Piece::BBishop, Piece::BQueen,
                                  Piece::BKing, Piece::BBishop, Piece::BKnight, Piece::BRook};
  board[0] = blackStart;
  board[7] = whiteStart;
  board[1].fill(Piece::BPawn);
  board[6].fill(Piece::WPawn);
}

void printBoard(const Board& board) {
  std::stringstream ss;
  for (int row{0}; row < 8; ++row) {
    ss << (8 - row) << ' ';
    for (int col{0}; col < 8; ++col) ss << PieceUnicode[board[row][col]] << ' ';
    ss << '\n';
  }
  ss << "  a b c d e f g h\n";
  std::cout << ss.str();
}

char pieceToChar(Piece piece) {
  switch (piece) {
    case Piece::WPawn:
      return 'P';
      break;
    case Piece::BPawn:
      return 'p';
      break;
    case Piece::WKnight:
      return 'N';
      break;
    case Piece::BKnight:
      return 'n';
      break;
    case Piece::WBishop:
      return 'B';
      break;
    case Piece::BBishop:
      return 'b';
      break;
    case Piece::WRook:
      return 'R';
      break;
    case Piece::BRook:
      return 'r';
      break;
    case Piece::WQueen:
      return 'Q';
      break;
    case Piece::BQueen:
      return 'q';
      break;
    case Piece::WKing:
      return 'K';
      break;
    case Piece::BKing:
      return 'k';
      break;
    default:
      return '.';
  }
}

Piece charToPiece(char c) {
  switch (c) {
    case 'P':
      return Piece::WPawn;
      break;
    case 'p':
      return Piece::BPawn;
      break;
    case 'N':
      return Piece::WKnight;
      break;
    case 'n':
      return Piece::BKnight;
      break;
    case 'B':
      return Piece::WBishop;
      break;
    case 'b':
      return Piece::BBishop;
      break;
    case 'R':
      return Piece::WRook;
      break;
    case 'r':
      return Piece::BRook;
      break;
    case 'Q':
      return Piece::WQueen;
      break;
    case 'q':
      return Piece::BQueen;
      break;
    case 'K':
      return Piece::WKing;
      break;
    case 'k':
      return Piece::BKing;
      break;
    default:
      return Piece::Empty;
      break;
  }
}

Color getPieceColor(Piece piece) { return Color::None; }

bool isWhitePiece(Piece piece) { return false; }

bool isBlackPiece(Piece piece) { return false; }

bool isOpponent(Piece p1, Piece p2) { return false; }

std::string squareToString(Square sq) { return ""; }

Square stringToSquare(const std::string& str) { return Square{0, 0}; }

bool isValidSquare(Square sq) { return false; }

void loadFen(Board& board, const std::string& fen) {}

std::string boardToFen(const Board& board) { return ""; }
