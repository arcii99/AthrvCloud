//FormAI DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Structure for a student record
struct student {
    int roll_no;
    char name[50];
    float marks;
};

// Function to display a student record
void display_student(struct student s) {
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: %f\n\n", s.marks);
}

// Index table for searching students by roll number
struct index_table {
    int roll_no;
    int record_location;
};

// Function to compare two index table entries
int index_cmp(const void *entry1, const void *entry2) {
    return ((struct index_table*) entry1)->roll_no - ((struct index_table*) entry2)->roll_no;
}

// Function to search for a student by roll number
int search_index(struct index_table *table, int size, int roll_no) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (table[i].roll_no == roll_no) {
            return table[i].record_location;
        }
    }
    
    return -1;
}

int main() {
    // Initialize students and index table
    struct student students[] = {{1, "Alice", 80.5}, {2, "Bob", 75.0}, {3, "Charlie", 90.0}};
    int num_students = sizeof(students) / sizeof(struct student);
    struct index_table index[num_students];
    int i, j;
    
    // Populate index table with roll numbers and record locations
    for (i = 0; i < num_students; i++) {
        index[i].roll_no = students[i].roll_no;
        index[i].record_location = i;
    }
    
    // Sort index table by roll number
    qsort(index, num_students, sizeof(struct index_table), index_cmp);
    
    // Display all students using index table for efficient searching
    for (i = 1; i <= num_students; i++) {
        int record_location = search_index(index, num_students, i);
        
        if (record_location != -1) {
            display_student(students[index[record_location].record_location]);
        } else {
            printf("Student with roll number %d not found!\n\n", i);
        }
    }
    
    return 0;
}