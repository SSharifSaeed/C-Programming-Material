/*
Sharif Saeed
340 Data structures and systems
HW 1
*/

#include <stdio.h>

int main(){
    int *ptr;
    ptr = (int*)malloc(100* sizeof(int));

    if (ptr == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    *ptr = 1;
    ptr++;
    *ptr = 2;
    ptr++;
    *ptr = 3;
    ptr++;
    *ptr = 4;
    ptr++;
    *ptr = 5;
    
    return 0;
}