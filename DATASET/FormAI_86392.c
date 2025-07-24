//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(char* msg){
    int i = 0;
    while(msg[i] != '\0'){
        printf("%c", msg[i]);
        i++;
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int bootTime = rand() % 100;
    char* optimizeMsg = "Booting in progress...";
    display(optimizeMsg);
    int i;
    for(i=0;i<bootTime;i++){
        printf("%d percent complete.\n", i+1);
    }
    char* successMsg = "System booting optimized successfully!";
    display(successMsg);
    return 0;
}