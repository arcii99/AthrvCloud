//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>

int main() {
    int num_of_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_of_students);

    char student_names[num_of_students][20];
    float student_grades[num_of_students];

    for (int i = 0; i < num_of_students; i++) {
        printf("Enter the name of student #%d: ", i+1);
        scanf("%s", &student_names[i]);

        printf("Enter the grade of student #%d: ", i+1);
        scanf("%f", &student_grades[i]);
    }

    // Bubble sort - sorting grades and names accordingly
    for (int i = 0; i < num_of_students; i++) {
        for (int j = i+1; j < num_of_students; j++) {
            if (student_grades[i] < student_grades[j]) {
                float temp_grade = student_grades[i];
                student_grades[i] = student_grades[j];
                student_grades[j] = temp_grade;

                char temp_name[20];
                strcpy(temp_name, student_names[i]);
                strcpy(student_names[i], student_names[j]);
                strcpy(student_names[j], temp_name);
            }
        }
    }

    printf("Top 3 students:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %.2f\n", i+1, student_names[i], student_grades[i]);
    }

    return 0;
}