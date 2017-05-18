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
    }else if(less(get_Value(maxItem),get_Value(item))){//se tiverem keys diff, e o item modificado for maior q o max
        maxItem = item;

    }else if(eq(get_Value(maxItem),get_Value(item))){//se os valores forem iguais
        if(less(get_Key(item),get_Key(maxItem))){//vai ver pela ordem alfabetica, caso item vier primeiro
            maxItem = item;
        }
    }
}
void calculateMax(link st){
    maxItem = NULLItem;//definimos o Max como NULL, como prevencao de quando o Max e removido
    if(STcount(st)){//se existirem elementos na arvore
        calculateMax_aux(st);//calculamos assim o Max
    }

}
void calculateMax_aux(link st){
    //funcao baseada no print in order, q ve por ordem crescente
    
    if (st == NULL)
        return;
    calculateMax_aux(nextNodeLeft(st));
    if(maxItem==NULLItem){//se o max item for nulo, definimos o 1 q encontramos
        maxItem = nodeItem(st);
    }
    if(less(get_Value(maxItem),get_Value(nodeItem(st)))){//se o item da arvore for maior
        maxItem=nodeItem(st);//como e visto por ordem alfabetica, em caso de igualdade fica bem
    }  
    calculateMax_aux(nextNodeRight(st));
}
Key maxItemKey(){
    return get_Key(maxItem);
}
void writeMax(){
    if(maxItem!=NULLItem)//se for diferente de NULL imprime
        writeln_Item(maxItem);//escreve o item maximo
}

int notNullMaxItem(){
    return maxItem != NULLItem;
}
//void freeMaxItem(){}