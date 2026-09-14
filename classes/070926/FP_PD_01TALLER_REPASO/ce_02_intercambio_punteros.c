/**
 * @file ce_02_intercambio_punteros.c
 * @brief Swaping of pointers.
 * @author Josue Bustamante
 * @date 2026-09-12
 */

#include <stdio.h>

void swaper(int *number_one, int *number_two){
    int temp = *number_one;
    *number_one = *number_two;
    *number_two = temp;
}

int main(){
    int number_one = 10, number_two = 5;

    printf("Value of number one %d\n", number_one);
    printf("Value of number two %d\n", number_two);

    swaper(&number_one, &number_two);

    printf("Value of number one %d\n", number_one);
    printf("Value of number two %d\n", number_two);

    return 0;
}

