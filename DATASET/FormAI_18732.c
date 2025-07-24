//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

struct student{
    int ID;
    char name[20];
    float marks[5];
};

float calculate_average(float *marks){
    float total = 0.0, average;
    for(int i=0; i<5; i++){
        total += *(marks+i);
    }
    average = total/5.0;
    return average;
}

void main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student *s = (struct student*) malloc(n * sizeof(struct student));
    if(s==NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }

    for(int i=0; i<n; i++){
        printf("Enter ID for student %d: ", i+1);
        scanf("%d", &(s+i)->ID);
        printf("Enter name for student %d: ", i+1);
        scanf("%s", (s+i)->name);
        printf("Enter marks for student %d: ", i+1);
        for(int j=0; j<5; j++){
            scanf("%f", &(s+i)->marks[j]);
        }
    }

    printf("\n***** Displaying Student Information *****\n");
    printf("ID\tName\t\tAverage\n");
    printf("-----------------------------------------------\n");

    for(int i=0; i<n; i++){
        float avg = calculate_average((s+i)->marks);
        printf("%d\t%s\t\t%.2f\n", (s+i)->ID, (s+i)->name, avg);
    }
    free(s);
}