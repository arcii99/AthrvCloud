//FormAI DATASET v1.0 Category: Arithmetic ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //seed the random number generator with the current time
    
    int knights = 10;
    int dragons = 3;
    int arrow_damage = rand()%10 + 1; //randomize arrow damage between 1 and 10
    int sword_damage = rand()%5 + 1; //randomize sword damage between 1 and 5
    int total_damage = 0;
    
    printf("A group of %d knights are on a quest to slay %d dragons!\n", knights, dragons);
    printf("The knights have two weapons at their disposal: bows and swords\n");
    
    for(int i=1; i<=dragons; i++){ //loop through each dragon
        printf("\nDragon %d approaches!\n", i);
        int dragon_health = rand()%20 + 1; //randomize dragon health between 1 and 20
        
        while(dragon_health > 0){ //keep attacking the dragon until it is defeated
            int attack_type = rand()%2 + 1; //randomize attack type between 1 and 2
            
            if(attack_type == 1){ //bow attack
                printf("The knights fire their bows!\n");
                int damage = knights * arrow_damage; //calculate total damage from the bows
                printf("The dragons takes %d damage from the arrows!\n", damage);
                dragon_health -= damage;
            }
            else{ //sword attack
                printf("The knights charge with their swords!\n");
                int damage = knights * sword_damage; //calculate total damage from the swords
                printf("The dragon takes %d damage from the swords!\n", damage);
                dragon_health -= damage;
            }
            
            if(dragon_health <= 0){ //dragon has been defeated
                printf("The dragon has been defeated!\n");
                break;
            }
            
            printf("The dragon has %d health remaining\n", dragon_health);
            
            //dragon counterattacks
            printf("The dragon launches a counterattack!\n");
            int knight_casualties = rand()%knights + 1; //randomize number of knights to die between 1 and the total number of knights
            knights -= knight_casualties;
            printf("%d knights are killed in the counterattack!\n", knight_casualties);
            printf("There are %d knights remaining\n", knights);
            
            if(knights <= 0){ //all knights have been killed
                printf("The dragon has killed all the knights, quest failed!\n");
                return 0;
            }
        }
        
        printf("The knights have defeated dragon %d! Onto the next one!\n", i);
        total_damage += (10 - knights) * 2 * sword_damage; //calculate total damage dealt
        knights = 10; //reset the number of knights for the next dragon
    }
    
    printf("All the dragons have been slain, the quest is a success!\n");
    printf("The knights dealt a total of %d damage to the dragons!\n", total_damage);
    
    return 0;
}