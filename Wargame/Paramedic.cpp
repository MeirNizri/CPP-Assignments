/**
 * Class for Paramedic in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "Paramedic.hpp"

using namespace std;

Paramedic::Paramedic(uint _player) : Soldier(_player, 100, 0) { }
Paramedic::Paramedic(uint _player, uint _maxHealth, uint _damage) : Soldier(_player, _maxHealth, _damage) { }

bool Paramedic::inRange(const vector<std::vector<Soldier*>>& board, pair<int,int> location) {
	if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size())
		return false;
	return true;
}

void Paramedic::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    for(int i=location.first-1; i<=location.first+1; i++) {
		for(int j=location.second-1; j<=location.second+1; j++) {
			if (inRange(board, {i,j}) && board[i][j] && board[i][j]->getPlayer()==player)
		    	board[i][j]->heal();
        }
    }
}

void Paramedic::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
	baseAction(board, location);
}