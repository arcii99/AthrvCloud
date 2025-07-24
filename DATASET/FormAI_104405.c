//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include<stdio.h>
int main(){
    printf("Hello, I'm your smart home assistant!\n");

    while(1){
        printf("What do you want me to do?: ");
        char command[20];
        scanf("%s",command);

        if(strcmp(command,"turn on lights")==0){
            printf("Sure, turning on the lights! You can see your messy room now.\n");
        }
        else if(strcmp(command,"turn off lights")==0){
            printf("Okay, lights are off. Be careful not to step on anything in the darkness.\n");
        }
        else if(strcmp(command,"play music")==0){
            printf("Let's groove! Playing some funky tunes.\n");
        }
        else if(strcmp(command,"open curtains")==0){
            printf("Tada! The sun is shining in. Time to wake up.\n");
        }
        else if(strcmp(command,"close curtains")==0){
            printf("Goodnight! The curtains are closed now. Time to sleep.\n");
        }
        else if(strcmp(command,"make coffee")==0){
            printf("Bloop bloop! The coffee is brewing. You're welcome!\n");
        }
        else if(strcmp(command,"order pizza")==0){
            printf("Yum! Pizza is on the way. You're getting fatter.\n");
        }
        else if(strcmp(command,"water plants")==0){
            printf("Glub glub! Your plants are hydrated. They said thanks.\n");
        }
        else if(strcmp(command,"clean house")==0){
            printf("I'm sorry, Dave. I'm afraid I can't do that.\n");
        }
        else{
            printf("I don't know how to %s. Please give me valid commands.\n",command);
        }
    }
    return 0;
}