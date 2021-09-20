/**
 * Class for SniperCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "Sniper.hpp"

using namespace std;

class SniperCommander: public Sniper {
public:
    /** Constructors  */
    SniperCommander(int _player);
    
    /** Activate all other snipers  */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
   virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};