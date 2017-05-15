#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT.h"

void command_A();

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
    }
    return -1;//Something wrong happened
}
void command_A(){
    //scanf("%x", &number)     %u/decimal unsigned

}









//sort
int less(int a, int b){
    return a<b;
}
int findMiddle(int l, int r);
void parcialQuickInsertSort(int a[],int l,int r,int sort);

void parcialQuickInsertSort(int a[],int l,int r,int sort){
    //nao precisamos de ordenar a lista toda, visto q vamos guardando a lista de ordenacao
    //deste modo este sort ira apenas ordenar o ultimo elemento q adicionamos
    //complexidade log(n)
    //estavel
    if(l<r){
        int i = findMiddle(l, r);//vamos encontrar o meio da lista ordenada
        if(less(sort,a[i])){//e ver se o valor q queremos ordenar e menor q o valor do meio
            //se for
            parcialQuickInsertSort(a,l,i-1,sort);//vamos ver a metade inferior
        }else{
            //caso contrario
            parcialQuickInsertSort(a,i+1,r,sort);//vamos apenas analizar a metade superior


        }
    }else{
        if(less(sort,a[l])){//se sort for inferior ao l
            a[l]=sort;
        }else{
            a[l+1]=sort;
        }
    }
    

}
int findMiddle(int l, int r){
    int final = l + (r - l) / 2;//encontra ao meio
    printf("%d\n",final);
    return final;
}