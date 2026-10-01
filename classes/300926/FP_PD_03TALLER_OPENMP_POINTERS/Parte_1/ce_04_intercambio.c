/**
 * @file ec_04_intercambio.c
 * @brief Swapping two variables using pass-by-reference with pointers.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 42;
    int y = 99;

    printf("Before swap: x = %d, y = %d\n", x, y);
    
    // Pass addresses of x and y to swap function
    swap(&x, &y);
    
    printf("After swap:  x = %d, y = %d\n", x, y);

    return 0;
}