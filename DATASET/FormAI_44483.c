//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int age;
    char gender;
    float gpa;
};

void xml_parser(char *filename, struct student **students, int *num_students) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    char line[100];
    int line_num = 0;

    while (fgets(line, 100, file)) {
        line_num++;
        // skip lines that don't start with '<'
        if (line[0] != '<') {
            continue;
        }

        // get the tag name
        char *tag = strtok(line, "<>");
        if (tag == NULL) {
            printf("Error: invalid tag on line %d of file %s\n", line_num, filename);
            continue;
        }

        // determine what to do based on the tag name
        if (strcmp(tag, "students") == 0) {
            // ignore
        } else if (strcmp(tag, "student") == 0) {
            // allocate memory for a new student
            *num_students += 1;
            *students = realloc(*students, *num_students * sizeof(struct student));
        } else if (strcmp(tag, "name") == 0) {
            // get the student's name
            char *name = strtok(NULL, "<>");
            if (name != NULL) {
                strcpy((*students)[*num_students - 1].name, name);
            } else {
                printf("Error: invalid name on line %d of file %s\n", line_num, filename);
            }
        } else if (strcmp(tag, "age") == 0) {
            // get the student's age
            char *age_str = strtok(NULL, "<>");
            if (age_str != NULL) {
                (*students)[*num_students - 1].age = atoi(age_str);
            } else {
                printf("Error: invalid age on line %d of file %s\n", line_num, filename);
            }
        } else if (strcmp(tag, "gender") == 0) {
            // get the student's gender
            char *gender_str = strtok(NULL, "<>");
            if (gender_str != NULL) {
                (*students)[*num_students - 1].gender = gender_str[0];
            } else {
                printf("Error: invalid gender on line %d of file %s\n", line_num, filename);
            }
        } else if (strcmp(tag, "gpa") == 0) {
            // get the student's GPA
            char *gpa_str = strtok(NULL, "<>");
            if (gpa_str != NULL) {
                (*students)[*num_students - 1].gpa = atof(gpa_str);
            } else {
                printf("Error: invalid GPA on line %d of file %s\n", line_num, filename);
            }
        } else {
            printf("Error: unknown tag on line %d of file %s\n", line_num, filename);
        }
    }

    fclose(file);
}

int main() {
    struct student *students = NULL;
    int num_students = 0;
    
    // parse the XML file
    xml_parser("students.xml", &students, &num_students);
    
    // print the students
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Gender: %c\n", students[i].gender);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }
    
    // free the memory allocated for the students
    free(students);

    return 0;
}