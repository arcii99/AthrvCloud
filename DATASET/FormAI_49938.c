//FormAI DATASET v1.0 Category: File handling ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

int main(){
    //Futuristic File handling program
    
    FILE* inputFile = fopen("input.txt", "r");  //Opening Input File
    FILE* outputFile = fopen("output.txt", "w"); //Opening Output File

    if(inputFile == NULL){  //Checking if Input File is opened successfully
        printf("Error! Unable to open Input File.");
        exit(1);  //Terminating the program
    }

    if(outputFile == NULL){  //Checking if Output File is opened successfully
        printf("Error! Unable to open Output File.");
        exit(1);  //Terminating the program
    }

    char data;
    int i = 0;
    
    while((data = fgetc(inputFile)) != EOF){  //Reading Input File character by character
        if(i%2 == 0){  //Encrypting the data
            data = data + 5;
        }
        else{
            data = data - 3;
        }
        fputc(data, outputFile);  //Writing the Encrypted data to Output File
        i++;
    }

    printf("Data has been Encrypted successfully and written to Output File!"); //Successful message
    
    fclose(inputFile);  //Closing Input File
    fclose(outputFile);  //Closing Output File

    return 0;  //Exiting the program
}