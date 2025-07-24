//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include<stdio.h>
#include<math.h>
#include<string.h>

int attackLevel = 0; //initializing attack level to zero

//function to detect possible intrusions
void detectIntrusion(char* input){
    int length = strlen(input);
    if (length > 100) { //detect input greater than 100
        printf("Possible intrusion detected: Large input\n");
        attackLevel++;
    }
    if (strstr(input, "harmful code")!=NULL){ //detect attack strings
        printf("Possible intrusion detected: Harmful code detected\n");
        attackLevel++;
    }
    if (strstr(input, "shutdown system")!=NULL){
        printf("Possible intrusion detected: System shutdown detected\n");
        attackLevel+=2;
    }
    if (strstr(input, "root access")!=NULL){//detect unauthorized access
        printf("Possible intrusion detected: Unauthorized root access\n");
        attackLevel+=3;
    }
}

//function to recursively read input and detect intrusions
void readInput(){
    char input[500];
    printf("Enter input: "); //prompt user for input
    scanf("%s", input);
    detectIntrusion(input); //call detectIntrusion function

    if (attackLevel >= 6){ //check attack level
        printf("Attack level exceeds limit. System shutting down...\n");
        exit(0);
    }
    else {
        printf("No intrusion detected. Continuing...\n");
        readInput();
    }
}

int main(){
    printf("Intrusion Detection System: Recursive Style\n");
    readInput(); //call readInput function
    return 0;
}