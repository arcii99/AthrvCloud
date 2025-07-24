//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include<stdio.h>

struct Resume{
    char name[50];
    char email[50];
    char address[100];
    char skills[200];
    char education[200];
    char experience[500];
}applicant;

struct ParsedResume{
    char name[50];
    char degree[50];
    char skills[200];
    int years_of_experience;
}parsed_resume;

void parse_resume(struct Resume applicant){
    int i, j, k;
    char temp[50];

    // Parsing Name
    i=0, j=0;
    while(applicant.name[i] != ' '){
        temp[j] = applicant.name[i];
        i++;
        j++;
    }
    temp[j]='\0';
    strcpy(parsed_resume.name,temp);
    // Parsing Education
    i=0, j=0, k=0;
    while(applicant.education[i] != '\0'){
        if(applicant.education[i] != ','){
            temp[j]=applicant.education[i];
            j++;
        }
        else{
            temp[j]='\0';
            if(k == 0){
                strcpy(parsed_resume.degree, temp);
                k++;
            }
            else{
                strcat(parsed_resume.degree," in ");
                strcat(parsed_resume.degree,temp);
            }
            j=0;
        }
        i++;
    }
    temp[j]='\0';
    strcat(parsed_resume.degree," in ");
    strcat(parsed_resume.degree,temp);

    // Parsing Skills
    i=0, j=0, k=0;
    while(applicant.skills[i] != '\0'){
        if(applicant.skills[i] != ','){
            temp[j]=applicant.skills[i];
            j++;
        }
        else{
            temp[j]='\0';
            if(k == 0){
                strcpy(parsed_resume.skills, temp);
                k++;
            }
            else{
                strcat(parsed_resume.skills,", ");
                strcat(parsed_resume.skills,temp);
            }
            j=0;
        }
        i++;
    }
    temp[j]='\0';
    strcat(parsed_resume.skills,", ");
    strcat(parsed_resume.skills,temp);

    // Parsing Years of Experience
    i=0, j=0;
    while(applicant.experience[i] != '\0'){
        if(applicant.experience[i] >= '0'&& applicant.experience[i] <= '9'){
            temp[j]=applicant.experience[i];
            j++;
        }
        else{
            temp[j]='\0';
            j=0;
            parsed_resume.years_of_experience=atoi(temp);
            break;
        }
        i++;
    }
    return;
}

int main(){
    printf("Enter Applicant Name: ");
    fgets(applicant.name, 50, stdin);
    printf("Enter Applicant Email: ");
    fgets(applicant.email, 50, stdin);
    printf("Enter Applicant Address: ");
    fgets(applicant.address, 100, stdin);
    printf("Enter Applicant's Skills (comma separated): ");
    fgets(applicant.skills, 200, stdin);
    printf("Enter Applicant's Education (comma separated): ");
    fgets(applicant.education, 200, stdin);
    printf("Enter Applicant's Experience (years): ");
    fgets(applicant.experience, 500, stdin);

    parse_resume(applicant);

    printf("\nParsed Resume Details:\n");
    printf("Name: %s\n", parsed_resume.name);
    printf("Degree: %s\n", parsed_resume.degree);
    printf("Skills: %s\n", parsed_resume.skills);
    printf("Years of Experience: %d\n", parsed_resume.years_of_experience);

    return 0;
}