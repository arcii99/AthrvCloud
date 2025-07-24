//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generate_random_num(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if(min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } 
    else 
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

char *generate_random_theory(int num_calls)
{
    if(num_calls == 0)
    {
       return "The government is hiding the truth about global warming by using weather controlling machines!"; //base case
    }
    else
    {
        int theory_num = generate_random_num(1,7);
        char *theory;
        switch(theory_num)
        {
            case 1:
                theory = "The moon landing never happened and it was all a setup!";
                break;

            case 2:
                theory = "The government is hiding the existence of aliens from us!";
                break;

            case 3:
                theory = "The Illuminati is secretly controlling every aspect of our lives!";
                break;

            case 4:
                theory = "Drug companies are secretly hiding cures to diseases to keep making money!";
                break;

            case 5:
                theory = "The earth is really flat, but the government is hiding it from us!";
                break;

            case 6:
                theory = "Satanic cults are running the world and controlling all major governments!";
                break;

            case 7:
                theory = "The government is using chemtrails to control our minds and emotions!";
                break;

            default:
                theory = "The government is hiding the truth from us!";
        }

        char *recursive_theory = generate_random_theory(num_calls-1);
        char *final_theory = calloc(strlen(theory) + strlen(recursive_theory) + 5, sizeof(char));
        sprintf(final_theory,"%s And also, %s",theory,recursive_theory);
        free(recursive_theory);
        return final_theory;
    }
}

int main()
{
    char *conspiracy_theory = generate_random_theory(5);
    printf("%s\n", conspiracy_theory);
    free(conspiracy_theory);
    return 0;
}