/**
 * @file ce_05_recursividad.c
 * @brief implementation of a function that sums the digits of a number
 * @author Josue Bustamante
 * @date 2026-09-12
 */



 #include<stdio.h>


 int sum_digits(int n){

    if(n==0){
        return 0;
    }

    return(n%10) + sum_digits(n/10);
 }


 int main(){

    int number=556754;
    int result = sum_digits(number);
     printf("The sum of the digits is: %d\n", result);
    return 0;
 }