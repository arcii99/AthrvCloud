//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *filePointer;
    int numberToWrite;
    
    //Opening the file in write mode
    filePointer = fopen("numbers.txt", "w");
    
    //Checking if file opening was successful or not
    if(filePointer == NULL){
        printf("Unable to open file!");
        return 0;
    }
    
    //Writing numbers to the file
    for(int i = 0; i < 10; i++){
        printf("Enter a number: ");
        scanf("%d", &numberToWrite);
        fprintf(filePointer, "%d\n", numberToWrite);
    }
    
    //Closing the file
    fclose(filePointer);
    
    //Re-opening the file in read mode
    filePointer = fopen("numbers.txt", "r");
    
    //Checking if file opening was successful or not
    if(filePointer == NULL){
        printf("Unable to open file!");
        return 0;
    }
    
    //Reading numbers from the file
    int numberRead;
    while(fscanf(filePointer, "%d", &numberRead) != EOF){
        printf("%d\n", numberRead);
    }
    
    //Closing the file
    fclose(filePointer);
    
    return 0;
}