/**
 * Class for ParamedicCommander in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */

#pragma once
#include "Paramedic.hpp"

using namespace std;

class ParamedicCommander: public Paramedic {
public:
    /** Constructors  */
    ParamedicCommander(int _player);
    
    /** Activate all paramedics */
    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location);
};