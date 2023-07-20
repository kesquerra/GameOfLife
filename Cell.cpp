#include "Cell.hpp"
#include "numeric"
#include <iostream>

Cell::Cell(int _id) {
    id = _id;
    isAlive = (((rand() & 100)) > 50); // 50% chance to start alive
    nextState = false;
};

bool Cell::getState() const {
    return isAlive;
}

int Cell::getId() const {
    return id;
}

// calculate the next state of the cell and set the nextState field
void Cell::calcNextState() {
    // count all neighbors that are alive
    int aliveAmount = 0;
    for (auto n: neighbors) {
        if (n->getState()) {
            aliveAmount++;
        }
    }
    
    // set the next iteration state according to Conway's rules
    if (isAlive && (aliveAmount == 2 || aliveAmount == 3)) {
        nextState = true;
        return;
    }
    if (!isAlive && (aliveAmount == 3)) {
        nextState = true;
        return;
    }

    nextState = false;
}

// set the cell state to the next iteration
void Cell::updateState() {
    isAlive = nextState;
}

// add a neighbor to the cell's neighbor vector
void Cell::addNeighbor(Cell* cell) {
    neighbors.emplace_back(cell);
}


