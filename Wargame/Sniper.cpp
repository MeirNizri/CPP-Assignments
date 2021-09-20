/**
 * Class for FootSoldier in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "Sniper.hpp"

using namespace std;

Sniper::Sniper(uint _player) : Soldier(_player, 100, 50) { }
Sniper::Sniper(uint _player, uint _maxHealth, uint _damage) : Soldier(_player, _maxHealth, _damage) { }

void Sniper::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Soldier* soldier = nullptr;
    pair<int,int> dest;
    int maxHP = 0;
    for(int i=0; i<board.size(); i++) {
		for(int j=0; j<board[0].size(); j++) {
	        if (board[i][j] && board[i][j]->getPlayer()!=player && board[i][j]->getHealth()>maxHP) {
	                soldier = board[i][j];
	                maxHP = soldier->getHealth();
	                dest.first = i; dest.second = j;
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

void Sniper::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
	baseAction(board, location);
}