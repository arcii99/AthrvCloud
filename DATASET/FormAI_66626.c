//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include<stdio.h>
#include<stdlib.h>

struct Student {
    int roll_No;
    char name[20];
    float cgpa;
};

int main() {
    int n, i, j, k;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student s[n];
    int index[n];
    
    for(i=0; i<n; i++) {
        printf("\nDetails of student %d:\n", i+1);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll_No);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("CGPA: ");
        scanf("%f", &s[i].cgpa);
        index[i] = i; // initializing index array with 0-n for now
    }
    
    // implementation of selection sort to sort index array based on roll numbers
    for(i=0; i<n-1; i++) {
        k = i;
        for(j=i+1; j<n; j++) {
            if(s[index[j]].roll_No < s[index[k]].roll_No)
                k = j;
        }
        if(i != k) {
            int temp = index[i];
            index[i] = index[k];
            index[k] = temp;
        }
    }
    
    // display the sorted list
    printf("\nSorted list based on roll numbers:\n");
    for(i=0; i<n; i++) {
        printf("%d. %d %s %.2f\n", i+1, s[index[i]].roll_No, s[index[i]].name, s[index[i]].cgpa);
    }
    
    return 0;
}