#include <stdio.h>
#include <stdbool.h>

const float pi = 3.1416;

int main(){
    int student_id = 1063561017;
    char name[] = "josue";
    float size = 1.76;
    char grade = 'A';

    printf("the id of the studen is: %d\n", student_id);
    printf("the name of student is: %s\n", name);
    printf("the size of the studen is: %f\n", size);
    printf("the grade of the studen is: %c\n\n", grade);

    float plant = 2;
    double zombie = 3;

    printf("%.2f\n", plant);
    printf("%.4lf\n\n", zombie);

    int myInt;
    float myFloat;
    double myDouble;
    char myChar;
    

    printf("%zu\n", sizeof(myInt));
    printf("%zu\n", sizeof(myFloat));
    printf("%zu\n", sizeof(myDouble));
    printf("%zu\n\n", sizeof(myChar));
    
    int normalInt = 1000;                       // standard int 
    double normalDouble = 3.14;                 // standard double

    short int small = -100;                     // smaller int
    unsigned int count = 25;                    // only positive int
    long int big = 1234567890;                  // larger int
    long long int veryBig = 9223372036854775807; // very large int
    unsigned long long int huge = 18446744073709551615U; // very large, only positive
    long double precise = 3.141592653589793238L; // extended precision

    printf("Normal int: %d\n", normalInt);
    printf("Normal double: %lf\n", normalDouble);
    printf("Small: %hd\n", small);
    printf("Count: %u\n", count);
    printf("Big: %ld\n", big);
    printf("Very Big: %lld\n", veryBig);
    printf("Huge: %llu\n", huge);
    printf("Precise: %Lf\n\n", precise);


    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of short int: %zu bytes\n", sizeof(short int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of long long int: %zu bytes\n", sizeof(long long int));
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsigned long long int));
    printf("Size of long double: %zu bytes\n\n", sizeof(long double));

    float suma = (float) 5/2;
    printf("%.1f", suma);

    int x = 10;
    int y = 3;

    printf("%d\n", x + y); // 13
    printf("%d\n", x - y); // 7
    printf("%d\n", x * y); // 30
    printf("%d\n", x / y); // 3
    printf("%d\n", x % y); // 1

    int z = 5;
    ++z;
    printf("%d\n", z); // 6
    --z;
    printf("%d\n\n", z); // 5

    printf("%d\n", 5>3);
    printf("%d\n\n", 5<3);

    // Create boolean variables
    bool isProgrammingFun = true;
    bool isFishTasty = false;

    // Print boolean values
    printf("%d\n", isProgrammingFun);   // Prints 1 (true)
    printf("%d\n", isFishTasty);        // Prints 0 (false)

    if(0){
        printf("es verdadero");
    }

    return 0;
}