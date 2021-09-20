/**
 * Abstract class for Soldier in the war game.
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */
 
#pragma once
#include <iostream>
#include <vector>
#include <sys/param.h>

using namespace std;

class Soldier {
protected:
    uint player;
    uint maxHealth;
    uint damage;
    int health;

public:
    Soldier(uint _player, uint _maxHealth, uint _damage) : 
        player(_player), maxHealth(_maxHealth), damage(_damage), health(_maxHealth) { }

    uint getPlayer() {
        return player;
    }
    int getHealth() {
        return health;
    }
    void hit(int _damage) {
        health -= _damage;
    }
    void heal() {
        health = maxHealth;
    }

    virtual void baseAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) = 0;
    virtual void fullAction(vector<std::vector<Soldier*>>& board, pair<int,int> location) = 0;
    virtual ~Soldier() {}
};