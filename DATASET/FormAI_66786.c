//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>

struct Resume {
    char name[30];
    int age;
    char education[50];
    char experience[100];
};

void parseResume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    struct Resume resume1 = {"John Doe", 25, "B.S. Computer Science", "2 years as a software engineer at XYZ company"};
    struct Resume resume2 = {"Jane Smith", 27, "M.S. Electrical Engineering", "3 years as a hardware engineer at ABC company"};

    parseResume(resume1);
    printf("\n");
    parseResume(resume2);

    return 0;
}