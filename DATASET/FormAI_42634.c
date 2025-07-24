//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isVirus(char* s){
    if(strstr(s, "virus") != NULL || strstr(s, "malware") != NULL){
        return true;
    }
    return false;
}

int main(){
    char fileName[1000];
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");

    if(file == NULL){
        printf("File not found\n");
        return 0;
    }

    char line[2000];
    int lineNum = 1;
    bool infected = false;
    while(fgets(line, sizeof(line), file) != NULL){
        if(isVirus(line)){
            printf("File is infected with a virus on line %d\n", lineNum);
            infected = true;
            break;
        }
        lineNum++;
    }

    if(!infected){
        printf("File is clean, no viruses found\n");
    }

    fclose(file);

    return 0;
}