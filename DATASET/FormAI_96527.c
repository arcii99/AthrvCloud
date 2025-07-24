//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    float gpa;
};

void writeToFile(struct student array[], int size, char f[]) {
    FILE *fp;
    fp = fopen(f, "w");
    for(int i=0; i<size; i++) {
        fprintf(fp, "%s\n%d\n%.2f\n", array[i].name, array[i].id, array[i].gpa);
    }
    fclose(fp);
}

int main() {
    struct student s[5];
    char file[50] = "students.txt";
    FILE *fp;
    fp = fopen(file, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for(int i=0; i<5; i++) {
        fgets(s[i].name, 50, fp);
        fscanf(fp, "%d\n%f\n", &s[i].id, &s[i].gpa);
    }
    fclose(fp);
    printf("Name\tID\tGPA\n");
    for(int i=0; i<5; i++) {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].id, s[i].gpa);
    }
    struct student temp;
    printf("\nEnter name of new student: ");
    fgets(temp.name, 50, stdin);
    printf("Enter ID of new student: ");
    scanf("%d", &temp.id);
    printf("Enter GPA of new student: ");
    scanf("%f", &temp.gpa);
    s[5] = temp;
    writeToFile(s, 6, file);
    printf("\nNew student added to file.\n");
    return 0;
}