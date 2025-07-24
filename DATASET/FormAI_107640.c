//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>

typedef struct student {
    int roll_number;
    char name[50];
    float marks;
} Student;

int main() {
    FILE *file_pointer; // declaring file pointer
    file_pointer = fopen("students.txt", "w"); // opening file in write mode
    
    if(file_pointer == NULL) {
        printf("File failed to open\n");
        return 1;
    }
    
    // writing data into the file
    Student student_array[3] = { {1, "John Doe", 86}, {2, "Jane Smith", 92}, {3, "Mike Johnson", 78} };
    for(int i=0; i<3; i++) {
        fprintf(file_pointer, "%d\t%s\t%.2f\n", student_array[i].roll_number, student_array[i].name, student_array[i].marks);
    }
    
    fclose(file_pointer); // closing file
    
    // reading data from the file
    file_pointer = fopen("students.txt", "r"); // opening file in read mode
    
    if(file_pointer == NULL) {
        printf("File failed to open\n");
        return 1;
    }
    
    Student student;
    printf("Roll Number\tName\t\tMarks\n");
    while(fscanf(file_pointer, "%d\t%s\t%f\n", &student.roll_number, student.name, &student.marks) != EOF) {
        printf("%d\t\t%s\t%.2f\n", student.roll_number, student.name, student.marks);
    }
    
    fclose(file_pointer); // closing file
    
    return 0;
}