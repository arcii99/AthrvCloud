//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 50
#define MAX_RESUMES 10
#define MAX_TEXT_LENGTH 1000

typedef struct Resume {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone_number[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    int work_experience;
    char skills[MAX_FIELDS][MAX_FIELD_LENGTH];
} Resume;

typedef struct Database {
    Resume resumes[MAX_RESUMES];
    int num_of_resumes;
} Database;

void add_resume(Database *db) {
    Resume new_resume;
    printf("Enter Name: ");
    fgets(new_resume.name, MAX_FIELD_LENGTH, stdin);
    printf("Enter Email: ");
    fgets(new_resume.email, MAX_FIELD_LENGTH, stdin);
    printf("Enter Phone Number: ");
    fgets(new_resume.phone_number, MAX_FIELD_LENGTH, stdin);
    printf("Enter Address: ");
    fgets(new_resume.address, MAX_FIELD_LENGTH, stdin);
    printf("Enter Work Experience (in years): ");
    scanf("%d", &new_resume.work_experience);
    getchar();
    printf("Enter Skills (separated by comma): ");
    char skills_input[MAX_TEXT_LENGTH];
    fgets(skills_input, MAX_TEXT_LENGTH, stdin);
    char *skill = strtok(skills_input, ",");
    int i = 0;
    while (skill != NULL && i < MAX_FIELDS) {
        skill[strcspn(skill, "\n")] = 0; // Remove newline character
        strcpy(new_resume.skills[i], skill);
        i++;
        skill = strtok(NULL, ",");
    }
    if (i == MAX_FIELDS) {
        printf("Max skills reached, %d skills added\n", i);
    }
    db->resumes[db->num_of_resumes++] = new_resume;
    printf("Resume added successfully!\n");
}

void print_resume(Resume resume) {
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone Number: %s", resume.phone_number);
    printf("Address: %s", resume.address);
    printf("Work Experience: %d years\n", resume.work_experience);
    printf("Skills:");
    for (int i = 0; i < MAX_FIELDS; i++) {
        if (strlen(resume.skills[i]) > 0) { // Only print non-empty skills
            printf(" %s,", resume.skills[i]);
        }
    }
    printf("\n");
}

void search_by_skill(Database *db) {
    char skill[MAX_FIELD_LENGTH];
    printf("Enter skill to search: ");
    fgets(skill, MAX_FIELD_LENGTH, stdin);
    printf("Search results:\n");
    for (int i = 0; i < db->num_of_resumes; i++) {
        for (int j = 0; j < MAX_FIELDS; j++) {
            if (strcasecmp(db->resumes[i].skills[j], skill) == 0) {
                print_resume(db->resumes[i]);
                break; // Only show each resume once
            }
        }
    }
}

void print_menu() {
    printf("--- Resume Parser ---\n");
    printf("1. Add Resume\n");
    printf("2. Search by Skill\n");
    printf("3. Exit\n");
}

int main() {
    Database db = {0}; // Initialize database
    int option;
    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        getchar(); // Read newline character
        switch (option) {
            case 1:
                if (db.num_of_resumes == MAX_RESUMES) {
                    printf("Max resumes reached, cannot add more!\n");
                } else {
                    add_resume(&db);
                }
                break;
            case 2:
                if (db.num_of_resumes == 0) {
                    printf("No resumes added yet!\n");
                } else {
                    search_by_skill(&db);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 3);
    return 0;
}