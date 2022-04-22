#include <stdio.h>
#include "map.h"

#define GRID_SIZE 13

void initialiseArrays();
void fillCoords();
void fillGrid();
void fillJunc();
void printGrid();
void printJunc();

/* 
    blocked[] is the (hardcoded example) input of blocked rows.
    route[] is a 2 element array containing the two station which a route must be calculated between.  
    grid[] format is [ROW,COLUMN].  
*/
char blocked[7] = {'2', '2', '0', 'e', '1', '1', 's'};
Map blockedEdges[2];
int route[2] = {10, 12}; 
int grid[13][13];

/* Array containing the coordinates of the start/end points as row,col valuepairs */
Map station[12];
Map junc[25];

/* 
    initialiseArrays() fills the arrays: blocked[], route[], and grid[][] with the default hardcoded values used for testing. 
    Then prints out the grid[][] array as a 13x13 grid.
*/

void initialiseArrays() {
    int i, j;
    /* 
        fillCoords() should always run before fillGrid(),
        unless you know exactly what you're doing.
    */
    fillCoords();
    fillGrid();
    
}

/*
    Sets the blocked edge values in the grid to -1 according to the input blocked[]
*/

void setBlocked() {
    int i,j;

    for(i = 1; i <= blocked[0] * 3 + 1; i+=3) {
        for(j = 0; j < 25; j++) {
            if ((junc[j].row - 2)/2 == (int)blocked[i]-'0' && (junc[j].col - 2)/2 == (int)blocked[i+1]-'0') {
                if(blocked[i+2] == 'e') {
                    grid[junc[j].row][junc[j].col+1] = -1;

                    blockedEdges[(i-1)/3].col = junc[j].col+1;
                    blockedEdges[(i-1)/3].row = junc[j].row+1;
                }
                else if(blocked[i+2] == 's') {
                    grid[junc[j].row+1][junc[j].col] = -1;

                    blockedEdges[(i-1)/3].col = junc[j].col+1;
                    blockedEdges[(i-1)/3].row = junc[j].row+1;
                }
            }
        }
    }
}

/*
    Fills the Map coords with xy value pairs describing the coordinates of different station.
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
    station[0].row = 12;
    station[0].col = 4;

    station[1].row = 12;
    station[1].col = 6;

    station[2].row = 12;
    station[2].col = 8;

    station[3].row = 8;
    station[3].col = 12;

    station[4].row = 6;
    station[4].col = 12;

    station[5].row = 4;
    station[5].col = 12;

    station[6].row = 0;
    station[6].col = 8;

    station[7].row = 0;
    station[7].col = 6;

    station[8].row = 0;
    station[8].col = 4;

    station[9].row = 4;
    station[9].col = 0;

    station[10].row = 6;
    station[10].col = 0;

    station[11].row = 8;
    station[11].col = 0;
}

/*
    Fills the array containing all the junction coordinates with respect to the main grid.
*/
void fillJunc() {
    int row,col,i;

    i = 0;

    for(row = 2; row <= 10; row+=2) {
        for(col = 2; col <= 10; col+=2) {
            junc[i].col = col;
            junc[i].row = row;
            i++;
        }
    }
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
    // Uncomment to add stations
    // for (i = 0; i < 12; i++) {
    //     grid[station[i].row][station[i].col] = i + 1;
    // }
}

/*
    Returns a value from grid[][]
*/
int getGrid(int row, int col) {
    return grid[row][col];
}

/*
    Sets a value in grid[][] at (row,col)
*/
void setGrid(int row, int col, int value) {
    grid[row][col] = value;
}

/*
    Gets the coordinate values of a station
    The value passed for isCol determines which coordinate is returned.
*/
int getStationValue(int i, int isCol) {
    if (isCol == 1) {
        return station[i].col;
    } else {
        return station[i].row;
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

void printJunc() {
    int i;
    for(i = 0; i < 25; i++) {
        printf("Junction(r,c) %d: (%2d,%2d) \n", i, junc[i].row,junc[i].col);
    }
}
