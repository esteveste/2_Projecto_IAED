#ifndef ST_Keys
#define ST_Keys

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;

void STinit(link*);
int STcount(link);
Item STsearch(link,Key);
void STinsert(link*,Item);
void STdelete(link*,Key);
void STsort(link,void (*visit)(Item));
void STfree(link*);
void update_height(link);
link deleteR(link, Key);



link insertR(link h, Item item);

#endif