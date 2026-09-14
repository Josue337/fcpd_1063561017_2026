/**
 * @file ce_10_gestion_estudiantes.c
 * @brief Implement a student management system using structures.
 * @author Josue Bustamante
 * @date 2026-09-12
 */


#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float grade1;
    float grade2;
    float grade3;
};

float calculateAverage(struct Student student) {

    return (student.grade1 + student.grade2 + student.grade3) / 3;
}

int main() {

    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students;

    students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Grade 1: ");
        scanf("%f", &students[i].grade1);

        printf("Grade 2: ");
        scanf("%f", &students[i].grade2);

        printf("Grade 3: ");
        scanf("%f", &students[i].grade3);
    }

    printf("\n--- Student averages ---\n");

    for (int i = 0; i < n; i++) {

        float average = calculateAverage(students[i]);

        printf("%s - Average: %.2f\n", students[i].name, average);
    }

    printf("\n--- Approved students ---\n");

    for (int i = 0; i < n; i++) {

        float average = calculateAverage(students[i]);

        if (average >= 60) {
            printf("%s - Average: %.2f\n", students[i].name, average);
        }
    }

    free(students);

    return 0;
}