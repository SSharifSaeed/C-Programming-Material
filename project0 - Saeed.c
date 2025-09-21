/*
Sharif Saeed
340 Data structures and systems
Project 0
*/

#include <stdio.h>
#define MAX_SIZE 50

int main(){
    int val,temp;
    int condition = 0;
    printf("Enter the number of integer values to be read in: ");
    scanf("%d",&val);
    printf("\n"); //White space
    while (condition == 0){
        if (val > MAX_SIZE){
            printf("\nThe number specified exceeds the maximum allowable value.\n");
            printf("Please enter another number: ");
            printf("\n");
            scanf("%d",&val);
        } else {
            condition = 1;
        }
    }
    int array[val];

    for (int i = 0; i < val; i++){
        printf("\nEnter an integer value: ");
        scanf("%d",&temp);
        array[i] = temp;
    }

    printf("\n");
    printf("The values stored in the array are: ");

    for (int j = 0; j < val; j++){
        if (array[j] % 6 == 0){
            printf("\n%d divisible by 6", array[j]);
        } else if (array[j] % 7 == 0){
            printf("\n%d divisible by 7", array[j]);
        } else {
            printf("\n%d none", array[j]);
        }
    }

    printf("\nDone.");
    
    return 0;
}

