//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Personal_Details {
    char name[50];
    char address[100];
    char email[50];
    char phone[20];
};

struct Education_Details {
    char degree[50];
    char institution[100];
    char date[20];
};

struct Experience_Details {
    char company[100];
    char position[50];
    char date[20];
};

struct Resume {
    struct Personal_Details personal;
    struct Education_Details education[10];
    struct Experience_Details experience[10];
};

void parse_resume(struct Resume *r, char *filename) {
    FILE *fptr;
    char buffer[255];

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error - Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, 255, fptr)) {

        if (strstr(buffer, "Name:")) {
            sscanf(buffer, "%*[^:]:%[^\n]", r->personal.name);
        }

        if (strstr(buffer, "Address:")) {
            sscanf(buffer, "%*[^:]:%[^\n]", r->personal.address);
        }

        if (strstr(buffer, "Email:")) {
            sscanf(buffer, "%*[^:]:%[^\n]", r->personal.email);
        }

        if (strstr(buffer, "Phone:")) {
            sscanf(buffer, "%*[^:]:%[^\n]", r->personal.phone);
        }

        if (strstr(buffer, "Education:")) {
            int i = 0;
            while (fgets(buffer, 255, fptr)) {
                if (strstr(buffer, "---")) break;
                if (i > 9) break;

                sscanf(buffer, "%[^,],%[^,],%[^\n]", r->education[i].degree, r->education[i].institution, r->education[i].date);
                i++;
            }
        }

        if (strstr(buffer, "Experience:")) {
            int i = 0;
            while (fgets(buffer, 255, fptr)) {
                if (strstr(buffer, "---")) break;
                if (i > 9) break;

                sscanf(buffer, "%[^,],%[^,],%[^\n]", r->experience[i].company, r->experience[i].position, r->experience[i].date);
                i++;
            }
        }
    }
    fclose(fptr);
}

void print_resume(struct Resume *r) {
    printf("Name: %s\n", r->personal.name);
    printf("Address: %s\n", r->personal.address);
    printf("Email: %s\n", r->personal.email);
    printf("Phone: %s\n\n", r->personal.phone);

    printf("Education:\n");
    for (int i = 0; i < 10; i++) {
        if (r->education[i].degree[0] == 0) break;
        printf("%s, %s, %s\n", r->education[i].degree, r->education[i].institution, r->education[i].date);
    }
    printf("\nExperience:\n");
    for (int i = 0; i < 10; i++) {
        if (r->experience[i].company[0] == 0) break;
        printf("%s, %s, %s\n", r->experience[i].company, r->experience[i].position, r->experience[i].date);
    }
}

int main() {
    struct Resume r;

    char filename[] = "resume.txt";

    parse_resume(&r, filename);

    print_resume(&r);

    return 0;
}