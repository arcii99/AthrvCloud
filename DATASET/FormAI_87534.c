//FormAI DATASET v1.0 Category: Data mining ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10000

struct Node{
    int data;
    struct Node *next;
};

void insert(struct Node *head, int value){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data= value;
    temp->next = head->next;
    head->next = temp;
}

void display(struct Node *head){
    while(head->next != NULL){
        printf("%d->",head->next->data);
        head = head->next;
    }
    printf("NULL\n");
}

void generateData(int data[]){
    for(int i=0;i<SIZE;i++){
        data[i] = rand()%1000;
    }
}

void getFrequentItems(int data[]){
    struct Node *hashtable[10];
    int freq[10]={0};
    int max_freq = 0;
    for(int i=0;i<10;i++){
        hashtable[i] = (struct Node*)malloc(sizeof(struct Node));
        hashtable[i]->data = -1;
        hashtable[i]->next = NULL;
    }
    for(int i=0;i<SIZE;i++){
        int index = data[i]%10;
        insert(hashtable[index],data[i]);
        freq[index]+=1;
        if(freq[index]>max_freq)
            max_freq=freq[index];
    }
    printf("Frequent items with frequency %d are:\n",max_freq);
    for(int i=0;i<10;i++){
        if(freq[i]==max_freq){
            display(hashtable[i]);
        }
    }
}

int main(){
    int data[SIZE];
    generateData(data);
    printf("Data Generated\n");
    clock_t start = clock();
    getFrequentItems(data);
    clock_t end = clock();
    double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n",time_taken);
    return 0;
}