#include "Grid.hpp"
#include <iostream>
#include <algorithm>

const int GRID_SIZE = 256;  // grid size to be processed
const int VIEW_SIZE = 128;  // grid size to be shown in console

Grid::Grid() {
    // generate a 2d vector filled with cells according to the grid size
    for (int i=0; i<GRID_SIZE; i++) {
        cells.emplace_back(std::vector<Cell>());
        for (int j=0; j<GRID_SIZE; j++) {
            cells[i].emplace_back(Cell(i*GRID_SIZE+j));
        }
    }
    addNeighbors(); // add all cell's neighbors to each cell
};

// generates coordinates for each cell's neighbors according to grid size
// with care to the borders
std::vector<std::vector<int>> Grid::getCoords(int x, int y) const{
    std::vector<std::vector<int>> coords {
                {-1, -1}, {-1, 0}, {-1, 1}, 
                {0, -1}, {0, 1},
                {1, -1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<int>> results;
    for (std::vector<int> coord : coords) {
        int nx = coord[0] + x;
        if (nx >= 0 && nx < GRID_SIZE) {
            int ny = coord[1] + y;
            if (ny >= 0 && ny < GRID_SIZE) {
                results.push_back({nx, ny});
            }
        }
    }
    return results;
}

// add all cell's neighbors to each cell
void Grid::addNeighbors() {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            std::vector<std::vector<int>> coords = getCoords(i, j);
            for (std::vector<int> coord : coords) {
                cells[i][j].addNeighbor(&cells[coord[0]][coord[1]]);
            }
        }
    }
};

// calculate the next state of each cell in one pass
// update the state in the next pass
void Grid::nextState() {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            cells[i][j].calcNextState();
        }
    }
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            cells[i][j].updateState();
        }
    }
}

// simple ascii display:
// "a" -> alive
// "." -> dead
void Grid::display() const {
    int idx = (GRID_SIZE - VIEW_SIZE) / 2;
    for (int i=idx; i<VIEW_SIZE; i++) {
        for (int j=idx; j<VIEW_SIZE; j++) {
            if (cells[i][j].getState()) {
                std::cout << "a ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}