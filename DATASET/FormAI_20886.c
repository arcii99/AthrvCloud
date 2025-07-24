//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char infectedFile[50];
    printf("Enter the name of the file you want to scan: ");
    scanf("%s", infectedFile);

    FILE *fp = fopen(infectedFile, "r"); //open file in read mode

    if(fp==NULL){
        printf("\nError opening the file %s.\n\n", infectedFile);
        exit(0);
    }

    char line[200]; //maximum length of a line in file
    int lineNumber = 0; //to keep track of the line number
    int count = 0; //to keep count of number of viruses found
    
    while(fgets(line, sizeof(line), fp)){
        lineNumber++;
        if(strstr(line, "virus") != NULL || strstr(line, "malware") != NULL){ //checking for virus or malware keywords
            printf("\nVirus found on line %d: %s\n", lineNumber, line);
            count++;
        }
    }

    if(count == 0){
        printf("\nNo viruses found in %s\n", infectedFile);
    } else {
        printf("\n%d viruses found in %s\n", count, infectedFile);
    }

    fclose(fp); //close the file
    return 0;
}