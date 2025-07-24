//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    if(argc<2){
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "%s <filename>\n", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL){
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        return -1;
    }

    char buffer[1024];

    while(fgets(buffer, 1024, fp)){

        char *token;

        token = strtok(buffer, ",");

        while(token){

            printf("%s\n", token);

            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}