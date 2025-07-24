//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; //Pointer to file
    int nums[10] = {0,1,2,3,4,5,6,7,8,9}; //Array of numbers to write to file
    int i, num; //Counters and variable to read from file

    printf("Hello there! Let's have some fun with file handling!\n\n");

    fp = fopen("fun.txt", "w+"); //Open/create file called fun.txt for read and write

    if(fp == NULL){ //Check if file opened successfully
        printf("Oops, something went wrong while opening the file!\n");
        return 1;
    }

    printf("Yay! The file is now open and ready for some fun!\n");

    fprintf(fp, "Look at these cool numbers: "); //Print a message to the file

    for(i=0; i<10; i++){ //Loop through array and print each number to the file
        fprintf(fp, "%d ", nums[i]);
    }

    printf("Numbers written to file successfully! Let's read them back to have some more fun!\n");

    rewind(fp); //Move cursor to beginning of file

    fscanf(fp, "%s", &num); //Read the message we printed earlier from the file

    printf("%s", num); //Print the message to the console

    printf("Here are the numbers we wrote earlier: ");

    for(i=0; i<10; i++){ //Loop through file and read each number
        fscanf(fp, "%d", &num);
        printf("%d ", num); //Print each number to the console
    }

    printf("\n\nWow, that was so much fun with files! Let's delete the file now and call it a day.\n");

    fclose(fp); //Close the file
    remove("fun.txt"); //Delete the file

    return 0;
}