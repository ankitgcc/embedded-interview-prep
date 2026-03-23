//Check if a number is even or odd

#include <stdio.h>

void checkEvenOdd(int n){
    if(n&1){
        printf("Odd\n");
    }
    else{
        printf("Even\n");
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    checkEvenOdd(n);
}