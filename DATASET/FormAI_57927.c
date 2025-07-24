//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char resume[] = "I am a software developer with experience in C, Java, and Python. I have a Bachelor's degree in Computer Science and experience working with databases.";
    char keyword[] = "C";

    // Parsing logic to find keyword in resume
    char* keyword_location = strstr(resume, keyword);
    if (keyword_location != NULL) {
        printf("Congratulations! You have experience in %s\n", keyword);
    } else {
        printf("Sorry, you do not have any experience with %s. Maybe try learning it on the weekend?\n", keyword);
    }

    // Generating a funny response
    if (strstr(resume, "juggling") != NULL) {
        printf("Wow, you have experience juggling! That's a great skill to have in the workplace and is sure to impress your coworkers.\n");
    } else if (strstr(resume, "fire-breathing") != NULL) {
        printf("Hold on now, we're not looking for a fire-breathing dragon. Unless, of course, you can code with flames...?\n");
    } else {
        printf("Hmm, you seem pretty ordinary. Can you at least make a decent cup of coffee?\n");
    }

    return 0;
}