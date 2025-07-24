//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int voterCount = 0;
int choiceCount = 0;

typedef struct candidate{
    char name[50];
    int votes;
}Candidate;

Candidate candidates[5];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * castVote(void *arg)
{
    printf("\nNew Voter Entered!\n");
    pthread_mutex_lock(&lock);
    voterCount++;
    printf("Voter %d is currently voting...\n",voterCount);
    sleep(2);
    printf("There are currently %d voters.\n",voterCount);
    printf("Please choose your candidate:\n");
    printf("1 - Candidate A\n");
    printf("2 - Candidate B\n");
    printf("3 - Candidate C\n");
    printf("4 - Candidate D\n");
    printf("5 - Candidate E\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            candidates[0].votes++;
            break;
        case 2:
            candidates[1].votes++;
            break;
        case 3:
            candidates[2].votes++;
            break;
        case 4:
            candidates[3].votes++;
            break;
        case 5:
            candidates[4].votes++;
            break;
        default:
            printf("Please enter valid choice.\n");
    }
    choiceCount++;
    printf("Voter %d voted for candidate %d\n",voterCount, choice);
    pthread_mutex_unlock(&lock);
}

void displayResults(){
    printf("\n**********ELECTION RESULTS**********\n");
    int i;
    for(i=0;i<5;i++){
        printf("%s - %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main()
{
    strcpy(candidates[0].name, "Candidate A");
    strcpy(candidates[1].name, "Candidate B");
    strcpy(candidates[2].name, "Candidate C");
    strcpy(candidates[3].name, "Candidate D");
    strcpy(candidates[4].name, "Candidate E");

    int n;
    printf("Enter the number of voters: ");
    scanf("%d",&n);

    pthread_t voter_threads[n];

    int i;
    for(i=0;i<n;i++)
    {
        pthread_create(&voter_threads[i],NULL,&castVote,NULL);
        sleep(1);
    }

    for(i=0;i<n;i++){
        pthread_join(voter_threads[i],NULL);
    }

    displayResults();

    return 0;
}