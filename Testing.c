#include <stdio.h>
#include <stdlib.h>

struct hello{
    int a;
};

int main(){
    int a =89;
    int* hello;
    hello = &a;
    printf("%d",*hello);

    return 0;
}