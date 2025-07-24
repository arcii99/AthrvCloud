//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct student {
    int id;
    char name[20];
    int age;
};

void writeToFile(struct student s[], int n){
    FILE *file = fopen("students.dat", "w");
    fwrite(&n, sizeof(int), 1, file);
    fwrite(s, sizeof(struct student), n, file);
    fclose(file);
}

void readFromFile(struct student s[], int *n){
    FILE *file = fopen("students.dat", "r");
    fread(n, sizeof(int), 1, file);
    fread(s, sizeof(struct student), *n, file);
    fclose(file);
}

int main(){
    struct student s[100];
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the details of student #%d:\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
    }
    writeToFile(s,n);
    printf("Successfully written to file!\n");

    struct student s2[100];
    int m=0;
    readFromFile(s2, &m);
    printf("Read %d students from file:\n", m);
    for(i=0; i<m; i++){
        printf("ID: %d, Name: %s, Age: %d\n", s2[i].id, s2[i].name, s2[i].age);
    }
    return 0;
}