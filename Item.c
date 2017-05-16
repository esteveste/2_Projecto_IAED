#include "Item.h"
#include <stdio.h>
#include <stdlib.h>

//definir produto
typedef struct produto{
    unsigned int key;//chave equivale a um nr hexadecimal q igualamos a um nr
    int value;
}Produto;

Item newItem(unsigned int key, int value){
    Item new_item = (Item)malloc(sizeof(Produto));
    new_item->key = key;
    new_item->value = value;
    return new_item;
}

void sumItem(Item item,int value){
    item->value +=value;
}

int lessItemKey(Item a, Item b){
    return a->key<b->key? 1 : 0;
}
int lessItemValue(Item a, Item b){
    return a->value<b->value? 1 : 0;
}
void freeItem(Item item){
    free(item);
}
