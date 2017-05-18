#ifndef maxv1
#define maxv1

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "ST_Keys.h"

void setMax(Item item);
void writeMax();
void changeMax(Item item,Value value,link st);
void calculateMax(link st);//calcular o max

#endif