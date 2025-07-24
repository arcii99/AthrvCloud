//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int id;
    char* watermark;
} student_t;

char* generate_watermark(char* name, int id) {
    char watermark[256];
    sprintf(watermark, "THIS IS A DIGITAL WATERMARK FOR %s WITH ID %d", name, id);
    char* result = (char*)malloc(sizeof(char) * strlen(watermark));
    strcpy(result, watermark);
    return result;
}

void print_student_info(student_t student) {
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Watermark: %s\n", student.watermark);
}

int main() {
    student_t student1;
    student1.name = "John Doe";
    student1.id = 12345;
    student1.watermark = generate_watermark(student1.name, student1.id);

    student_t student2;
    student2.name = "Jane Smith";
    student2.id = 67890;
    student2.watermark = generate_watermark(student2.name, student2.id);

    print_student_info(student1);
    printf("\n");
    print_student_info(student2);

    return 0;
}