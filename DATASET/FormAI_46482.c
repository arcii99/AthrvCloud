//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    int number, sum = 0;
    file = fopen("numbers.txt", "r");
    if(file == NULL){
        printf("Error in opening file\n");
        return 0;
    }
    printf("Numbers read from the file:\n");
    while(fscanf(file, "%d", &number) != EOF){
        printf("%d\n", number);
        sum += number;
    }
    fclose(file);
    printf("The sum of the numbers is: %d\n", sum);
    return 0;
}