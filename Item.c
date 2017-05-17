#include "Item.h"
#include <stdio.h>
#include <stdlib.h>

//definir produto
typedef struct produto{
    unsigned int key;//chave equivale a um nr hexadecimal q igualamos a um nr
    int value;
}Produto;

Item newItem(Key key, Value value){
    Item new_item = (Item)malloc(sizeof(Produto));
    new_item->key = key;
    new_item->value = value;
    return new_item;
}

void sumItem(Item item,Value value){
    item->value +=value;
}

int lessItemKey(Item a, Item b){
    return a->key<b->key? 1 : 0;
}
int lessItemValue(Item a, Item b){
    return a->value<b->value? 1 : 0;
}
void deleteItem(Item item){
    free(item);
}


Key scan_Key(){
    Key key;
    scanf("%x",&key);
    return key;

}

Item scan_Item(){
    Key key;
    Value value;
    scanf("%x %d",&key,&value);//vamos buscar os valores do stdin
    Item item = newItem(key,value);//cria o Item com os valores obtidos
    return item;
}

void writeln_Item(Item item){
    printf("%x %d\n",get_Key(item),get_Value(item));
}

Key get_Key(Item item){
    return item->key;
}
Value get_Value(Item item){
    return item->value;
}