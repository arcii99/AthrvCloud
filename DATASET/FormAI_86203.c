//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include<stdio.h>
#include<string.h>

struct Resume{
    char full_name[50];
    char email[50];
    char phone[12];
    char address[100];
    char education[200];
    char experience[200];
};

void parse_resume(struct Resume r){
    
    char* token;
    
    // Parsing full name
    token = strtok(r.full_name, " ");
    printf("First Name: %s\n", token);
    printf("Last Name: %s\n\n", strtok(NULL, " "));
    
    //Parsing email
    printf("Email: %s\n\n", r.email);
    
    //Parsing phone number
    printf("Phone Number: %s\n\n", r.phone);
    
    //Parsing address
    printf("Address: %s\n\n", r.address);
    
    //Parsing education
    printf("Education: %s\n\n", r.education);
    
    //Parsing experience
    printf("Experience: %s\n\n", r.experience);   
}

int main(){
    
    struct Resume r;
    
    //Sample Resume Information
    strcpy(r.full_name, "John Doe");
    strcpy(r.email, "johndoe@gmail.com");
    strcpy(r.phone, "1234567890");
    strcpy(r.address, "123 Main Street, Anytown, USA");
    strcpy(r.education, "Bachelor of Science in Computer Science from XYZ University");
    strcpy(r.experience, "5 years of experience in software development at ABC Company");
    
    //Parsing Resume
    parse_resume(r);
    
    return 0;
}