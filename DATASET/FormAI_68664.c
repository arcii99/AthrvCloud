//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1024
#define MAXFIELD 20
#define DELIMITER ","

typedef struct Csv{
    int nfield;
    int nrecord;
    char *field[MAXFIELD];
    char *record[MAXLINE];
}Csv;

char *csvfield(Csv *csv,int n){
    if(n < 0 || n >= csv->nfield){
        return "";
    }
    return csv->field[n];
}

char *csvrecord(Csv *csv,int n){
    if(n < 0 || n >= csv->nrecord){
        return "";
    }
    return csv->record[n];
}

Csv *csvread(char *filename){
    char line[MAXLINE],*p;
    Csv *csv = (Csv*)malloc(sizeof(Csv));
    memset(csv,0,sizeof(Csv));

    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        return NULL;
    }

    /* process header */
    if(fgets(line,sizeof(line),fp) != NULL){
        p = strtok(line,DELIMITER);
        while(p != NULL){
            csv->field[csv->nfield++] = strdup(p);
            p = strtok(NULL,DELIMITER);
        }
    }

    /* process records */
    while(fgets(line,sizeof(line),fp) != NULL){
        p = strtok(line,DELIMITER);
        while(p != NULL){
            csv->record[csv->nrecord++] = strdup(p);
            p = strtok(NULL,DELIMITER);
        }
    }

    fclose(fp);
    return csv;
}

void csvprint(Csv *csv){
    int i,j;
    for(i=0;i<csv->nrecord;i++){
        for(j=0;j<csv->nfield;j++){
            printf("%s:%s\n",csvfield(csv,j),csvrecord(csv,i));
        }
    }
}

void csvfree(Csv *csv){
    int i;
    for(i=0;i<csv->nfield;i++){
        free(csv->field[i]);
    }
    for(i=0;i<csv->nrecord;i++){
        free(csv->record[i]);
    }
    free(csv);
}

int main(){
    Csv *csv;
    csv = csvread("students.csv");
    csvprint(csv);
    csvfree(csv);
    return 0;
}