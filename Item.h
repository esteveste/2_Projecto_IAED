#ifndef ITEM  //caso ja tenha sido definido nao volta a definir
#define ITEM

typedef struct produto *Item;
typedef unsigned int Key;
typedef int Value;
//com estas funcoes obtemos os valores do Item sem compremeter a abstracao
#define get_Key(a) (a->key) 
#define get_Value(a) (a->value) 

//static link head; 


Item newItem(unsigned int key, int value);//cria um novo Item
int lessItemKey(Item a, Item b);//retorna 1 se chave do item a < chave do item b, e 0 se a>=b
int lessItemValue(Item a, Item b);//retorna 1 se o valor do item a < valor do item b, e 0 caso contrario
void freeItem(Item item);//releases item from memory
void sumItem(Item item,int value);//Soma o value ao value do item


//funcoes para manter abstracao quando vamos buscar ao stdin
Key scan_Key();//para a chave
Item scan_Item();//para a chave e o valor

//funcao para imprimir o Item no stdout
void writeln_Item(Item item);

#endif 