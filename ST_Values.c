#include "ST_Values.h"

//estrutura para facilitar conter o maximo//ver melhor
//caso no buffer, complexidade(1), Preencher o buffer sem modificar valores anteriores->(1)
//refazer buffer(caso ficar vazio, com a modificacao de valores)->(N)
//refazer o buffer basea em obter os valores da arvore(vendo cada um por ordem alfabetica)

//estrutura
typedef Item buffer_Link;

//variaveis para manter contagem do max e min do buffer, static para nao serem acedidas noutros ficheiros
static buffer_Link max = NULL;//mete os pointeiros do maximo 
static buffer_Link min = NULL;//e minimo a Null
static buffer_Link *buffer_heads;//pointer para a estrutura do buffer de items

void buffer_Init() {
    int i;
    buffer_heads = (buffer_Link*)malloc(BufferSize*sizeof(buffer_Link));
    for (i = 0; i < BufferSize; i++) buffer_heads[i] = NULL;
}

void insertBuffer(Item item){
    int i =0;
    if (max == NULL){
        //significa q inicalizamos o buffer e ainda nao temos max
        buffer_heads[i] = item;//mete o 1 item na lista
        max = min = item; //definir o max e min iniciais do buffer
    }else{
        //caso ja tenhamos adicionado um 1 item
        while(buffer_heads[i]==NULL);
    }

}

