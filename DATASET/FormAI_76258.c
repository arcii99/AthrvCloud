//FormAI DATASET v1.0 Category: Data mining ; Style: authentic
#include<stdio.h>

struct student{
    int roll_no;
    float marks;
};

int main(){
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct student s[n];
    
    for(i=0; i<n; i++){
        printf("Enter the Roll no. and Marks of student %d: ", i+1);
        scanf("%d %f", &s[i].roll_no, &s[i].marks);
    }
    
    float avg_marks=0.0;
    for(i=0; i<n; i++){
        avg_marks += s[i].marks;
    }
    avg_marks /= n;
    
    printf("\n\nList of students whose marks are greater than average marks:\n");
    for(i=0; i<n; i++){
        if(s[i].marks > avg_marks){
            printf("%d %f\n", s[i].roll_no, s[i].marks);
        }
    }
    
    return 0;
}