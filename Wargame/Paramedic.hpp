/**
 * Class for Paramedic in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "Soldier.hpp"

using namespace std;

class Paramedic: public Soldier {
public:
    /** Constructors  */
    Paramedic(uint _player);
    Paramedic(uint _player, uint _maxHealth, uint _damage);
    
    /** Check illegal range in 2D vector  */
    bool inRange(const vector<std::vector<Soldier*>>& board, pair<int,int> location);

    /** Heal all soldiers close to him  */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};