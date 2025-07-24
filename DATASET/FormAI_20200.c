//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct medicine{
    char med_name[40];
    int price;
    int stock;
};
 
int main(){
    int choice;
    int i, add, flag;
    char mname[40];
    struct medicine med[100];
 
    med[0].price=20;
    strcpy(med[0].med_name,"Paracetamol");
    med[0].stock=10;
    
    med[1].price=50;
    strcpy(med[1].med_name,"Crocin");
    med[1].stock=15;
    
    med[2].price=100;
    strcpy(med[2].med_name,"Cetirizine");
    med[2].stock=5;
 
    do{
        printf(" \n\n");
        printf("Medical Store Management System \n");
        printf("-------------------------------\n");
        printf("1.View Medicine List \n");
        printf("2.Add Medicine \n");
        printf("3.Check stock of a medicine \n");
        printf("4.Exit \n");
        
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            
            case 1:
                printf("\n Medicine List: \n");
                printf("-----------------\n\n");
                printf("\tMedicine Name\t  Price\t Stock\n\n");
                
                for(i=0; i<3; i++){
                    printf("\t%s\t%d\t%d\n", med[i].med_name, med[i].price, med[i].stock);
                }
                
                break;
                
            case 2:
                printf("\n Enter the number of medicines you want to add: ");
                scanf("%d",&add);
                printf("\n");
                
                for(i=3; i<add+3; i++){
                    flag=0;
                    
                    printf("Enter Medicine Name: ");
                    scanf("%s",med[i].med_name);
                    
                    printf("Enter Medicine Price: ");
                    scanf("%d",&med[i].price);
                    
                    printf("Enter Stock Count: ");
                    scanf("%d",&med[i].stock);
                    
                    for(int j=0; j<i; j++){
                        if(strcmp(med[j].med_name, med[i].med_name)==0){
                            flag=1;
                            med[j].stock+=med[i].stock;
                            break;
                        }
                    }
                    
                    if(flag==0){
                        printf("\n Medicine added successfully\n");
                    }
                    else{
                        printf("\nExisting medicine stock updated successfully\n");
                    }
                }
                break;
                
            case 3:
                printf("\n Enter the medicine name: ");
                scanf("%s",mname);
                printf("\n");
                flag=0;
                
                for(i=0; i<3; i++){
                    if(strcmp(med[i].med_name,mname)==0){
                        printf("Medicine found: ");
                        printf("\n Medicine Name:%s\t Price:%d\t Stock:%d \n",med[i].med_name,med[i].price,med[i].stock);
                        flag=1;
                        break;
                    }
                }
                
                if(flag==0){
                    printf("\n Medicine not found\n");
                }
                
                break;
                
            case 4:
                printf("\n\nExiting Medical Store System...\n\n");
                break;
                
            default:
                printf("\nInvalid choice entered\n");
                
        }
    }while(choice!=4);

    return 0;
}