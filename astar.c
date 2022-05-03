#include <stdio.h>
#include "map.h"
#include "grid.h"
#include "node.h"

Node grid[13][13];

Node *open[13][13], *closed[13][13];
Map current, target;

void init(int start, int end) {
    current = (Map){.row = getStationValue(start,0), .col = getStationValue(start,1)};
    target = (Map){.row = getStationValue(end, 0), .col = getStationValue(end, 1)};

    open[current.row][current.col] = &grid[current.row][current.col];
}

void calculatePath() {
    int i,j;
    while (!isMapEqual(current, target)) {
        current = getLowestFcost().pos;
        if(open[current.row][current.col]){
            open[current.row][current.col] = NULL;
            closed[current.row][current.col] = &grid[current.row][current.col];
            
            if(current.row > 1 && current.col > 1 && current.row < 13 && current.col < 13) {
                if (grid[current.row+1][current.col].traversable == 0 && closed[current.row+1][current.col] == NULL) {
                    if(!(open[current.row+1][current.col] == NULL)) {
                        grid[current.row+1][current.col].hcost = (current.row+1 + current.col) - (target.col + target.row);
                        grid[current.row+1][current.col].parent = &grid[current.row][current.col];
                        
                    }
                }
            }
        }
    }
}

Node getLowestFcost() {
    int i,j;
    Node current;
    current = grid[0][0];
    for(i = 0; i < 13; i++){
        for(j = 0; j < 13; j++) {
            if(grid[i][j].fcost && grid[i][j].fcost < current.fcost) {
                current = grid[i][j];
            }
        }
    }
    return current;
}

/* 
    Imports values from grid.c and stores them locally in grid[][]
*/
void importGrid() {
    int i,j;

    for(i = 0; i < 13; i++) {
        for(j = 0; j < 13; j++) {
            grid[i][j].traversable = getGrid(i,j);
            grid[i][j].pos.row = i;
            grid[i][j].pos.col = j;
        }
    }
}