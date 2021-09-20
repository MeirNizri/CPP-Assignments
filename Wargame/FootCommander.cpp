/**
 * Class for FootCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "FootCommander.hpp"

using namespace std;

FootCommander::FootCommander(int _player) : FootSoldier(_player, 150, 20) { }
    
void FootCommander::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    FootSoldier::baseAction(board, location);
}

void FootCommander::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Soldier* soldier = nullptr;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if (board[i][j] && board[i][j]->getPlayer()==player) {
                soldier = board[i][j];
                if (dynamic_cast<FootSoldier*>(soldier)) 
                    soldier->baseAction(board, {i,j});
            }
        }
    }
}