#pragma once

#include <string>
#include "chess_defs.h"

// --- Part 1: Board Setup & Output ---
void initBoard(Board& board);
void printBoard(const Board& board);

// --- Part 2: Coordinates & Piece Conversions ---
char pieceToChar(Piece piece);
Piece charToPiece(char c);

Color getPieceColor(Piece piece);
bool isWhitePiece(Piece piece);
bool isBlackPiece(Piece piece);
bool isOpponent(Piece p1, Piece p2);

std::string squareToString(Square sq);
Square stringToSquare(const std::string& str);
bool isValidSquare(Square sq);

// --- Part 3: FEN Import & Export ---
void loadFen(Board& board, const std::string& fen);
std::string boardToFen(const Board& board);
