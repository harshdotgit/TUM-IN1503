#pragma once

#include <array>
#include <string>
#include <unordered_map>

enum Piece {
  Empty,
  WPawn,
  WKnight,
  WBishop,
  WRook,
  WQueen,
  WKing,
  BPawn,
  BKnight,
  BBishop,
  BRook,
  BQueen,
  BKing
};

enum class Color {
  White,
  Black,
  None
};


// 8x8 Board: board[row][col] where row 0 is Rank 8 and row 7 is Rank 1
using Board = std::array<std::array<Piece, 8>, 8>;

struct Square {
  int row = 0;  // 0..7 (0 = Rank 8, 7 = Rank 1)
  int col = 0;  // 0..7 (0 = File 'a', 7 = File 'h')

  bool operator==(const Square& other) const = default;
};

struct Move {
  Square from;
  Square to;
  Piece promotion = Piece::Empty;

  bool operator==(const Move& other) const = default;
};

inline std::unordered_map<Piece, std::string> PieceUnicode{
    {Piece::Empty, "."},        {Piece::WPawn, "\u2659"},
    {Piece::WKnight, "\u2658"}, {Piece::WBishop, "\u2657"},
    {Piece::WRook, "\u2656"},   {Piece::WQueen, "\u2655"},
    {Piece::WKing, "\u2654"},   {Piece::BPawn, "\u265F"},
    {Piece::BKnight, "\u265E"}, {Piece::BBishop, "\u265D"},
    {Piece::BRook, "\u265C"},   {Piece::BQueen, "\u265B"},
    {Piece::BKing, "\u265A"},
};