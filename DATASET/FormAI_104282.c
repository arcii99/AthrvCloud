//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char education[100];
    char experience[200];
    char skills[200];
};

void print_resume(struct resume r);
int parse_resume(struct resume* r, char* file_name);

int main() {
    struct resume my_resume;
    char file_name[50] = "resume.txt";
    int success = parse_resume(&my_resume, file_name);
    if (success) {
        print_resume(my_resume);
    } else {
        printf("Resume parsing failed.\n");
    }
    return 0;
}

void print_resume(struct resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
    printf("Skills: %s\n", r.skills);
}

int parse_resume(struct resume* r, char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        return 0;
    }

    char line[200];
    int line_num = 0;
    while (fgets(line, sizeof(line), file)) {
        line_num++;
        if (line_num == 1) {
            strncpy(r->name, line, sizeof(r->name));
            r->name[strlen(r->name) - 1] = '\0';
        } else if (line_num == 2) {
            strncpy(r->email, line, sizeof(r->email));
            r->email[strlen(r->email) - 1] = '\0';
        } else if (line_num == 3) {
            strncpy(r->education, line, sizeof(r->education));
            r->education[strlen(r->education) - 1] = '\0';
        } else if (line_num == 4) {
            strncpy(r->experience, line, sizeof(r->experience));
            r->experience[strlen(r->experience) - 1] = '\0';
        } else if (line_num == 5) {
            strncpy(r->skills, line, sizeof(r->skills));
            r->skills[strlen(r->skills) - 1] = '\0';
        }
    }

    fclose(file);
    return 1;
}