#include <stdio.h>

int less(int a, int b){
    return a<b;
}
int findMiddle(int l, int r);
void parcialQuickInsertSort(int a[],int l,int r,int sort);

void parcialQuickInsertSort(int a[],int l,int r,int sort){
    //nao precisamos de ordenar a lista toda, visto q vamos guardando a lista de ordenacao
    //deste modo este sort ira apenas ordenar o ultimo elemento q adicionamos
    //complexidade log(n)
    //estavel(ver melhor)
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
int main(){
    int array[100], c, n;
 
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

      parcialQuickInsertSort(array,0,c-1,22);
    for (c = 0; c < n; c++)
        printf("| %d |",array[c]);
    
    return 0;
}