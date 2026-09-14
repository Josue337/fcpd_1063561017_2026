/**
 * @file ce_01_primos_arreglo.c
 * @brief Generates an array of random numbers and counts how many are prime.
 * @author Josue Bustamante
 * @date 2026-09-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int number)
{
    if (number < 2)
    {
        return 0;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int count_primes(int numbers[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (is_prime(numbers[i]))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    srand(time(NULL));
    int n;

    printf("Enter the array size: ");
    scanf("%d", &n);

    int numbers[n];

    printf("\nGenerated numbers:\n");

    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 100 + 1;
        printf("%d ", numbers[i]);
    }

    int total_primes = count_primes(numbers, n);

    printf("\n\nTotal prime numbers: %d\n", total_primes);

    return 0;
}