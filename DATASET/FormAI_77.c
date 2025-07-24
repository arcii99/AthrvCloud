//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char* file){
    FILE *fp;
    char line[2048], c, key[50];
    int i, j, flag = 0;
    fp = fopen(file, "r");
    if(fp == NULL){
        printf("Error: Unable to open file %s\n", file);
        return;
    }
    while(fgets(line, 2048, fp)){
        for(i=0;i<strlen(line);i++){
            if(line[i] == '#'){
                flag = 1;
                j=0;
                continue;
            }
            if(flag && line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && j<50){
                key[j] = line[i];
                j++;
            }
        }
        if(flag && strlen(key) > 0){
            printf("ALERT! Potential virus detected: %s in file: %s\n", key, file);
            flag = 0;
        }
    }
    fclose(fp);
}

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: ./antivirus filename\n");
        return 0;
    }
    char *file = argv[1];
    printf("Scanning file: %s for viruses...\n", file);
    printf("----------------------------------------------------------------------------------------------------\n");
    scan(file);
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Scan complete\n");
    return 0;
}