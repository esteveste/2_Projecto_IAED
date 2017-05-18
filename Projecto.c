#include "Projecto.h"

link estrutura_Keys;//estrutura q ordena alfabeticamente as chaves

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
                
                break;
            case 'l':
                /*Lista alfabeticamente todos os produtos*/
                command_L();
                break;
            case 'm':
                /*Escreve o produto com o maior número de unidades em stock. */
                command_M();
                
                break;
            case 'r':
                /*Remove o produto com o código dado*/
                command_R();
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
        sumItemStock(existentItem,get_Value(item));//modifica
        changeMax(existentItem,get_Value(item),estrutura_Keys);//vamos verificar se alteramos o max
        free(item);//liberta o item visto q ele nao e utilizado
    }else{
        //caso contrario criamos um novo item para inserir na arvore
        STinsert(&estrutura_Keys,item);//vamos buscar o endereco do pointer e mandamos
        setMax(item);//definimos o max
    }

}

void command_L(){
    print_Ordered_ST(estrutura_Keys);//imprime por ordem alfabetica
}
void command_M(){
    writeMax();//escreve o max
}
void command_R(){
    Key chave = scan_Key();
    if(notNullMaxItem() && eq(chave,maxItemKey())){//se a chave do q vamos remover for igual a do max
        //notNullMaxItem evita a leitura indevida de memoria no maxItem se for Nulo
        STdelete(&estrutura_Keys,chave);//removemos da arvore
        calculateMax(estrutura_Keys);//calculamos um novo max
    }else{//caso contrario
        STdelete(&estrutura_Keys,chave);//so removemos da arvore
    }

}
