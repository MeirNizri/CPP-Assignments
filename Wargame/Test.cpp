/**
 * Unit tests for WarGame
 * 
 * Author: Meir Nizri
 * Fourth assignment in cpp course
 * Date: 2020-05
 */
 
#include "doctest.h"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
#include "Board.hpp"

using namespace std;
using namespace WarGame;

Board game1(8, 8);
Board game2(8, 8);

TEST_CASE("Invalid moves") {
    game1[{0,0}] = new FootSoldier(1);
    game1[{0,1}] = new FootCommander(1);
    game1[{0,2}] = new Sniper(1);
    game1[{1,1}] = new SniperCommander(1);
    game1[{0,4}] = new Paramedic(1);
    game1[{0,5}] = new ParamedicCommander(1);
    game1[{7,7}] = new FootSoldier(2);
    game1[{7,6}] = new FootCommander(2);
    game1[{7,5}] = new Sniper(2);
    game1[{6,6}] = new SniperCommander(2);
    game1[{7,0}] = new Paramedic(2);
    game1[{7,1}] = new ParamedicCommander(2);
    
    CHECK_THROWS(game1.move(1, {0,0}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(1, {0,0}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(1, {0,0}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,2}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(1, {0,2}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,1}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(1, {0,1}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,1}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(1, {0,1}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(1, {1,1}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,4}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,4}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(1, {0,5}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(1, {0,5}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(2, {7,5}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(2, {7,5}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {7,7}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(2, {7,7}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(2, {7,7}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {6,6}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {7,6}, Board::MoveDIR::Down));
    CHECK_THROWS(game1.move(2, {7,6}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {7,6}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(2, {7,6}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(2, {7,0}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {7,0}, Board::MoveDIR::Left));
    CHECK_THROWS(game1.move(2, {7,0}, Board::MoveDIR::Right));
    CHECK_THROWS(game1.move(2, {7,1}, Board::MoveDIR::Up));
    CHECK_THROWS(game1.move(2, {7,1}, Board::MoveDIR::Left));
}

TEST_CASE("Soldier moves") {
    CHECK(game1[{1,1}]);
    CHECK(game1[{0,2}]);
    CHECK(game1[{0,1}]);
    CHECK(game1[{0,0}]);
    CHECK(game1[{0,4}]);
    CHECK(game1[{0,5}]);
    CHECK(game1[{6,6}]);
    CHECK(game1[{7,7}]);
    CHECK(game1[{7,6}]);
    CHECK(game1[{7,5}]);
    CHECK(game1[{7,0}]);
    CHECK(game1[{7,1}]);
    
    game1.move(1, {1,1}, Board::MoveDIR::Up);
    game1.move(2, {7,0}, Board::MoveDIR::Down);
    game1.move(2, {7,1}, Board::MoveDIR::Down);
    game1.move(1, {0,2}, Board::MoveDIR::Right);
    game1.move(1, {0,1}, Board::MoveDIR::Up);
    game1.move(1, {0,0}, Board::MoveDIR::Right);
    game1.move(2, {6,6}, Board::MoveDIR::Down);
    game1.move(1, {0,4}, Board::MoveDIR::Up);
    game1.move(1, {0,5}, Board::MoveDIR::Right);
    game1.move(2, {7,7}, Board::MoveDIR::Down);
    game1.move(2, {7,5}, Board::MoveDIR::Left);
    game1.move(2, {7,6}, Board::MoveDIR::Left);
    game1.move(2, {7,5}, Board::MoveDIR::Down);

    CHECK(game1[{2,1}]);
    CHECK(game1[{0,3}]);
    CHECK(game1[{1,1}]);
    CHECK(game1[{0,1}]);
    CHECK(game1[{1,4}]);
    CHECK(game1[{0,6}]);
    CHECK(game1[{6,7}]);
    CHECK(game1[{7,4}]);
    CHECK(game1[{6,5}]);
    CHECK(game1[{5,6}]);
    CHECK(game1[{6,0}]);
    CHECK(game1[{6,1}]);
    CHECK(game1[{0,2}] == nullptr);
    CHECK(game1[{0,0}] == nullptr);
    CHECK(game1[{1,0}] == nullptr);
    CHECK(game1[{1,2}] == nullptr);
    CHECK(game1[{6,6}] == nullptr);
    CHECK(game1[{7,7}] == nullptr);
    CHECK(game1[{7,6}] == nullptr);
    CHECK(game1[{7,5}] == nullptr);
    CHECK(game1[{7,3}] == nullptr);
    CHECK(game1[{6,4}] == nullptr);
    CHECK(game1[{5,7}] == nullptr);
}

TEST_CASE("Soldiers action") {
    game2[{1,0}] = new FootSoldier(1);
    game2[{0,0}] = new FootCommander(1);
    game2[{1,2}] = new Sniper(1);
    game2[{0,2}] = new SniperCommander(1);
    game2[{1,1}] = new Paramedic(1);
    game2[{0,1}] = new ParamedicCommander(1);
    game2[{6,6}] = new Paramedic(2);
    game2[{7,6}] = new ParamedicCommander(2);
    
    game2.move(1, {1,0}, Board::MoveDIR::Up); // footsoldier shot paramedic
    CHECK(game2[{6,6}]->getHealth()==90);
    CHECK(game2[{7,6}]->getHealth()==200); 
    game2.move(2, {6,6}, Board::MoveDIR::Down); // paramedic healed
    CHECK(game2[{5,6}]->getHealth()==100);
    CHECK(game2[{7,6}]->getHealth()==200);
    
    game2.move(1, {1,2}, Board::MoveDIR::Up); // sniper shot paramediccommander
    CHECK(game2[{7,6}]->getHealth()==150);
    CHECK(game2[{5,6}]->getHealth()==100);
    game2.move(2, {7,6}, Board::MoveDIR::Down); // paramedicCommander healed
    CHECK(game2[{6,6}]->getHealth()==200);
    CHECK(game2[{5,6}]->getHealth()==100);
    
    game2.move(1, {0,0}, Board::MoveDIR::Up); // footsoldier and footCommander shot paramedic
    CHECK(game2[{6,6}]->getHealth()==200); 
    CHECK(game2[{5,6}]->getHealth()==70);
    game2.move(2, {5,6}, Board::MoveDIR::Down); // paramedic healed
    CHECK(game2[{6,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==100);
    
    game2.move(1, {0,2}, Board::MoveDIR::Up); // snipercommander shot paramediccommander and sniper shot paramedic
    CHECK(game2[{6,6}]->getHealth()==100); 
    CHECK(game2[{4,6}]->getHealth()==50);
    game2.move(2, {6,6}, Board::MoveDIR::Down); // paramediccommander healed
    CHECK(game2[{5,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==100);
    
    // team 1 not hurt
    CHECK(game2[{1,0}]->getHealth()==150); 
    CHECK(game2[{2,0}]->getHealth()==100);
    CHECK(game2[{0,1}]->getHealth()==200); 
    CHECK(game2[{1,1}]->getHealth()==100);
    CHECK(game2[{1,2}]->getHealth()==120); 
    CHECK(game2[{2,2}]->getHealth()==100);

    game2.move(1, {2,0}, Board::MoveDIR::Up); // footsoldier shot paramedic
    CHECK(game2[{5,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==90);
    game2.move(1, {1,0}, Board::MoveDIR::Up); // footsoldier and footCommander shot paramedic
    CHECK(game2[{5,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==60);
    game2.move(1, {3,0}, Board::MoveDIR::Up); // footsoldier shot paramedic
    CHECK(game2[{5,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==50);
    game2.move(1, {2,0}, Board::MoveDIR::Up); // footsoldier and footCommander shot paramedic
    CHECK(game2[{5,6}]->getHealth()==200); 
    CHECK(game2[{4,6}]->getHealth()==20);
    game2.move(1, {2,2}, Board::MoveDIR::Up); // sniper shot paramediccommander
    CHECK(game2[{5,6}]->getHealth()==150); 
    CHECK(game2[{4,6}]->getHealth()==20);
    game2.move(1, {1,2}, Board::MoveDIR::Up); // snipercommander and sniper shot paramediccommander
    CHECK(game2[{5,6}] == nullptr);
    CHECK(game2[{4,6}]->getHealth()==20);
    game2.move(1, {3,0}, Board::MoveDIR::Right); // footsoldier and footCommander shot paramedic
    CHECK(game2[{5,6}] == nullptr);
    CHECK(game2[{4,6}] == nullptr);
    
    // team 2 lost
    CHECK(game2.has_soldiers(1));
    CHECK(!game2.has_soldiers(2));
}