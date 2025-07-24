//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char resume_text[] = "SKILLS:\n-Programming: C, C++, Python, Java\n-Database: SQL, Oracle, MySQL\n-Languages: English, Spanish, Mandarin\nEXPERIENCE:\n-Software Developer Intern at XYZ Company\n-Database Administrator at ABC Corporation";
    char *skill_list[] = {"C", "C++", "Python", "Java", "SQL", "Oracle", "MySQL"};
    char *language_list[] = {"English", "Spanish", "Mandarin"};
    char *experience_list[] = {"Software Developer", "Database Administrator"};

    // Initialize categories and counters
    int skill_count = 0;
    int language_count = 0;
    int experience_count = 0;
    int total_experience = 0;

    // Parse skills section of resume
    char *skill_ptr = strstr(resume_text, "SKILLS:");
    skill_ptr += strlen("SKILLS:");
    while (isblank(*skill_ptr) || *skill_ptr == ':' || *skill_ptr == '-') skill_ptr++;
    char *end_ptr = strstr(resume_text, "EXPERIENCE:");
    char skill_buffer[50];
    while (skill_ptr < end_ptr) {
        if (isalpha(*skill_ptr)) {
            int i = 0;
            while (isalnum(*skill_ptr)) {
                skill_buffer[i] = *skill_ptr;
                i++;
                skill_ptr++;
            }
            skill_buffer[i] = '\0';
            for (int j=0; j<7; j++) {
                if (!strcmp(skill_list[j], skill_buffer)) {
                    skill_count++;
                    break;
                }
            }
        } else {
            skill_ptr++;
        }
    }

    // Parse language section of resume
    char *language_ptr = strstr(end_ptr, "Languages:");
    language_ptr += strlen("Languages:");
    end_ptr = strstr(resume_text, "EXPERIENCE:");
    char language_buffer[50];
    while (language_ptr < end_ptr) {
        if (isalpha(*language_ptr)) {
            int i = 0;
            while (isalpha(*language_ptr)) {
                language_buffer[i] = *language_ptr;
                i++;
                language_ptr++;
            }
            language_buffer[i] = '\0';
            for (int j=0; j<3; j++) {
                if (!strcmp(language_list[j], language_buffer)) {
                    language_count++;
                    break;
                }
            }
        } else {
            language_ptr++;
        }
    }

    // Parse experience section of resume
    char *experience_ptr = strstr(resume_text, "EXPERIENCE:");
    experience_ptr += strlen("EXPERIENCE:");
    end_ptr = strchr(resume_text, '\0');
    char experience_buffer[50];
    while (experience_ptr < end_ptr) {
        if (isalpha(*experience_ptr)) {
            int i = 0;
            while (isalnum(*experience_ptr)) {
                experience_buffer[i] = *experience_ptr;
                i++;
                experience_ptr++;
            }
            experience_buffer[i] = '\0';
            for (int j=0; j<2; j++) {
                if (!strcmp(experience_list[j], experience_buffer)) {
                    experience_count++;
                    break;
                }
            }
            if (!strcmp(experience_buffer, "Software") && 
                !strcmp(experience_ptr+1, "Developer")) {
                total_experience++;
            } else if (!strcmp(experience_buffer, "Database") &&
                       !strcmp(experience_ptr+1, "Administrator")) {
                total_experience += 2;
            }
        } else {
            experience_ptr++;
        }
    }

    printf("Skills:\t\t\t%d\n", skill_count);
    printf("Languages:\t\t%d\n", language_count);
    printf("Experience (Software Developer or Database Administrator):\t%d\n", experience_count);
    printf("Total Years of Experience as a Developer/Administrator:\t%d\n", total_experience);

    return 0;
}