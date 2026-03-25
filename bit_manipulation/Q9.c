// Find the rightmost set bit

#include <stdio.h>

int firstSetBit(int n){
    if(n==0) return 0;
    int pos = 1;
    while ((n&(1 << (pos - 1)))== 0){
        pos++;
    }
    return pos;
}

int main(){
    int n = 18;
    printf("The position of the rightmost set bit in %d is %d\n", n, firstSetBit(n));
     return 0;
}