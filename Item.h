#ifndef ITEM  //caso ja tenha sido definido nao volta a definir
#define ITEM

typedef struct produto *Item;
//static link head; 


Item newItem(unsigned int key, int value);//cria um novo Item
int lessItemKey(Item a, Item b);//retorna 1 se chave do item a < chave do item b, e 0 se a>=b
int lessItemValue(Item a, Item b);//retorna 1 se o valor do item a < valor do item b, e 0 caso contrario
void freeItem(Item item);//releases item from memory
void sumItem(Item item,int value);//Soma o value ao value do item

#endif 