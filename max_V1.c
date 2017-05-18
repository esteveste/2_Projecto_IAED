//maximo simplificado
//never used,or finished
#include "max_V1.h"

static Item maxItem = NULLItem;


void setMax(Item item){
    if(maxItem != NULLItem){
        if(less(get_Value(maxItem),get_Value(item))){//e o item for maior
            maxItem = item;//ent o max item e o novo
        }else if(eq(get_Value(maxItem),get_Value(item))){//se forem iguais
            if(less(get_Key(item),get_Key(maxItem))){//vemos pela ordem alfabetica, se item < maxItem
                maxItem = item;
            }
        }
    }else{//se ainda nao foi inicializado
        maxItem = item;//iguala

    }
}
void changeMax(Item item,Value value,link st){
    if(eq(get_Key(item),get_Key(maxItem))){//se o maxItem for o item atual
        if(valueNegative(value)){//se o valor for negativo
            calculateMax(st);
        }
    }
}
void calculateMax(link st){
    //funcao baseada no print in order, q ve por ordem crescente
    if (st == NULL)
        return;
    calculateMax(nextNodeLeft(st));

    if(less(get_Value(maxItem),get_Value(nodeItem(st)))){//se o item da arvore for maior
        maxItem=nodeItem(st);//como e visto por ordem alfabetica, em caso de igualdade fica bem
    }
    calculateMax(nextNodeRight(st));
}
void writeMax(){
    writeln_Item(maxItem);//escreve o item maximo
}