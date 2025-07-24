//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100], c; //filename variable will store the name of the file we want to access

    printf("Enter the filename to open: ");
    scanf("%s", filename); //taking input from user for the file name

    fp = fopen(filename, "r"); //opening the file in read mode
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0); //if the file cannot be opened, the program will exit
    }

    while ((c = fgetc(fp)) != EOF) //read and print each character of the file until end of file is reached
        printf("%c", c);

    fclose(fp); //close the file

    FILE *fptr;
    int num;

    fptr = fopen("integer.txt", "w"); //create and open the file integer.txt in write mode

    printf("\nEnter integers to write to the file: ");
    while (scanf("%d", &num) == 1) { //take input from user until a non-integer input is entered
        fprintf(fptr, "%d\n", num); //write the input integer to the file
    }

    fclose(fptr); //close the file

    fptr = fopen("integer.txt", "r"); //open the file in read mode

    int sum = 0;
    while (fscanf(fptr, "%d", &num) == 1) { //read each integer from the file until end of file is reached
        sum += num; //add up all the integers
    }

    printf("The sum of the integers in the file is: %d\n", sum);

    fclose(fptr); //close the file

    return 0;
}