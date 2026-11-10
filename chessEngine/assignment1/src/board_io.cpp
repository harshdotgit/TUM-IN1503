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

Color getPieceColor(Piece piece) {
  if (piece == Piece::Empty) return Color::None;
  char c{pieceToChar(piece)};
  return std::isupper(static_cast<unsigned char>(c)) ? Color::White : Color::Black;
}

bool isWhitePiece(Piece piece) { return getPieceColor(piece) == Color::White; }

bool isBlackPiece(Piece piece) { return getPieceColor(piece) == Color::Black; }

bool isOpponent(Piece p1, Piece p2) {
  return (isWhitePiece(p1) && isBlackPiece(p2)) || (isBlackPiece(p1) && isWhitePiece(p2));
}

std::string squareToString(Square sq) {
  std::string s;
  s += static_cast<char>('a' + sq.col);
  s += static_cast<char>('8' - sq.row);
  return s;
}

Square stringToSquare(const std::string& str) { return Square{'8' - str[1], str[0] - 'a'}; }

bool isValidSquare(Square sq) { return (sq.row >= 0 && sq.row < 8 && sq.col >= 0 && sq.col < 8); }

void loadFen(Board& board, const std::string& fen) {
  for (auto& r : board) r.fill(Piece::Empty);
  int row{0}, col{0};
  for (char c : fen) {
    if (c == ' ') break;
    if (c == '/') {
      ++row;
      col = 0;
    } else if (c >= '1' && c <= '8') {
      col += c - '0';
    } else if (row < 8 && col < 8) {
      board[row][col] = charToPiece(c);
      ++col;
    }
  }
}

std::string boardToFen(const Board& board) {
  std::stringstream ss;
  int empty{0};
  for (int row{0}; row < 8; ++row) {
    empty = 0;
    for (int col{0}; col < 8; ++col) {
      Piece p = board[row][col];
      if (p == Piece::Empty) {
        ++empty;
        continue;
      }
      if (empty > 0) {
        ss << empty;
        empty = 0;
      }
      ss << pieceToChar(p);
    }
    if (empty > 0) ss << empty;
    if (row < 7) ss << '/';
  }
  return ss.str();
  ;
}
