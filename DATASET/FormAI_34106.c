//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(){

    int num_lights = 3;
    int light_states[3] = {0,0,0};
    char light_names[3][10] = {"Living Room", "Kitchen", "Bedroom"};

    printf("Welcome to Smart Home Light Control System\n");
    printf("Currently, %d lights are available for control\n\n",num_lights);

    while(1){
        printf("Please select a light to control:\n");
        for(int i=0; i<num_lights; i++){
            printf("%d: %s (%s)\n",i+1,light_names[i],light_states[i]?"ON":"OFF");
        }
        printf("%d: Quit\n",num_lights+1);

        int choice;
        scanf("%d",&choice);

        if(choice==num_lights+1){
            printf("Thank you for using Smart Home Light Control System!\n");
            break;
        }
        else if(choice<=num_lights){
            printf("\n%s is currently %s\n",light_names[choice-1],light_states[choice-1]?"ON":"OFF");
            printf("Do you want to turn it %s? (1-YES, 0-NO) ",light_states[choice-1]?"OFF":"ON");
            int to_turn;
            scanf("%d",&to_turn);
            if(to_turn==1){
                light_states[choice-1] = light_states[choice-1]?0:1;
                printf("%s turned %s\n",light_names[choice-1],light_states[choice-1]?"ON":"OFF");
            }
            else{
                printf("No changes made\n");
            }
        }
        else{
            printf("Invalid Choice!\n");
        }

        printf("\n");

    }

    return 0;
}