//maximo simplificado
#include "max_V1.h"

static Item maxItem = NULLItem;

void setMax(Item item){
    if(maxItem != NULLItem){
        if(!eq(get_Key(maxItem),get_Key(item))){//se nao tiverem a mesma chave
            if(less(get_Value(maxItem),get_Value(item))){//e o item for maior
                maxItem = item;//ent o max item e o novo
            }else if(eq(get_Value(maxItem),get_Value(item))){//se forem iguais
                if(less(get_Key(item),get_Key(maxItem))){//vemos pela ordem alfabetica, se item < maxItem
                maxItem = item;
                }
            }
        }else{//se tiverem a mesma chave,significa q vamos alterar o 
            //se aumentarmos o stock do item ou mantermos o max sera o mesmo Item
            if(!less(get_Value(maxItem),get_Value(item))){//no entanto se diminuirmos o valor

            }
        }
    }else{//se ainda nao foi inicializado
        maxItem = item;//iguala

    }
}