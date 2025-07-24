//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fireWall(char *string, int index){
    if(index == strlen(string)){
        printf("Firewall blocked all the incoming traffic!\n");
        return;
    }
    if(string[index] != '0' && string[index] != '1'){
        printf("Invalid input!\n");
        return;
    }
    if(string[index] == '0'){
        printf("Passing traffic: %c\n", string[index]);
        fireWall(string, index+1);
    }
    else{
        printf("Blocking traffic: %c\n", string[index]);
        fireWall(string, index+1);
    }
}

int main(){
    char input[100];
    printf("Enter 1s and 0s to test firewall:\n");
    scanf("%s", input);
    fireWall(input, 0);
    return 0;
}