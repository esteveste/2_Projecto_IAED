#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

//definir produto
typedef struct produto{
    unsigned int chave;//chave equivale a um nr hexadecimal q igualamos a um nr
    int valor;
}Item;

//Definir a estrutura
typedef struct node {
     Item item; 
     struct node* l;
     struct node* r;
}*link;
static link head; 

void init() {
 head = NULL;
}



link insert(Item item, link l, link r) {
 link x = (link)malloc(sizeof(struct node));
 x->item = item;
 x->l = l;
 x->r = r;
 return x;
} 

int less(int a, int b){
    return a<=b;
}