//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_handling(char *message);

int main(){
    char name[10];
    int age;
    float gpa;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    if(name[strlen(name)-1] == '\n') name[strlen(name)-1] = '\0';

    if(strlen(name) < 2){
        error_handling("Invalid name");
    }

    printf("Enter your age: ");
    if(scanf("%d", &age) != 1){
        error_handling("Invalid age");
    }

    if(age <= 0 || age > 150){
        error_handling("Invalid age");
    }

    printf("Enter your GPA: ");
    if(scanf("%f", &gpa) != 1){
        error_handling("Invalid GPA");
    }

    if(gpa < 0 || gpa > 4){
        error_handling("Invalid GPA");
    }

    printf("\nName: %s\nAge: %d\nGPA: %.2f", name, age, gpa);

    return 0;
}

void error_handling(char *message){
    printf("\n---Error---\n");
    printf("%s\n", message);
    printf("Exiting program with error code 1.");
    exit(1);
}