//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int id;
    char name[20];
    int marks[3];
} student;

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    student *db = malloc(num_students * sizeof(student));

    int i, j;
    for(i=0; i<num_students; i++) {
        printf("\nEnter details for student %d: ", i+1);
        printf("\nEnter id: ");
        scanf("%d", &db[i].id);
        printf("Enter name: ");
        scanf("%s", db[i].name);
        printf("Enter marks for 3 subjects: ");
        for(j=0; j<3; j++) {
            scanf("%d", &db[i].marks[j]);
        }
    }
    
    printf("\n");
    for(i=0; i<num_students; i++) {
        printf("Details for student %d: \n", i+1);
        printf("ID: %d\n", db[i].id);
        printf("Name: %s\n", db[i].name);
        printf("Marks: ");
        for(j=0; j<3; j++) {
            printf("%d ", db[i].marks[j]);
        }
        printf("\n");
    }

    free(db);
    return 0;
}