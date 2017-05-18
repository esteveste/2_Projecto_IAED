#include "ST_Values.h"

//estrutura para facilitar conter o maximo//ver melhor
//caso no buffer, complexidade(1), Preencher o buffer sem modificar valores anteriores->(1)
//refazer buffer(caso ficar vazio, com a modificacao de valores)->(N)
//refazer o buffer basea em obter os valores da arvore(vendo cada um por ordem alfabetica)


//variaveis para manter contagem do max e min do buffer, static para nao serem acedidas noutros ficheiros
static buffer_Link *bufferMax = NULL;//mete os pointeiros do maximo do local do buffer
static buffer_Link *bufferMin = NULL;//e minimo a Null
static buffer_Link *buffer_heads;//pointer para a estrutura do buffer de items

void buffer_Init() {
    int i;
    buffer_heads = (buffer_Link*)malloc(BufferSize*sizeof(buffer_Link));
    for (i = 0; i < BufferSize; i++) buffer_heads[i] = NULL;
}

//modificar o bufferLink

void insertBuffer(Item item){
    int i =0;
    if (bufferMax == NULL){
        //significa q inicalizamos o buffer e ainda nao temos max
        buffer_heads[i] = item;//mete o 1 item na lista
        bufferMax = bufferMin = &buffer_heads[i]; //definir o max e min iniciais do buffer
    }else{
        //caso ja tenhamos adicionado um 1 item
        int i = 0;
        for(;buffer_heads[i]==NULL && i < BufferSize ;i++);//vamos procurar por free spots no buffer
        if(i == BufferSize){
            //se o buffer tiver cheio
            if(less(get_Value(*bufferMin),get_Value(item))){
                //o item tem de ser maior q o min
                *bufferMin = item;//no lugar do min do buffer substituimos pelo item
                searchMinMax();//atualizamos o max e o min
            }else if(eq(get_Value(*bufferMin),get_Value(item))){
                //se os valores forem iguais, ve as chaves
                if(less(get_Key(item),get_Key(*bufferMin))){
                    //se for alfabeticamente inferior, troca
                    *bufferMin = item;//no lugar do min do buffer substituimos pelo item
                    searchMinMax();
                }
            }
        }else{
            //caso haja spot
            buffer_heads[i]=item;
            updateMinMax(&buffer_heads[i]);//actualiza os buffers

        }

    }

}

void updateMinMax(buffer_Link* linkBuffer){
    //se for novo maximo define
    if(less(get_Value(*bufferMax),get_Value(*linkBuffer)))
        bufferMax = linkBuffer;
    //se for novo minimo define
    if(less(get_Value(*linkBuffer),get_Value(*bufferMin)))
        bufferMin = linkBuffer;
}

void searchMinMax(){
    int i,NullFlag = 1;
    for(i=0;i<BufferSize;i++){//vamos ver todos os valores do buffer
        if(buffer_heads[i]<*bufferMin){
            //se o item for menor q o buffer min atual
            bufferMin = &buffer_heads[i];//definimos o bufferMin
        }
        if(*bufferMax<buffer_heads[i]){
            //se o item for maior q o buffer max atual
            bufferMax = &buffer_heads[i];//definimos o bufferMax
        }
        if(buffer_heads[i]!=NULL)//se encontramos um item no buffer
            NullFlag = 0;//desativamos a flag
    }
    if(NullFlag){//se o buffer esta todo NULL
        //temos q procurar em todos os items por um novo max e min

    }
}

void modifyBuffer(Item item,Value value){
    int i;
    for(i=0;i<BufferSize;i++)
        if(eq(get_Key(item),get_Key(buffer_heads[i])))//ver se o elemento se encontra no buffer
            break;
    if(i!=BufferSize){//ent encontramos o item
        if(valueNegative(value)){
            //se o value for negativo, ent retiramos stock
            //se o Buffermin for o item q alteramos
            if(eq(get_Key(*bufferMin),get_Key(item))){
                buffer_heads[i] = NULL;//apagamos o item pk ja nao sabemos a sua posicao no buffer
                searchMinMax();//vemos o min e o max de novo
            }else if(less(get_Value(buffer_heads[i]),get_Value(*bufferMin))){//se o item ficou inferior ao min
                buffer_heads[i] = NULL;//apagamos o item pk ja nao sabemos a sua posicao no buffer
                searchMinMax();//vemos o min e o max de novo
            }else{//fora desses casos
                //basta atualizar o Max
                searchMinMax();
            }

        }else{//se o valor foi positivo ou igual a zero
            searchMinMax();//basta atualizar o Max
        }
    }else{
        //se nao esta no buffer
        insertBuffer(item);//tentamos inserir no buffer
    }
}
void refillBuffer(){

}
void writeMax(){
    writeln_Item(*bufferMax);//escreve o item maximo
}