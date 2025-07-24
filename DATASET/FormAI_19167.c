//FormAI DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

/* Defining the maximum limit for the file size */
#define MAX_FILE_SIZE 1000000

/* Function to generate a random number */
int random_number(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){

    /* Defining variables */
    char file_data[MAX_FILE_SIZE];
    char recovered_data[MAX_FILE_SIZE];
    int data_size = 0;
    int i, j;

    /* Generating random data for the file */
    srand(time(0));
    for(i=0; i<MAX_FILE_SIZE; i++){
        file_data[i] = random_number(32, 126);
    }
    printf("Data Generated Succesfully!\n");

    /* Writing the data to the file */
    FILE *fp;
    fp = fopen("data.txt", "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(0);
    }
    fputs(file_data, fp);
    fclose(fp);

    /* Retrieving the data from the file */
    fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(0);
    }
    fgets(file_data, MAX_FILE_SIZE, fp);
    fclose(fp);

    /* Corrupting the data intentionally */
    for(i=0; i<MAX_FILE_SIZE/10; i++){
        j = random_number(0, MAX_FILE_SIZE-1);
        file_data[j] = ' ';
    }

    /* Recovering the data using XOR */
    for(i=0; file_data[i]!='\0'; i++){
        recovered_data[i] = file_data[i] ^ 10;
    }

    /* Writing the recovered data to the file */
    fp = fopen("recovered_data.txt", "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(0);
    }
    fputs(recovered_data, fp);
    fclose(fp);

    printf("Data Recovery Succesfull!\n");

    return 0;
}