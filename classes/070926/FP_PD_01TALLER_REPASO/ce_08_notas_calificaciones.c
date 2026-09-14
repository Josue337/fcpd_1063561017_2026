/**
 * @file ce_08_notas_calificaciones.c
 * @brief Assign a letter grade based on a numerical score.
 * @author Josue Bustamante
 * @date 2026-09-12
 */

#include <stdio.h>

int main() {

    int grade = 85;

    if (grade >= 90) {
        printf("Grade: A\n");
    } else if (grade >= 80) {
        printf("Grade: B\n");
    } else if (grade >= 70) {
        printf("Grade: C\n");
    } else if (grade >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}