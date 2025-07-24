//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include<stdio.h>
#include<string.h>

struct resume{
    char name[50];
    char email[50];
    long int phone;
    char skills[100];
    char education[100];
};

void parse_resume(struct resume r){
    printf("Name: %s\n",r.name);
    printf("Email: %s\n",r.email);
    printf("Phone: %li\n",r.phone);
    printf("Skills: %s\n",r.skills);
    printf("Education: %s\n",r.education);
}

int main(){
    struct resume r1;
    strcpy(r1.name,"John Doe");
    strcpy(r1.email,"johndoe@gmail.com");
    r1.phone = 1234567890;
    strcpy(r1.skills,"C++, Java, Python, JavaScript");
    strcpy(r1.education,"Bachelor's in Computer Science, XYZ University");

    parse_resume(r1);

    return 0;
}