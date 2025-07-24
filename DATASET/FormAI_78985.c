//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000

int main(){
    char filename[MAX_LEN];
    int found_virus = 0;
    printf("Enter filename to check for viruses: ");
    scanf("%s", filename);
    FILE *fileptr = fopen(filename, "rb");
    if(fileptr == NULL){
        printf("File not found!");
        exit(1);
    }
    char buffer[100];
    while(fread(buffer, sizeof(char), 100, fileptr) == 100){
        if(strstr(buffer, "virus") != NULL){
            found_virus = 1;
            printf("Virus detected!\n");
            break;
        }
    }
    if(found_virus == 0){
        printf("File is clean!\n");
    }
    fclose(fileptr);
    return 0;
}