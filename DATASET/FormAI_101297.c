//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
//Welcome to the exciting world of C Database simulation!
//This program will make you feel like a real-life database administrator.
//We'll start by creating a simple database with some sample data.

#include <stdio.h>

struct student {
    char name[20];
    int age;
    float marks;
};

int main() {
    struct student s[3];
    int i;

    //Adding some sample data to our database
    strcpy(s[0].name, "John");
    s[0].age = 20;
    s[0].marks = 95.0;

    strcpy(s[1].name, "Mike");
    s[1].age = 22;
    s[1].marks = 88.0;

    strcpy(s[2].name, "Sarah");
    s[2].age = 19;
    s[2].marks = 90.5;

    //Displaying the data in our database
    printf("****Student Database****\n");
    printf("Name\t\tAge\tMarks\n");
    for(i=0; i<3; i++) {
        printf("%s\t\t%d\t%.2f\n", s[i].name, s[i].age, s[i].marks);
    }

    //Updating data in our database
    s[1].age = 23;
    s[1].marks = 92.0;

    //Displaying the updated data in our database
    printf("\n****Updated Student Database****\n");
    printf("Name\t\tAge\tMarks\n");
    for(i=0; i<3; i++) {
        printf("%s\t\t%d\t%.2f\n", s[i].name, s[i].age, s[i].marks);
    }

    //Deleting data from our database
    strcpy(s[2].name, "");
    s[2].age = 0;
    s[2].marks = 0.0;

    //Displaying the updated data in our database with deletion
    printf("\n****Deleted Student Database****\n");
    printf("Name\t\tAge\tMarks\n");
    for(i=0; i<3; i++) {
        if(s[i].name[0]!='\0') {
            printf("%s\t\t%d\t%.2f\n", s[i].name, s[i].age, s[i].marks);
        }
    }

    return 0;
}