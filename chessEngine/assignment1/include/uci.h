#pragma once

#include <string>
#include "chess_defs.h"

// --- Moves & UCI Protocol ---
Move parseMove(const std::string& moveStr);
std::string moveToString(const Move& move);
void applyMove(Board& board, const Move& move);

// Process a single UCI command line (e.g. "uci", "isready", "ucinewgame", "position ...", "go ...", "d")
void handleUciCommand(const std::string& line, Board& board);
