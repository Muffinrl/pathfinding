#include "map.h"

typedef struct{
    int hcost, fcost, traversable;
    Map pos;
    struct Node *parent;
}Node;