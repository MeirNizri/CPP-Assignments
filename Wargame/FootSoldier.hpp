/**
 * Class for FootSoldier in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "Soldier.hpp"
#include <bits/stdc++.h> 

using namespace std;

class FootSoldier: public Soldier {
public:
    /** Constructors */
    FootSoldier(uint _player);
    FootSoldier(uint _player, uint _maxHealth, uint _damage);
    
    /** Function to calculate distance */
    float findDistance(int x1, int y1, int x2, int y2) { 
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
    } 
    
    /** Attack closest enemy soldier */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};