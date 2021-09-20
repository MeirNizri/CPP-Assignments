/**
 * Class for FootCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "FootSoldier.hpp"

using namespace std;

class FootCommander: public FootSoldier {
public:
    /** Constructors */
    FootCommander(int _player);
    
    /** Activate all FootSoldiers */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};