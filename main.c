#include <stdio.h>
#include "grid.h"

int main() {
    initialiseArrays();
    fillJunc();
    setBlocked();
    printGrid();
}