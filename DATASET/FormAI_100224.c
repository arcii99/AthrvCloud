//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <string.h>

struct resume {
    char name[50];
    int age;
    char education[100];
    char experience[500];
};

int main() {
    int num_resumes;
    printf("Enter the number of resumes to parse: ");
    scanf("%d", &num_resumes);

    struct resume resumes[num_resumes];

    for (int i = 0; i < num_resumes; i++) {
        printf("Enter the name of resume #%d: ", i+1);
        scanf("%s", resumes[i].name);

        printf("Enter the age of %s: ", resumes[i].name);
        scanf("%d", &resumes[i].age);

        printf("Enter the educational background of %s: ", resumes[i].name);
        scanf("%s", resumes[i].education);

        printf("Enter the work experience of %s: ", resumes[i].name);
        scanf("%s", resumes[i].experience);
    }

    printf("\nParsed resumes:\n");

    for (int i = 0; i < num_resumes; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("Education: %s\n", resumes[i].education);
        printf("Experience: %s\n", resumes[i].experience);
    }

    return 0;
}