/**
 * @file ce_09_memoria_dinamica.c
 * @brief Create a dynamic array, fill it with user-provided values, and calculate their sum.
 * @author Josue Bustamante
 * @date 2026-09-12
 */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int *array;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("Enter the values:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum = sum + array[i];
    }

    printf("The total sum is: %d\n", sum);

    free(array);

    return 0;
}
