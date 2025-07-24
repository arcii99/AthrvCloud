//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[30];
    int id;
    float cgpa;
};

struct index{
    int id;
    long offset;
};

int main(){

    FILE *fp;
    fp = fopen("database.bin","ab+");

    if(fp == NULL){
        printf("Error opening file!");
        return 0;
    }

    struct student s;
    struct index i;

    printf("Enter student name: ");
    fflush(stdin);
    gets(s.name);
    printf("Enter student ID: ");
    scanf("%d",&s.id);
    printf("Enter student CGPA: ");
    scanf("%f",&s.cgpa);

    fseek(fp,0,SEEK_END);
    long pos = ftell(fp);
    fwrite(&s,sizeof(s),1,fp);
    i.id = s.id;
    i.offset = pos;
    fwrite(&i,sizeof(i),1,fp);

    printf("Record added successfully!");

    fclose(fp);
    return 0;
}