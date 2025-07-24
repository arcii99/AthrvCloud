//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include<stdio.h>

/*
This program parses a simple C syntax to identify the presence of loops and conditional statements.

*/
int main(){

    int i = 0;
    int num_loops=0;
    int num_conditions=0;

    char buffer[1000];

    printf("Enter a C syntax to be parsed:\n");

    //Read the input C syntax from user
    scanf("%[^\n]s", &buffer);

    //Check for presence of loops
    for(i=0;i<strlen(buffer);i++){
        if(buffer[i] == 'f' && buffer[i+1] == 'o' && buffer[i+2] == 'r'){
            num_loops++;
        }
        else if(buffer[i] == 'w' && buffer[i+1] == 'h' && buffer[i+2] == 'i' && buffer[i+3] == 'l' && buffer[i+4] == 'e'){
            num_loops++;
        }
        else if(buffer[i]=='d' && buffer[i+1]=='o'){
            num_loops++;
        }
    }

    //Check for presence of conditional statements
    for(i=0;i<strlen(buffer);i++){
        if(buffer[i] == 'i' && buffer[i+1] == 'f'){
            num_conditions++;
        }
        else if(buffer[i] == 'e' && buffer[i+1] == 'l' && buffer[i+2] == 's' && buffer[i+3] == 'e'){
            num_conditions++;
        }
        else if(buffer[i]=='s' && buffer[i+1]=='w' && buffer[i+2]=='i' && buffer[i+3]=='t' && buffer[i+4]=='c' && buffer[i+5]=='h'){
            num_conditions++;
        }
    }

    printf("Number of loops in the input syntax:%d\n",num_loops);
    printf("Number of conditional statements in the input syntax:%d\n",num_conditions);

    return 0;
}