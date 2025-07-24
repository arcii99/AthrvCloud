//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
  int id;
  char name[20];
  char grade[5];
};

int main(){
  struct student stu_list[5];
  int n,i;
  printf("Enter the number of students:\n");
  scanf("%d",&n);
  for(i=0; i<n; i++){
    printf("Enter student ID, name and grade for student %d:\n",i+1);
    scanf("%d %s %s",&stu_list[i].id,stu_list[i].name,stu_list[i].grade);
  }
  printf("Enter the student ID to search:\n");
  int search_id;
  scanf("%d",&search_id);
  int found_index=-1;
  for(i=0; i<n; i++){
    if(stu_list[i].id==search_id){
      found_index=i;
      break;
    }
  }
  if(found_index!=-1){
    printf("Student details:\n");
    printf("ID: %d\n",stu_list[found_index].id);
    printf("Name: %s\n",stu_list[found_index].name);
    printf("Grade: %s\n",stu_list[found_index].grade);
  }
  else{
    printf("No student found with ID %d\n",search_id);
  }  
  return 0;
}