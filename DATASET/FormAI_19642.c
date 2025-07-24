//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MIN_FLOOR 1
#define MAX_FLOOR 10
#define NO_OF_ELEVATORS 3

int queue[MAX_FLOOR+1]={0};
int dir[NO_OF_ELEVATORS]={1,1,1},pos[NO_OF_ELEVATORS]={1,1,1},dest[NO_OF_ELEVATORS]={0},flag[NO_OF_ELEVATORS]={0},c=0;
//queue will store the number of passengers waiting on each floor, dir will store the direction of each elevator, pos will store the current position of each elevator, dest will store the destination floor of each elevator, flag will be used to check if an elevator has reached its destination floor.
struct {
    int eid;
    int hd;
    int tl;
    int curr_floor;
    int dest_floor;
}elev[NO_OF_ELEVATORS];

//function to generate random number between min and max
int random_number_generator(int min,int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//function to print the elevator status and queue
void show_status()
{
    printf("\n");
    printf("Elevator Status: \n");
    for(int i=0;i<NO_OF_ELEVATORS;i++)
    {
        printf("Elevator %d: ",i+1);
        if(flag[i])
            printf("DESTINATION FLOOR REACHED\n");
        else
            printf("CURRENT FLOOR: %d    DESTINATION FLOOR: %d    DIRECTION: %s\n",pos[i],dest[i],dir[i]==1?"UP":"DOWN");
    }
    printf("\nQueue Status: \n");
    for(int i=1;i<=MAX_FLOOR;i++)
    {
        if(queue[i]!=0)
            printf("Floor %d: %d\n",i,queue[i]);
    }
}

//function to check if there are any waiting passengers
int is_queue_empty()
{
    for(int i=1;i<=MAX_FLOOR;i++)
    {
        if(queue[i]!=0)
            return 0;
    }
    return 1;
}

int main()
{
    srand(time(0));
    int i,j,k,l,eid=1;
    char c;
    for(i=0;i<NO_OF_ELEVATORS;i++)
    {
        elev[i].eid=eid++;
        elev[i].hd=0;
        elev[i].tl=-1;
        elev[i].curr_floor=random_number_generator(MIN_FLOOR,MAX_FLOOR);
        elev[i].dest_floor=random_number_generator(MIN_FLOOR,MAX_FLOOR);
        dir[i]=elev[i].dest_floor>elev[i].curr_floor?1:-1;
        if(dir[i]==1)
            pos[i]=elev[i].curr_floor-1;
        else
            pos[i]=elev[i].curr_floor+1;
        dest[i]=elev[i].dest_floor;
    }
    printf("\nELEVATOR SIMULATION\n");
    while(!is_queue_empty() || !c)
    {
        printf("\nPress Enter to Continue, or X to Exit\n");
        if((c=getchar())=='X'||c=='x')
            break;
        system("clear");
        //deciding which elevator to move first
        int first_elevator=-1,min_dist=MAX_FLOOR+1;
        for(i=0;i<NO_OF_ELEVATORS;i++)
        {
            //checking if elevator has reached its destination floor and its queue is empty
            if(flag[i]||elev[i].hd>elev[i].tl)
                continue;
            for(j=elev[i].hd;j<=elev[i].tl;j++)
            {
                if(dest[i]>elev[i].curr_floor)
                {
                    if(queue[elev[i].curr_floor+1]>0)
                    {
                        first_elevator=i;
                        break;
                    }
                }
                else
                {
                    if(queue[elev[i].curr_floor-1]>0)
                    {
                        first_elevator=i;
                        break;
                    }
                }
            }
            if(first_elevator!=-1)
                break;
        }
        //moving first elevator
        if(first_elevator!=-1)
        {
            if(dest[first_elevator]>elev[first_elevator].curr_floor)
            {
                dir[first_elevator]=1;
                pos[first_elevator]++;
                elev[first_elevator].curr_floor=pos[first_elevator];
            }
            else if(dest[first_elevator]<elev[first_elevator].curr_floor)
            {
                dir[first_elevator]=-1;
                pos[first_elevator]--;
                elev[first_elevator].curr_floor=pos[first_elevator];
            }
            else
            {
                flag[first_elevator]=1;
                queue[elev[first_elevator].curr_floor]=0;
            }
        }
        //checking for other elevators
        for(i=0;i<NO_OF_ELEVATORS;i++)
        {
            if(i==first_elevator)
                continue;
            if(flag[i])
                continue;
            if(dir[i]==1 && pos[i]!=MAX_FLOOR)
                pos[i]++;
            else if(dir[i]==-1 && pos[i]!=MIN_FLOOR)
                pos[i]--;
            else if(pos[i]==MAX_FLOOR || pos[i]==MIN_FLOOR)
                dir[i]*=-1;
            elev[i].curr_floor=pos[i];
        }
        //adding passengers to queue
        for(i=1;i<=MAX_FLOOR;i++)
        {
            int count=random_number_generator(0,3);
            for(j=0;j<count;j++)
                queue[i]++;
        }
        for(i=0;i<NO_OF_ELEVATORS;i++)
        {
            if(flag[i] || elev[i].hd<=elev[i].tl)
                continue;
            int dest_floor=elev[i].dest_floor;
            if(queue[dest_floor]==0)
                continue;
            if(pos[i]<dest_floor)
                dir[i]=1;
            else if(pos[i]>dest_floor)
                dir[i]=-1;
            else
                flag[i]=1;
            dest[i]=dest_floor;
        }
        show_status();
    }
    printf("\nExiting Elevator Simulation...\n");
    return 0;
}