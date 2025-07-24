//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{ // defining the structure of a employee
    char name[50];
    char skills[100];
    int experience;
};

void parseResume(char resume[]){ // function to parse the resume data
    struct employee emp; // creating instance of employee
    char *token;

    // parsing the resume for Name
    token = strtok(resume, "\n"); // separates the first line
    sprintf(emp.name, "%s", token); // get the first element and put it in employee name field

    // parsing the resume for Skills
    token = strtok(NULL, "\n"); // get the second line
    sprintf(emp.skills, "%s", token); // put it in employee skills field

    // parsing the resume for Experience
    token = strtok(NULL, "\n"); // get the third line
    emp.experience = atoi(token); // converting third line to integer and putting it in employee experience field

    // printing the parsed resume
    printf("\nName: %s\n",emp.name);
    printf("Skills: %s\n",emp.skills);
    printf("Experience: %d\n",emp.experience);
}

int main(){
    char resumeData[] = "John Doe\nC++, Java, Python, MySQL\n5"; // sample resume data
    printf("Parsing Resume: \n%s\n",resumeData);

    parseResume(resumeData); // call to function to parse the resume data
    return 0;
}