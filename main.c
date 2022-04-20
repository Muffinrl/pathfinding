#include <stdio.h>

void initialiseArrays();

char blocked[7];
int route[2], grid[13][13];

int main() {
    int i,j;
    initialiseArrays();



}

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

    for(i = 0; i < 13; i++) {
        printf("\n");
        for(j = 0; j < 13; j++) {
            if(grid[i][j] == 0) {
                printf(" %d ", grid[i][j]);
            }
            else {
                printf("%d ", grid[i][j]);
            }
        }
    }
}

