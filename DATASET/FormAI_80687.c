//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000
#define MAX_NAME_LENGTH 50
#define MAX_EDUCATION_LENGTH 50
#define MAX_SKILLS_LENGTH 200

struct resume {
    char name[MAX_NAME_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
};

struct resume_database {
    struct resume resumes[MAX_RESUMES];
    int num_resumes;
};

void parse_resume(struct resume *r, char *resume_text);
void add_resume(struct resume_database *db, struct resume *r);
int find_resume(struct resume_database *db, char *name);
void print_resume(struct resume *r);

int main() {
    struct resume_database db;
    db.num_resumes = 0;

    printf("Welcome to the C Resume Parsing System!\n\n");

    while (1) {
        printf("Menu\n");
        printf("1. Add resume\n");
        printf("2. Find resume\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char resume_text[1000];
            printf("Enter resume text: ");
            getchar();
            fgets(resume_text, 1000, stdin);

            struct resume r;
            parse_resume(&r, resume_text);

            add_resume(&db, &r);
            printf("Resume added successfully!\n");
        }
        else if (choice == 2) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name to search: ");
            getchar();
            fgets(name, MAX_NAME_LENGTH, stdin);

            int index = find_resume(&db, name);
            if (index == -1) {
                printf("Resume not found!\n");
            }
            else {
                struct resume *r = &(db.resumes[index]);
                print_resume(r);
            }
        }
        else if (choice == 3) {
            printf("Thank you for using the C Resume Parsing System!\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

        printf("\n");
    }

    return 0;
}

void parse_resume(struct resume *r, char *resume_text) {
    char *token = strtok(resume_text, "\n");
    strcpy(r->name, token);

    token = strtok(NULL, "\n");
    strcpy(r->education, token);

    token = strtok(NULL, "\n");
    strcpy(r->skills, token);
}

void add_resume(struct resume_database *db, struct resume *r) {
    db->resumes[db->num_resumes] = *r;
    db->num_resumes++;
}

int find_resume(struct resume_database *db, char *name) {
    for (int i = 0; i < db->num_resumes; i++) {
        struct resume *r = &(db->resumes[i]);
        if (strcmp(r->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_resume(struct resume *r) {
    printf("Name: %s", r->name);
    printf("Education: %s", r->education);
    printf("Skills: %s", r->skills);
}