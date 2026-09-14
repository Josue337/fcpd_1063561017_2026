/**
 * @file ce_04_factorial_paridad.c
 * @brief Calculate factorial and parity of the number positive.
 * @author Josue Bustamante
 * @date 2026/09/12
 */

#include <stdio.h>

int factorial(int a){
    int factorial = 1;
    for (int i = a; i >= 1; i--)
    {
        factorial = factorial*i;
    }

    return factorial;
}

bool paraty(int a){
    if (a % 2 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void factorial_and_parity(int n){

    int factoria = factorial(n);

    printf("The factorial of de numer 5 is %d\n", factoria);

    if (paraty(n) == true)
    {
        printf("The number is pair\n");
    }else{
        printf("The number is odd\n");
    }
}



int main(){

    factorial_and_parity(5);

    return 0;
}