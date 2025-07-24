//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_RESUMES 1000
#define MAX_POSITIONS 100
#define MAX_SKILLS 50

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[100];
    char positions[MAX_POSITIONS][50];
    int num_positions;
    char skills[MAX_SKILLS][50];
    int num_skills;
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void load_resumes(char *filename) {
    FILE *fp;
    char line[500];
    Resume r;
    int i = 0, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^,], %[^,], %s", r.name, r.email, r.phone);
        } else if (strstr(line, "Address:")) {
            sscanf(line, "Address: %[^\n]", r.address);
        } else if (strstr(line, "Education:")) {
            sscanf(line, "Education: %[^\n]", r.education);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", r.experience);
        } else if (strstr(line, "Positions:")) {
            r.num_positions = 0;
            while (fgets(line, sizeof(line), fp) && strstr(line, "-")) {
                sscanf(line, "- %[^\n]", r.positions[r.num_positions++]);
            }
        } else if (strstr(line, "Skills:")) {
            r.num_skills = 0;
            while (fgets(line, sizeof(line), fp) && strstr(line, "-")) {
                sscanf(line, "- %[^\n]", r.skills[r.num_skills++]);
            }
        } else if (strstr(line, "--------")) {
            resumes[i++] = r;
        }
    }
    num_resumes = i;

    fclose(fp);
}

void print_resume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
    printf("Positions:\n");
    for (int i = 0; i < r.num_positions; i++) {
        printf("- %s\n", r.positions[i]);
    }
    printf("Skills:\n");
    for (int i = 0; i < r.num_skills; i++) {
        printf("- %s\n", r.skills[i]);
    }
}

int main() {
    load_resumes("resumes.txt");
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume #%d:\n", i+1);
        print_resume(resumes[i]);
        printf("\n");
    }
    return 0;
}