/**
 * Class for FootSoldier in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "FootSoldier.hpp"
#include <float.h>

using namespace std;

FootSoldier::FootSoldier(uint _player) : Soldier(_player, 100, 10) { }
FootSoldier::FootSoldier(uint _player, uint _maxHealth, uint _damage) : Soldier(_player, _maxHealth, _damage) { }

void FootSoldier::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Soldier* soldier = nullptr;
    pair<int,int> dest;
    float minDistance = FLT_MAX;
    for(int i=0; i<board.size(); i++) {
		for(int j=0; j<board[0].size(); j++) {
	        if (board[i][j] && board[i][j]->getPlayer()!=player) {
	            float distance = findDistance(location.first, location.second, i, j);
	            if (distance!=0 && minDistance>distance) {
	                soldier = board[i][j];
	                dest.first = i; dest.second = j;
	                minDistance = distance;
	            }
	        }
        }
    }
	if(soldier) {
		soldier->hit(damage);
		if (soldier->getHealth() <= 0) {
			delete soldier;
			board[dest.first][dest.second] = nullptr;
		}
	}
}

void FootSoldier::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
	baseAction(board, location);
}