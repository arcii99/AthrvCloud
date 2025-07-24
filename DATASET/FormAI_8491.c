//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include<stdio.h>

//Struct to hold Time
struct Time{
    int hour;
    int minute;
};

//Struct to hold Appointment
struct Appointment{
    char name[50];
    struct Time startTime;
    struct Time endTime;
};

//Function to get Time
struct Time getTime(){
    struct Time time;
    printf("Enter Hour: ");
    scanf("%d",&time.hour);
    printf("Enter Minute: ");
    scanf("%d",&time.minute);
    return time;
}

//Function to display Time
void displayTime(struct Time time){
    printf("%02d:%02d",time.hour,time.minute);
}

//Function to compare Time
int compareTime(struct Time time1,struct Time time2){
    if(time1.hour<time2.hour){
        return -1;
    }
    else if(time1.hour>time2.hour){
        return 1;
    }
    else{
        if(time1.minute<time2.minute){
            return -1;
        }
        else if(time1.minute>time2.minute){
            return 1;
        }
        else{
            return 0;
        }
    }
}

//Function to check for Appointment Conflict
int isConflict(struct Appointment appointment1,struct Appointment appointment2){
    int start1=compareTime(appointment1.startTime,appointment2.startTime);
    int end1=compareTime(appointment1.endTime,appointment2.startTime);
    int start2=compareTime(appointment2.startTime,appointment1.startTime);
    int end2=compareTime(appointment2.endTime,appointment1.startTime);
    if((start1==0)||(end1==0)||(start2==0)||(end2==0)){
        return 1;
    }
    else if((start1==1)&&(end2==1)){
        return 0;
    }
    else if((start2==1)&&(end1==1)){
        return 0;
    }
    else{
        return 1;
    }
}

//Function to input Appointment Details
struct Appointment getAppointmentDetails(){
    struct Appointment appointment;
    printf("Enter Name of the Appointment: ");
    scanf("%s",appointment.name);
    printf("Enter Starting Time of the Appointment:\n");
    appointment.startTime=getTime();
    printf("Enter Ending Time of the Appointment:\n");
    appointment.endTime=getTime();
    return appointment;
}

//Function to display Appointment Details
void displayAppointmentDetails(struct Appointment appointment){
    printf("%50s | ",appointment.name);
    displayTime(appointment.startTime);
    printf(" - ");
    displayTime(appointment.endTime);
}

//Function to add Appointment to Calendar
void addAppointment(struct Appointment calendar[],int *size){
    if((*size)>=50){
        printf("Calendar is Full!! Cannot add Appointment.\n");
        return;
    }
    struct Appointment appointment=getAppointmentDetails();
    for(int i=0;i<(*size);i++){
        if(isConflict(calendar[i],appointment)==1){
            printf("Conflicting Appointment!! Cannot add Appointment.\n");
            return;
        }
    }
    calendar[(*size)++]=appointment;
    printf("Appointment added Successfully!!\n");
}

//Function to remove Appointment from Calendar
void removeAppointment(struct Appointment calendar[],int *size,char name[]){
    int found=0;
    for(int i=0;i<(*size);i++){
        if(strcmp(calendar[i].name,name)==0){
            found=1;
            for(int j=i;j<(*size)-1;j++){
                calendar[j]=calendar[j+1];
            }
            (*size)--;
            printf("Appointment removed Successfully!!\n");
            break;
        }
    }
    if(found==0){
        printf("Appointment not found!! Cannot remove Appointment.\n");
    }
}

//Function to display Calendar
void displayCalendar(struct Appointment calendar[],int size){
    printf("\n");
    printf("%50s | %10s | %10s\n","Appointment Name","Start Time","End Time");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<size;i++){
        displayAppointmentDetails(calendar[i]);
        printf("\n");
    }
}

int main(){
    struct Appointment calendar[50];
    int size=0;
    printf("Welcome to Appointment Scheduler!!\n");
    int choice=1;
    while(choice!=4){
        printf("\n");
        printf("1.Add Appointment\n");
        printf("2.Remove Appointment\n");
        printf("3.Display Calendar\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addAppointment(calendar,&size);
                    break;
            case 2: char name[50];
                    printf("Enter Name of the Appointment to Remove: ");
                    scanf("%s",name);
                    removeAppointment(calendar,&size,name);
                    break;
            case 3: displayCalendar(calendar,size);
                    break; 
            case 4: break;
            default: printf("Invalid Choice!! Try Again!!\n"); 
        }
    }
    printf("Thank You for using Appointment Scheduler!!\n");
    return 0;
}