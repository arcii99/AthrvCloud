//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int num, n; 
    int arr[100];
    printf("Enter the file name to create: ");
    char filename[50];
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Unable to create file\n");
        exit(1);
    }
    printf("\nEnter number of integers to write to file: ");
    scanf("%d", &n);
    printf("\nEnter %d integers to write to file: \n", n);
    for (int i=0; i<n; i++){
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }
    fclose(fp);
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Unable to open file\n");
        exit(1);
    }
    printf("\nContent of %s file is: \n", filename);
    while (fscanf(fp, "%d", &num) != EOF){
        printf("%d ", num);
        arr[num]++;
    }
    fclose(fp);
    printf("\n\nFrequency of each integer in the file is:\n");
    for (int i=0; i<100; i++){
        if (arr[i] != 0){
            printf("%d occurs %d times\n", i, arr[i]);
        }
    }
    return 0;
}