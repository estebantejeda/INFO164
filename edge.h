#include <iostream>
#include <stdlib.h>

using namespace std;

struct Edge{
    char letter;
    Edge *next;
}; typedef struct Edge edge;