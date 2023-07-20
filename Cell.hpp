#ifndef CELL_HPP
#define CELL_HPP

#include <vector>

class Cell {
    private:
        int id;
        bool isAlive;
        bool nextState;
        std::vector<Cell*> neighbors;
    public:
        Cell(int _id);
        bool getState() const;
        void calcNextState();
        void addNeighbor(Cell* cell);
        void updateState();
        int getId() const;
        
};

#endif