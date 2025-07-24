//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct Student {
    char name[30];
    int rollNo;
    int marks[5];
};

int main() {
    int n, m, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the number of exams: ");
    scanf("%d", &m);
    struct Student *students = (struct Student*) malloc(n * sizeof(struct Student));
    for(i=0;i<n;i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        for(j=0;j<m;j++) {
            printf("Marks in Exam %d: ", j+1);
            scanf("%d", &students[i].marks[j]);
        }
    }
    printf("\n\n**************** Results ****************\n");
    printf("\n|%-25s|%-10s|", "Name", "Roll No");
    for(i=1;i<=m;i++)
        printf(" Exam %-10d|", i);
    printf(" Average Marks |\n");
    for(i=0;i<70;i++)
        printf("-");
    printf("\n");
    for(i=0;i<n;i++) {
        float avg = 0;
        printf("|%-25s|%-10d|", students[i].name, students[i].rollNo);
        for(j=0;j<m;j++) {
            printf("%-15d|", students[i].marks[j]);
            avg += students[i].marks[j];
        }
        avg = avg/m;
        printf("%-15.2f|\n", avg);
    }
    for(i=0;i<70;i++)
        printf("-");
    return 0;
}