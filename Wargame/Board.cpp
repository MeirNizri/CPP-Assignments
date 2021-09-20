/**
 * class for board of the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "Board.hpp"
#include <stdexcept>

using namespace std;
using namespace WarGame;

Soldier*& Board::operator[](std::pair<int,int> location) {
	if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size())
		throw std::invalid_argument("There is no such destination in the board");
	return board[location.first][location.second];
}
Soldier* Board::operator[](std::pair<int,int> location) const {
	if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size())
		throw std::invalid_argument("There is no such destination in the board");
	return board[location.first][location.second];
}

void Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
    // Check the source is illegal
    Soldier* soldier = (*this)[source];
    if(soldier==nullptr || soldier->getPlayer()!=player_number)
        throw std::invalid_argument("There is no soldier of this player in that location");
    // Check the destination is illegal
    pair<int,int> dest (source.first, source.second);
    switch(direction) {
		case Up:    dest.first++;  break;
		case Down:  dest.first--;  break;
		case Right: dest.second++; break;
		default:    dest.second--;
	}
	if(dest.first<0 || dest.first>=board.size() || dest.second<0 || dest.second>=board[0].size())
		throw std::invalid_argument("There is no such destination in the board");
	if((*this)[dest] != nullptr){
		throw std::invalid_argument("That destination is already taken by another soldier");
	}
	// Move and activate the soldier
	(*this)[dest] = soldier;
	(*this)[source] = nullptr;
	soldier->fullAction(board, dest);
}

bool Board::has_soldiers(uint player_number) const {
	for(int i=0; i<board.size(); i++) {
		for(int j=0; j<board[0].size(); j++) {
			if(board[i][j] && board[i][j]->getPlayer()==player_number)
			 return true;
		}
	}
	return false;
}