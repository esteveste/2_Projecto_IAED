#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

//Definir a estrutura
typedef struct node {
     void* item; 
     struct node* l;
     struct node* r;
}*link;
static link head; 

void init() {
 head = NULL;
}

link insert(void* item, link l, link r) {
 link x = (link)malloc(sizeof(struct node));
 x->item = item;
 x->l = l;
 x->r = r;
 return x;
} 
