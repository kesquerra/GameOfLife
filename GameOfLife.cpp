#include "Grid.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int ITERATIONS = 5000;


const std::string CLRSCRN = "\033[2J\033[1;1H"; // clear screen string

int main() {
    srand(time(nullptr)); // set random seed

    Grid g = Grid(); // create grid

    // initial display
    std::cout << CLRSCRN;
    g.display();

    // perform each state update and show results
    for (int i=0; i<ITERATIONS; i++) {
        g.nextState();
        g.display();
        usleep(200000);
        std::cout << CLRSCRN;
    }
    
}