//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
    char name[20];
    int age;
};

void merge(struct person *data, int left, int mid, int right){
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct person *L = (struct person*)malloc(sizeof(struct person)*n1);
    struct person *R = (struct person*)malloc(sizeof(struct person)*n2);

    for(i=0;i<n1;i++){
        strcpy(L[i].name, data[left+i].name);
        L[i].age = data[left+i].age;
    }

    for(j=0;j<n2;j++){
        strcpy(R[j].name, data[mid+1+j].name);
        R[j].age = data[mid+1+j].age;
    }

    i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i].age <= R[j].age){
            strcpy(data[k].name, L[i].name);
            data[k].age = L[i].age;
            i++;
        }else{
            strcpy(data[k].name, R[j].name);
            data[k].age = R[j].age;
            j++;
        }
        k++;
    }

    while(i<n1){
        strcpy(data[k].name, L[i].name);
        data[k].age = L[i].age;
        i++;
        k++;
    }

    while(j<n2){
        strcpy(data[k].name, R[j].name);
        data[k].age = R[j].age;
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(struct person *data, int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;

        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);

        merge(data, left, mid, right);
    }
}

int main(){
    struct person people[] = {
        {"Oliver", 27},
        {"Isabella", 25},
        {"Emma", 23},
        {"Liam", 31},
        {"Lucas", 29},
        {"Mia", 26},
        {"Sophia", 22},
        {"Noah", 28},
        {"William", 30},
        {"Ava", 21}
    };

    printf("Before Sorting:\n");
    for(int i=0;i<10;i++){
        printf("%s - %d\n",people[i].name, people[i].age);
    }
    printf("\n");

    merge_sort(people, 0, 9);

    printf("After Sorting:\n");
    for(int i=0;i<10;i++){
        printf("%s - %d\n",people[i].name, people[i].age);
    }

    return 0;
}