#ifndef ST_Keys
#define ST_Keys

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;

#define key(a) (a->key) 
//funcoes arvore
//inicia a arvore
void STinit(link*);

int STcount(link);
//inserte elemento
void STinsert(link*,Item);
void STdelete(link*,Key);
//funcao q liberta a arvore da memoria
void STfree(link*);
Item STsearch(link h, Key v);//encontra node com uma certa chave
//imprime alfabeticamente os items
void print_Ordered_ST(link h);

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
link freeR(link h);//liberta a arvore

link max(link h);//maximo da arvore
link nextNodeLeft(link a);//ve o prox node a esquerda
link nextNodeRight(link a);
Item nodeItem(link a);//vai buscar o item ao node

#endif