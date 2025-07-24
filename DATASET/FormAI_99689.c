//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>

struct student {
   int id;
   char name[20];
   float marks[5];
   float average;
};

void calculate_average(struct student *stud) {
    float sum = 0.0;
    for(int i=0;i<5;i++) {
        sum += stud->marks[i];
    }
    stud->average = sum/5;
}

int main() {
    struct student students[3];
    for(int i=0;i<3;i++) {
        printf("Enter student %d details:\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Enter marks for 5 subjects:\n");
        for(int j=0;j<5;j++) {
            scanf("%f", &students[i].marks[j]);
        }
        calculate_average(&students[i]);
    }
    printf("\nStudent details:\n");
    for(int i=0;i<3;i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: ");
        for(int j=0;j<5;j++) {
            printf("%.2f ", students[i].marks[j]);
        }
        printf("\nAverage: %.2f\n", students[i].average);
    }
    return 0;
}