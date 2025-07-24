//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// structure for storing information of a student
struct student {
    int roll_no;
    char name[50];
    float cgpa;
};

// recursive function to find the top 3 students based on their CGPA
void find_top_three_students(struct student *data, int start, int end, struct student *top_three[]) {
    // base case
    if(start >= end) {
        return;
    }

    // find the middle index
    int mid = (start + end) / 2;

    // recursively search in left half
    find_top_three_students(data, start, mid, top_three);

    // recursively search in right half
    find_top_three_students(data, mid+1, end, top_three);

    // merge the two halves
    int i = start, j = mid+1, k = 0;
    struct student *temp = (struct student*) malloc(sizeof(struct student) * (end-start+1));

    while(i <= mid && j <= end) {
        if(data[i].cgpa > data[j].cgpa) {
            temp[k++] = data[i++];
        }
        else {
            temp[k++] = data[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = data[i++];
    }

    while(j <= end) {
        temp[k++] = data[j++];
    }

    // update the top three array with the top three students
    for(i=0; i<3 && i<k; i++) {
        top_three[i] = &temp[i];
    }
    for(; i<3; i++) {
        top_three[i] = NULL;
    }

    // copy the sorted array back to original data array
    for(i=start, j=0; i<=end && j<k; i++, j++) {
        data[i] = temp[j];
    }

    free(temp);
}

int main() {
    int n = 5, i;
    struct student data[] = {{1, "John", 8.2},
                             {2, "Smith", 7.5},
                             {3, "Mary", 9.1},
                             {4, "David", 7.8},
                             {5, "Sophie", 8.9}};

    struct student *top_three[3];
    find_top_three_students(data, 0, n-1, top_three);

    printf("Top three students based on CGPA:\n");
    for(i=0; i<3 && top_three[i]!=NULL; i++) {
        printf("%d. Roll no: %d, Name: %s, CGPA: %.2f\n", i+1, top_three[i]->roll_no, top_three[i]->name, top_three[i]->cgpa);
    }

    return 0;
}