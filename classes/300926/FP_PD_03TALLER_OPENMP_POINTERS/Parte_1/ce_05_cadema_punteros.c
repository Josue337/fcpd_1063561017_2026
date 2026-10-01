/**
 * @file ec_05_cadena_punteros.c
 * @brief Traversing a null-terminated string using a pointer.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>

int main(void) {
    char str[] = "OpenMP & Pointers";
    char *ptr = str; // Point to start of character array

    printf("Character | Memory Address\n");
    printf("---------------------------\n");

    while (*ptr != '\0') {
        printf("    '%c'   | %p\n", *ptr, (void *)ptr);
        ptr++; // Increment pointer to next character
    }

    return 0;
}