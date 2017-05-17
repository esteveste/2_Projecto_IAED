#include "Projecto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Item.h"
#include "ST_Keys.h"

link estrutura_Keys;//estrutura q ordena alfabeticamente as chaves
//buffer_Link st_Values;//estrutura possibilita a obtecao do maximo da estrutura anterior

int main(){
    
    STinit(&estrutura_Keys);//Inicializamos a estrutura para as Keys

    //comecamos a obter os comandos
    while(1){
        char command = getchar();
        getchar();//le o espaco seguinte ou \n
        switch(command){
            case 'a':
                /*Incrementa ou reduz o número de unidades associadas ao produto com o código dado. Se
                o código não existir deverá ser criado um novo produto com esse código.*/
                command_A();
                getchar();//scanf nao obtem o \n
                break;
            case 'l':
                /*Lista alfabeticamente todos os produtos*/
                command_L();
                break;
            case 'm':
                /*Escreve o produto com o maior número de unidades em stock. */
                command_M();
                getchar();//scanf nao obtem o \n
                break;
            case 'r':
                /*Remove o produto com o código dado*/
                command_R();
                 getchar();//scanf nao obtem o \n
                break;
            case 'x':
                printf("%d\n",STcount(estrutura_Keys));/*imprime o nr de Itens registadas*/ 
                STfree(&estrutura_Keys);
                return 0;
            default:
                printf("Erro: Opcao desconhecida: %c\n",command);
                
                break;
        }
       
    }
    return -1;//Something wrong happened
}
void command_A(){
    Item item = scan_Item();
    Item existentItem = STsearch(estrutura_Keys,get_Key(item));
    if(existentItem != NULLItem){
        //se o elemento ja existe na estrutura
        //ve primeiro o max, visto q o maximo encontra se na estrutura
        sumItemStock(existentItem,get_Value(item));
    }else{
        //caso contrario criamos um novo item para inserir na arvore
        STinsert(&estrutura_Keys,item);//vamos buscar o endereco do pointer e mandamos
    }


}

void command_L(){
    print_Ordered_ST(estrutura_Keys);
}
void command_M(){

}
void command_R(){
    Key chave = scan_Key();
    STdelete(&estrutura_Keys,chave);
}
