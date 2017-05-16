#include "Projecto.h"

//link st_Keys;//estrutura q ordena alfabeticamente as chaves
//buffer_Link st_Values;//estrutura possibilita a obtecao do maximo da estrutura anterior

int main(){
    while(1){
        char command = getchar();
        getchar();//le o espaco seguinte
        switch(command){
            case 'a':
                /*Incrementa ou reduz o número de unidades associadas ao produto com o código dado. Se
                o código não existir deverá ser criado um novo produto com esse código.*/
                command_A();
                break;
            case 'l':
                /*Lista alfabeticamente todos os produtos*/
                break;
            case 'm':
                /*Escreve o produto com o maior número de unidades em stock. */
                break;
            case 'r':
                /*Remove o produto com o código dado*/

                break;
            case 'x':
                //printf("%d\n",total_Msg);/*imprime o nr de mensagens registadas*/ 
                return 0;
            default:
                printf("Erro: Opcao desconhecida: %c\n",command);
                //clean_Line_Stdin();
                break;
        }
        getchar();//scanf nao obtem o \n
    }
    return -1;//Something wrong happened
}
void command_A(){
    Item item = scan_Item();

    //scanf("%x %d", &key,&value);     //%u/decimal unsigned

}


