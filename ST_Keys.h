#ifndef ST_Keys
#define ST_Keys

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;

#define key(a) (a->key) 

//funcoes arvore
void STinit(link*);
int STcount(link);
Item STsearch(link,Key);
void STinsert(link*,Item);
void STdelete(link*,Key);
void STsort(link,void (*visit)(Item));
void STfree(link*);


link deleteR(link, Key);

link NEW(Item item, link l, link r);//funcao q cria um novo node para a arvore
int height(link h);//funcao q retorna o height do node h
void update_height(link h);//vamos atualizar os valores da arvore

//funcoes da arvore AVL
link rotL(link h);//rotate Left
link rotR(link h);//rotate Rigth
link rotLR(link h); /*rotação dupla esquerda direita*/
link rotRL(link h); /*rotação dupla direita esquerda*/

int Balance(link h);//retorna o balance factor de um node
link AVLbalance(link h);//vamos equilibrar a arvore

link insertR(link h, Item item);//insere um Item
link deleteR(link h, Key k);//apagamos um item conforme a chave

void print_Ordered_ST(link h);//imprime alfabeticamente os items

link max(link h);//maximo da arvore


#endif