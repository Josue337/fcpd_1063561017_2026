/**
 * @file ce_03_mayor_menor_ternarios.c
 * @brief Finds the largest and smallest of three numbers using the ternary operator.
 * @author Josue Bustamante
 * @date 2026/09/12
 */

#include <stdio.h>

int max(int a, int b, int c)
{
    int maximum = (a > b) ? a : b;
    maximum = (maximum > c) ? maximum : c;

    return maximum;
}

int min(int a, int b, int c)
{
    int minimum = (a < b) ? a : b;
    minimum = (minimum < c) ? minimum : c;

    return minimum;
}

int main()
{
    int a = 5;
    int b = 10;
    int c = 15;

    int number_max = max(a, b, c);
    int number_min = min(a, b, c);

    printf("The largest number is %d\n", number_max);
    printf("The smallest number is %d\n", number_min);

    return 0;
}