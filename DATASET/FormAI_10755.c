//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include<stdio.h> //Standard input output header file
#include<string.h> //String header file

int main(){

    char virus[] = "malware"; //Virus string to look for
    char fileName[20]; //Name of file to scan
    char buffer[100]; //Buffer to store content of file
    int virusFlag = 0; //Flag to indicate presence of virus
    FILE *fp; //File pointer

    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r"); //Opening file in read mode

    if(fp == NULL){ //Check if file exists or not
        printf("File does not exist!");
        return 0; //Exit program
    }

    while(fgets(buffer, 100, fp) != NULL){ //Reading file line-by-line
        if(strstr(buffer, virus) != NULL){ //Checking if virus is present in line
            printf("Virus found in file \"%s\" in the following line:\n%s\n", fileName, buffer);
            virusFlag = 1;
        }
    }

    if(!virusFlag){ //If no virus found
        printf("No virus found in file \"%s\".\n", fileName);
    }

    fclose(fp); //Close file
    return 0;
}