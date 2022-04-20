#include <stdio.h>
#include "map.h"

#define GRID_SIZE 13

void initialiseArrays();
void fillCoords();
void fillGrid();
void printGrid();

/* 
    blocked[] is the (hardcoded example) input of blocked rows.
    route[] is a 2 element array containing the two stations which a route must be calculated between.    
*/
char blocked[7];
int route[2], grid[13][13];

/* Array containing the coordinates of the start/end points as row,col valuepairs */
Map coords[12];

int main() {
    int i;
    initialiseArrays();
    printGrid();
}

/* 
    initialiseArrays() fills the arrays: blocked[], route[], and grid[][] with the default hardcoded values used for testing. 
    Then prints out the grid[][] array as a 13x13 grid.
*/

void initialiseArrays() {
    int i, j;

    blocked[0] = '2';
    blocked[1] = '2';
    blocked[2] = '0';
    blocked[3] = 'e';
    blocked[4] = '1';
    blocked[5] = '1';
    blocked[6] = 's';

    route[0] = 10;
    route[1] = 12;

    /* 
        fillCoords() should always run before fillGrid(),
        unless you know exactly what you're doing.
    */
    fillCoords();
    fillGrid();
    
}

/*
    Fills the Map coords with xy value pairs describing the coordinates of different stations.
*/
void fillCoords() {
/*  Alternative method, doesn't assign the "correct" index to every valuepair sadly.
    int i,j,k;
    k = 0;

    for(i = 0; i < 13; i++) {
        for(j = 0; j < 13; j++) {
            if(((i == 4 || i == 6 || i == 8) && (j == 12 || j == 0 )) || ((j == 4 || j == 6 || j ==8) && (i == 12 || i == 0))){
                coords[k].col = j;
                coords[k].row = i;
                //printf("\nrow: %d, col: %d", coords[k].row, coords[k].col);
                k++;
            }
        }
    }
*/

/* 
    Hard coded start/end point map.
    Desperate measure, might "fix" later.
*/
coords[0].row = 12;
coords[0].col = 4;

coords[1].row = 12;
coords[1].col = 6;

coords[2].row = 12;
coords[2].col = 8;

coords[3].row = 8;
coords[3].col = 12;

coords[4].row = 6;
coords[4].col = 12;

coords[5].row = 4;
coords[5].col = 12;

coords[6].row = 0;
coords[6].col = 8;

coords[7].row = 0;
coords[7].col = 6;

coords[8].row = 0;
coords[8].col = 4;

coords[9].row = 4;
coords[9].col = 0;

coords[10].row = 6;
coords[10].col = 0;

coords[11].row = 8;
coords[11].col = 0;
}

/* 
    Describes the default grid, with 0's on the following values:
    rows and columns 4, 6, and 8.
    an extra square of 0's is added with borders between row,column value pairs (2,10), (10,2);

    Also adds the start/end coordinates at their assigned positions.
*/
void fillGrid() {
    int i,j;

    for(i = 0; i < 13; i++) {
        for(j = 0; j < 13; j++) {
            if(i == 4 || i == 6 || i == 8) {
                grid[i][j] = 0;
            }
            else if(j == 4 || j == 6 || j == 8) {
                grid[i][j] = 0;
            }
            else if( ((i == 2 || i == 10) && (j >= 2 && j <= 10)) || ((j == 2 || j == 10) && (i >= 2 && i <= 10)) ) {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = -1;
            }
        }
    }

    for (i = 0; i < 12; i++) {
        grid[coords[i].row][coords[i].col] = i + 1;
    }
}

/* Prints the grid array to the console as a 13x13 grid, with blue 0 values and red -1 values.*/
void printGrid() {
    int i,j;

    for(i = 0; i < 13; i++) {
        printf("\n");
        for(j = 0; j < 13; j++) {
            if(grid[i][j] == 0) {
                printf("\033[0;34m%2d ", grid[i][j]); /* Print 0 values in blue */
            }
            else if(grid[i][j] >= 1) {
                printf("\033[0;32m%2d ", grid[i][j]); /* Prints >=1 values in green */
            }
            else {
                printf("\033[0;31m%2d ", grid[i][j]); /* Print -1 values in red */
            }
        }
    }

    /* Reset console colour value */
    printf("\033[0m");
}