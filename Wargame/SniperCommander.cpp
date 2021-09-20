/**
 * Class for SniperCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "SniperCommander.hpp"

using namespace std;

SniperCommander::SniperCommander(int _player) : Sniper(_player, 120, 100) { }
    
void SniperCommander::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Sniper::baseAction(board, location);
}

void SniperCommander::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Soldier* soldier = nullptr;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if (board[i][j] && board[i][j]->getPlayer()==player) {
                soldier = board[i][j];
                if (dynamic_cast<Sniper*>(soldier)) 
                    soldier->baseAction(board, {i,j});
            }
        }
    }
}