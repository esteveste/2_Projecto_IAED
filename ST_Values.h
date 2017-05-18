#ifndef ST_Values
#define ST_Values

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define BufferSize 20 //size of memory buffer

//estrutura
typedef Item buffer_Link;

void buffer_Init();//inicializa o buffer

//vamos introduzir o valor no buffer
void insertBuffer(Item item);
//atualiza o min e o max conforme o novo item
void updateMinMax(buffer_Link* linkBuffer);
//encontramos o novo max e min do buffer
void searchMinMax();
//caso vamos alterar um valor do buffer
void modifyBuffer(Item item,Value value);
//escreve o item maximo do buffer
void writeMax();

#endif