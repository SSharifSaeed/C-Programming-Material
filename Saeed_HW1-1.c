/*
Sharif Saeed
340 Data structures and systems
HW 1
*/


#include <stdio.h>

/*PROBLEM 1*/
int main(){
    int ArrName[SIZE];
    int sum = 0;
    for(int i = 0; i < SIZE;i++){
        sum += ArrName[i];   
    }

    return 0;
}

/*PROBLEM 2*/
typedef struct{
        char lastName[20];
        int age;
        double salary;
} PERSON;

