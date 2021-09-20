/**
 * Class for sniper in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "Soldier.hpp"

using namespace std;

class Sniper: public Soldier {
public:
    /** Constructors  */
    Sniper(uint _player);
    Sniper(uint _player, uint _maxHealth, uint _damage);

    /** Attack the enemy soldier with largest HP */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};