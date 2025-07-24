//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include<stdio.h>

int main(){
    printf("Ah, Watson, good to see you. I am trying to solve this case, but I think I need your help with some code.\n");
    printf("\n");
    printf("The case involves a theft of a precious gem from the museum. The thief left some clues, but no fingerprints or footprints were found. The only thing we have is that the thief came from the North side of town.\n");
    printf("\n");
    printf("Here, let me show you the clues:\n\n");
    printf("\"The thief left 3 pieces of evidence. The first one is a wallet with a few dollars, the second one is an empty bottle of scotch, and the third one is a torn piece of paper with some numbers on it.\"\n");
    printf("\n");
    printf("We have to find out who the thief is and where he is hiding. I was thinking of using a Greedy Algorithm to solve this case. What do you think, Watson?\n");
    printf("\n");
    printf("Watson: Yes, Holmes, I think that's a good idea. We can use a Greedy Algorithm to narrow down the suspects based on the evidence we have.\n");
    printf("\n");
    printf("Holmes: Quite right, Watson. The first piece of evidence is a wallet with some dollars. Let's start by eliminating anyone who doesn't have a wallet. Here's our code:\n");

    int wallets[5] = {1,0,1,0,1};
    int i,j,total_suspects = 5;
    printf("\n");
    printf("Suspects with wallets:\n");
    for(i=0;i<total_suspects;i++){
        if(wallets[i]==1){
            printf("Suspect %d\n",i+1);
        }
    }
    printf("\n");
    printf("Holmes: That narrows down the list to 3 suspects. Let's move on to the second piece of evidence, which is an empty bottle of scotch. We know that only 2 suspects drink scotch. Here's the code:\n");

    int scotch[5] = {0,1,1,0,0};
    int scotch_count = 0;
    printf("\n");
    printf("Suspects who drink scotch:\n");
    for(i=0;i<total_suspects;i++){
        if(scotch[i]==1){
            printf("Suspect %d\n",i+1);
            scotch_count++;
        }
    }
    printf("\n");
    printf("Holmes: Excellent, Watson. We now have 2 suspects. Let's move on to the third piece of evidence, which is a torn piece of paper with some numbers on it. It looks like some kind of an address. We know that the thief came from the North side of town, so we can eliminate anyone who doesn't live on the North side. Here's the code:\n");

    int north[5] = {1,0,1,0,0};
    int north_count = 0;
    printf("\n");
    printf("Suspects who live on the North side:\n");
    for(i=0;i<total_suspects;i++){
        if(north[i]==1){
            printf("Suspect %d\n",i+1);
            north_count++;
        }
    }
    printf("\n");
    printf("Holmes: Well done, Watson. We have narrowed down the list to just one suspect. Let's see who it is.\n");

    if(scotch_count == 1 && north_count == 1){
        printf("It's Suspect 3!\n");
    }else{
        printf("It looks like we need more evidence to solve this case.\n");
    }
    
    printf("\n");
    printf("Watson: Another job well done, Holmes.\n");
    printf("Holmes: Indeed, Watson. Let's move on to the next case.\n");

    return 0;
}