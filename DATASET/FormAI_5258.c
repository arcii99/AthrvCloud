//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include<stdio.h>

int main(){
    int *ptr;
    char c;

    printf("Enter a character:");
    scanf("%c",&c);

    ptr = (int*)malloc(sizeof(int));

    if(!ptr){
        printf("Error: Memory could not be allocated!");
        exit(1);
    }

    printf("Memory allocated successfully!\n");

    *ptr = (int)c;

    printf("Value stored in memory: %d\n",*ptr);

    free(ptr);

    printf("Memory freed successfully!");

    return 0;
}