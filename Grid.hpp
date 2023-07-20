#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Cell.hpp"

class Grid {
    private:
        std::vector<std::vector<Cell>> cells;
    public:
        Grid();
        void display() const;
        void addNeighbors();
        void nextState();
        std::vector<std::vector<int>> getCoords(int x, int y) const;
};

#endif