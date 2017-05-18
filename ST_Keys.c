#include "ST_Keys.h"

//static link key_head = NULL;//start  
//static link value_head = NULL;//start the tree


//AVL tree Structure -> vai ser usada para as Keys
struct STnode {
    Item item;
    link l, r;
    int height;
};


//inicializa a ST
void STinit(link* head){
    *head = NULL;
} 
//insert de elementos na ST
void STinsert(link* head, Item item){
    *head = insertR(*head, item);
}

void STdelete(link* head, Key k){
     *head = deleteR(*head, k);
} 

void STfree(link* head)
{
    *head=freeR(*head);
}

link NEW(Item item, link l, link r)
{
    link x = (link)malloc(sizeof(struct STnode));
    x->item = item;
    x->l = l;
    x->r = r;
    x->height=1;
    return x;
}

int height(link h){
    if (h == NULL) return 0;
    return h->height;
} 

void update_height(link h)
{
    int height_left = height(h->l);
    int height_right = height(h->r);
    h->height = height_left >
    height_right ? height_left + 1 :
    height_right + 1;
} 

link rotL(link h)
{
    link x = h->r;
    h->r = x->l;
    x->l = h;
    update_height(h);
    update_height(x);
    return x;
}
link rotR(link h)
{
    link x = h->l;
    h->l = x->r;
    x->r = h;
    update_height(h);
    update_height(x);
    return x;
}

link rotLR(link h) /*rotação dupla esquerda direita*/
{
    if (h==NULL) return h;
    h->l=rotL(h->l);
    return rotR(h);
}
link rotRL(link h) /*rotação dupla direita esquerda*/
{
    if (h==NULL) return h;
    h->r=rotR(h->r);
    return rotL(h);
}

int Balance(link h) {/*Balance factor*/
    if(h == NULL) return 0;
    return height(h->l)-height(h->r);
} 
link AVLbalance(link h) {
    int balanceFactor;
    if (h==NULL) return h;
    balanceFactor= Balance(h);
    if(balanceFactor>1) {
        if (Balance(h->l)>=0) h=rotR(h);
        else h=rotLR(h);
    }
    else if(balanceFactor<-1){
        if (Balance(h->r)<=0) h = rotL(h);
        else h = rotRL(h);
    }
    else
    update_height(h);
    return h;
} 

link insertR(link h, Item item)
{
    if (h == NULL)
        return NEW(item, NULL, NULL);
    if (less(get_Key(item), get_Key(h->item)))
        h->l = insertR(h->l, item);
    else
        h->r = insertR(h->r, item);
    h=AVLbalance(h);
    return h;
} 

link deleteR(link h, Key k) {
    if (h==NULL) return h;
    else if (less(k, get_Key(h->item))) h->l=deleteR(h->l,k);
    else if (less(get_Key(h->item), k)) h->r=deleteR(h->r,k) ;
    else{
        if (h->l !=NULL && h->r !=NULL){
            link aux=max(h->l);
            {Item x; x=h->item; h->item=aux->item; aux->item=x;}
            h->l= deleteR(h->l, get_Key(aux->item));
        }
        else {
            link aux=h;
            if (h->l == NULL && h->r == NULL) h=NULL;
            else if (h->l==NULL) h=h->r;
            else h=h->l;
            deleteItem(aux->item);
            free(aux);
        }
    }
    h=AVLbalance(h);
    return h;
} 


//in order to be worked
void print_Ordered_ST(link h)
{
    if (h == NULL)
        return;
    print_Ordered_ST(h->l);
    writeln_Item(h->item);//imprime o item
    print_Ordered_ST(h->r);
}

//max da arvore
link max(link h) {
    while(h!=NULL && h->r!=NULL)//enquanto o proximo elemento da arvore nao for nulo
        h=h->r;//vai para o proximo
    return h;
} 

//search
Item STsearch(link h, Key v)
{
     if (h == NULL)
        return NULLItem;
    if (eq(v, get_Key(h->item)))
        return h->item;
    if (less(v, get_Key(h->item)))
        return STsearch(h->l, v);
    else
        return STsearch(h->r, v);
} 

link freeR(link h)
{
    if (h==NULL)
        return h;
    h->l=freeR(h->l);
    h->r=freeR(h->r);
    return deleteR(h,get_Key(h->item));
}

int STcount(link h){
    if (h==NULL) return 0;
    else return STcount(h->r)+STcount(h->l)+1; 
}

link nextNodeLeft(link a){
    return a->l;
}
link nextNodeRight(link a){
    return a->r;
}
Item nodeItem(link a){
    return a->item;
}

