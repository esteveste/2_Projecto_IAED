#ifndef maxv1
#define maxv1

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "ST_Keys.h"

void setMax(Item item);
void writeMax();
void changeMax(Item item,Value value,link st);//funcao para caso alterarmos o max na arvore
void calculateMax(link st);//calcular o max
void calculateMax_aux(link st);//funcao aux
int notNullMaxItem();//1 se o Max item n for nulo,0 else
Key maxItemKey();//devolve a Key do Max
#endif