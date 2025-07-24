//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include<stdio.h>
#include<string.h>

//function to convert date from natural language to date format
char* convertDate(char* input){
    char month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char number[31][3]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
    char* word;
    char* day;
    char* year;
    char* output;
    int i, j=0;
    int monthflag=0, numflag=0;

    //splitting the input string into words
    word=strtok(input," ");

    //iterate through all the words in the string
    while(word!=NULL){

        //check if word is a month name
        for(i=0;i<12;i++){
            if(strcmp(month[i],word)==0){
                strcat(output,number[i]);
                strcat(output,"/");
                monthflag=1;
                break;
            }
        }

        //check if word is a number between 0-31
        for(i=0;i<31;i++){
            if(strcmp(number[i],word)==0){
                day=word;
                numflag=1;
                break;
            }
        }

        //check if word is a year
        if(strlen(word)==4){
            year=word;
        }

        //move to next word
        word=strtok(NULL," ");
    }

    //if month is not found in the input string, ask for input again
    if(monthflag==0){
        printf("Sorry, the month was not found in the input. Please enter date again.\n");
        return "";
    }

    //if day is not found in the input string, ask for input again
    if(numflag==0){
        printf("Sorry, the day was not found in the input. Please enter date again.\n");
        return "";
    }

    //concatenate day and year to form output string
    strcat(output,day);
    strcat(output,"/");
    strcat(output,year);

    return output;
}

int main(){
    //input string
    char input[100];

    //output string
    char* output;

    //ask user for input
    printf("Please enter the date in natural language format (e.g. May 1 2022):\n");
    fgets(input,sizeof(input),stdin);

    //remove newline character from input string
    input[strcspn(input,"\n")]=0;

    //call convertDate function to convert input to date format
    output=convertDate(input);

    //print output
    printf("The date in date format is: %s\n",output);

    return 0;
}