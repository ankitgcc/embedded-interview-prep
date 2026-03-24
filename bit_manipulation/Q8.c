// Toggle the ith bit of a number

#include <stdio.h>

int toggleKthBit(int n, int pos){
    n = n ^ (1 << pos);
    return n;
}

int main(){
    int n =5, i =1;
    printf("Original n = %d\n", n);
    n = toggleKthBit(n, i);
    printf("After toggling the bit, n = %d\n", n);
     return 0;
}
