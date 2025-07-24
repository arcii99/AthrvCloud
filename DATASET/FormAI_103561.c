//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include<stdio.h>
#include<ctype.h>

char *months[]={
    "January","February","March",
    "April","May","June",
    "July","August","September",
    "October","November","December"
};
char *suffix[]={"st","nd","rd","th"};
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

int get_year()
{
    char year[5];
    int y=0;
    printf("Enter year (yyyy): ");
    scanf("%s",year);
    for(int i=0;i<4;i++){
        if(!isdigit(year[i])){
            printf("Invalid input. Please enter a 4-digit year.\n");
            return get_year();
        }
        y=y*10+(year[i]-'0');
    }
    if(y<=0 || y>9999){
        printf("Invalid year.\n");
        return get_year();
    }
    return y;
}

int get_month()
{
    char month[10];
    int m=0;
    printf("Enter month (mm or month name): ");
    scanf("%s",month);
    if(isdigit(month[0])){
        for(int i=0;i<2;i++){
            if(!isdigit(month[i])){
                printf("Invalid input. Please enter a valid month in mm format.\n");
                return get_month();
            }
            m=m*10+(month[i]-'0');
        }
        if(m<=0 || m>12){
            printf("Invalid month.\n");
            return get_month();
        }
    }
    else{
        for(int i=0;i<12;i++){
            if(strcasecmp(month,months[i])==0){
                m=i+1;
                break;
            }
        }
        if(m==0){
            printf("Invalid input. Please enter a valid month.\n");
            return get_month();
        }
    }
    return m;
}

int get_day(int month,int year)
{
    char day[3];
    int d=0,leap=0,p=3;
    if(year%4==0){
        leap=1;
        if(year%100==0){
            leap=0;
            if(year%400==0)
                leap=1;
        }
    }
    if(month!=2)
        p=(month<8)?0:1;
    printf("Enter day (dd): ");
    scanf("%s",day);
    for(int i=0;i<2;i++){
        if(!isdigit(day[i])){
            printf("Invalid input. Please enter a valid day in dd format.\n");
            return get_day(month,year);
        }
        d=d*10+(day[i]-'0');
    }
    if(d<=0 || d>days[month-1]+(month==2?leap:0)){
        printf("Invalid day. Please enter a valid day for the given month and year.\n");
        return get_day(month,year);
    }
    return d;
}

void print_suffix(int day)
{
    if(day>=11 && day<=13){
        printf("th");
        return;
    }
    switch(day%10){
        case 1:
            printf("st");
            break;
        case 2:
            printf("nd");
            break;
        case 3:
            printf("rd");
            break;
        default:
            printf("th");
    }
}

int main()
{
    printf("Welcome to the C natural language date converter program.\n");
    printf("This program converts natural language inputs to date format (dd/mm/yyyy).\n");
    printf("Please enter the date in the format of either dd/mm/yyyy or natural language (e.g. 1st May, 2022 or May 1st, 2022).\n\n");
    while(1){
        int day=0,month=0,year=0;
        char input[20];
        printf("Enter the date: ");
        scanf("%20[^\n]%*c",input);
        sscanf(input,"%d",&day);
        int len=strlen(input);
        for(int i=0;i<12;i++){
            if(strncasecmp(input,months[i],strlen(months[i]))==0){
                month=i+1;
                break;
            }
        }
        sscanf(input+len-4,"%d",&year);
        if(day!=0 && month!=0 && year!=0){
            if(day>days[month-1]+(month==2? (year%4==0? (year%100!=0 || year%400==0):0):0)){
                printf("Invalid day for given month and year. Please enter a valid date.\n");
                continue;
            }
        }
        else if(day==0 && month!=0 && year!=0){
            day=get_day(month,year);
        }
        else if(day!=0 && month==0 && year!=0){
            printf("Invalid input. Please enter a valid date.\n");
            continue;
        }
        else if(day!=0 && month!=0 && year==0){
            printf("Invalid input. Please enter a valid date.\n");
            continue;
        }
        else if(day==0 && month==0 && year!=0){
            printf("Invalid input. Please enter a valid date.\n");
            continue;
        }
        else if(day==0 && month!=0 && year==0){
            year=get_year();
            day=get_day(month,year);
        }
        else if(day!=0 && month==0 && year==0){
            year=get_year();
            month=get_month();
            if(day>days[month-1]+(month==2? (year%4==0? (year%100!=0 || year%400==0):0):0)){
                printf("Invalid day for given month and year. Please enter a valid date.\n");
                continue;
            }
        }
        else{
            printf("Invalid input. Please enter a valid date.\n");
            continue;
        }
        printf("The date is %d",day);
        print_suffix(day);
        printf(" %s, %d\n",months[month-1],year);
        printf("Do you want to convert another date? (y/n): ");
        char choice=getchar();
        while(getchar()!='\n');
        if(choice=='n')
            break;
    }
    printf("Thank you for using the C natural language date converter program.\n");
    return 0;
}