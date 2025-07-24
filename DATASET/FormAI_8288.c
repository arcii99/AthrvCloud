//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

int main(){

    int count=0,isEmpty=1,n,t;  //top of the stack is initially pointing to NULL 
    int stack[MAX];              //stack declaration
    printf("\nEnter the number of bags\n");
    scanf("%d",&n);
    printf("\nEnter the sequence of bags entered into the stack\n");
    for(int i=0;i<n;i++){
        scanf("%d",&t);         //taking the input of bags sequence in the stack
        if(t==count+1){
            count++;           //counting the number of bags in the stack
            printf("Baggage %d is loaded to flight\n",t);
            while(!isEmpty && stack[isEmpty]==count+1){
                count++;
                printf("Baggage %d is loaded to flight\n",stack[isEmpty--]);      //removing the topmost element in the stack which is now ready to load into the flight
            }
        }
        else{
            stack[++isEmpty]=t;   //if the stack element is not ready then push it into the stack
        }
    }
    printf("\n The remaining baggage in the stack is:");
    for(int i=0;i<isEmpty;i++){
        printf("%d",stack[i]);   //analyzing the remaining bag names which are not loaded into the flight
    }
    printf("\nTotal number of bags loaded into the flight:%d",count);
    return 0;
}