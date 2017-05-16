#include "ST_Values.h"

//estrutura para facilitar conter o maximo//ver melhor
//caso no buffer, complexidade(1), Preencher o buffer sem modificar valores anteriores->(1)
//refazer buffer(caso ficar vazio, com a modificacao de valores)->(N)
//refazer o buffer basea em obter os valores da arvore(vendo cada um por ordem alfabetica)
typedef struct buffer_Node{
    Item item;
}*buffer_Link;

//variaveis para manter contagem do max e min do buffer, static para nao serem acedidas noutros ficheiros
static int max = 0;
static int min = 0;
static buffer_Link *buffer_heads; 

void Buffer_Init() {
    int i;
    buffer_heads = (buffer_Link*)malloc(BufferSize*sizeof(buffer_Link));
    for (i = 0; i < BufferSize; i++) buffer_heads[i] = NULL;
}

