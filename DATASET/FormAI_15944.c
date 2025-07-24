//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

struct resume{
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[200];
    char education[200];
    char experience[500];
};

int main(){
    struct resume r;
    char resume_content[1000];
    int i,j=0;
    printf("Enter the resume content:\n");
    fgets(resume_content,sizeof(resume_content),stdin);
    int n=strlen(resume_content);
    for(i=0;i<n;i++){
        if(!strncmp(resume_content+i,"Name:",5)){
            j=0;
            i+=5;
            while(resume_content[i]!='\n'){
                r.name[j++]=resume_content[i++];
            }
            r.name[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Email:",6)){
            j=0;
            i+=6;
            while(resume_content[i]!='\n'){
                r.email[j++]=resume_content[i++];
            }
            r.email[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Phone:",6)){
            j=0;
            i+=6;
            while(resume_content[i]!='\n'){
                r.phone[j++]=resume_content[i++];
            }
            r.phone[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Address:",8)){
            j=0;
            i+=8;
            while(resume_content[i]!='\n'){
                r.address[j++]=resume_content[i++];
            }
            r.address[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Skills:",7)){
            j=0;
            i+=7;
            while(resume_content[i]!='\n'){
                r.skills[j++]=resume_content[i++];
            }
            r.skills[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Education:",10)){
            j=0;
            i+=10;
            while(resume_content[i]!='\n'){
                r.education[j++]=resume_content[i++];
            }
            r.education[j]='\0';
        }
        else if(!strncmp(resume_content+i,"Experience:",11)){
            j=0;
            i+=11;
            while(resume_content[i]!='\n'){
                r.experience[j++]=resume_content[i++];
            }
            r.experience[j]='\0';
        }
    }
    printf("\nName: %s\n",r.name);
    printf("Email: %s\n",r.email);
    printf("Phone: %s\n",r.phone);
    printf("Address: %s\n",r.address);
    printf("Skills: %s\n",r.skills);
    printf("Education: %s\n",r.education);
    printf("Experience: %s\n",r.experience);
    return 0;
}