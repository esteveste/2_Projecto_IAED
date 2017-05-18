#ifndef ITEM  //caso ja tenha sido definido nao volta a definir
#define ITEM

typedef struct produto *Item;
typedef unsigned int Key;
typedef int Value;
//com estas funcoes obtemos os valores do Item sem compremeter a abstracao
//#define get_Key(a) (a->key) 
//#define get_Value(a) (a->value) 
#define less(a,b) (a<b)//esta definicao e valida tanto para os values como para as keys
#define eq(a,b)(a==b)//mais uma vez e compativel tanto com os values como para as keys
#define NULLItem NULL
//static link head; 


Item newItem(unsigned int key, int value);//cria um novo Item
int lessItemKey(Item a, Item b);//retorna 1 se chave do item a < chave do item b, e 0 se a>=b
int lessItemValue(Item a, Item b);//retorna 1 se o valor do item a < valor do item b, e 0 caso contrario
int valueNegative(Value value);//retorna 1 se o value for negativo, 0 caso contrario
void deleteItem(Item item);//releases item from memory
void sumItemStock(Item item,int value);//Soma o value ao value do item,caso for negativo = 0

Key get_Key(Item item);//vamos buscar a Key do item
Value get_Value(Item item);//obtemos o Value do item

//funcoes para manter abstracao quando vamos buscar ao stdin
Key scan_Key();//para a chave
Item scan_Item();//para a chave e o valor

//funcao para imprimir o Item no stdout
void writeln_Item(Item item);

#endif 