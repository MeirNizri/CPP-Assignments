/**
 * Class for ParamedicCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#include "ParamedicCommander.hpp"

using namespace std;

ParamedicCommander::ParamedicCommander(int _player) : Paramedic(_player, 200, 0) { }
    
void ParamedicCommander::baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Paramedic::baseAction(board, location);
}

void ParamedicCommander::fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) {
    Soldier* soldier = nullptr;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if (board[i][j] && board[i][j]->getPlayer()==player) {
                soldier = board[i][j];
                if (dynamic_cast<Paramedic*>(soldier)) 
                    soldier->baseAction(board, {i,j});
            }
        }
    }
}