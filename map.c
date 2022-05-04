#include "map.h"

int isMapEqual(Map a, Map b) {
    return (a.col == b.col && a.row == b.row);
}