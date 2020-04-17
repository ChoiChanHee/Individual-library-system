#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[], int *count);
void display_menu();

// main function
int main(){

  int count=0;
char buff[MAX];
   Record records[MAX_RECORDS];
   char user_input[64] = "";

  read_DF(records, &count);

 FILE* fp=NULL;
  fp= fopen("member.txt", "w");

  if(fp ==NULL){
    printf("%s: file does not open.\n", "member.txt");
    exit(-1);
  }

   while(strcmp(user_input, "99") != 0){
      display_menu();
      printf("\nSelect a menu> ");
      fgets(user_input, 64, stdin);
      user_input[strlen(user_input)-1] = '\0';
      input_handler(user_input, records, &count);
   }
   sorting_data(records, count);//sorting (extra)
  for(int i=0; i<count; i++){
  if(i==0)
  fprintf(fp, "%s %s %s %s %s %s", records[i].name, records[i].p_num, records[i].bd, records[i].id, records[i].pw, records[i].book);
   else
     fprintf(fp, "\n%s %s %s %s %s %s", records[i].name, records[i].p_num, records[i].bd, records[i].id, records[i].pw, records[i].book);
}
store_data(records, count);
fclose(fp);
   return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[], int *count){
   // TODO: Modify this function as you need
  char buff[MAX];
  int result=0;
   if(!strcmp(input, "1")){
   records[*count]=sign_in(records, *count);
  (*count)++;
  }
   else if(!strcmp(input, "2")){
    int n=Login(records, *count);
    if(n!=-1){
    result=display_login(records, n, count);
      if(result == 5)
      if(defragment(records, n, count)){//extra
       printf("\n Successfully deleted yout account and data. Thank you.\n");
        }
    return;
    }
    else{
    printf("\ndoes not exist account, or wrong password\n");
    scanf("%c", buff);
    }
  }   
   else if(!strcmp(input, "3"))
      forget_id(records, *count);
   else if(!strcmp(input, "4"))
      forget_pw(records, *count);
   else if(!strcmp(input, "5"))
      the_most_like_genre(records, *count);
   else if(!strcmp(input, "99"))
      printf(""); // Quit - no operation (an empty statement with a semi-colon)
   else
      printf("Unknown menu: %s", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

   // TODO: Modify this function as you need
   printf("******************************\n");
   printf(" Individule library system \n");
   printf("******************************\n");
   printf(" 1. Creat Account\n");
   printf(" 2. Log in\n");
   printf(" 3. Forgot ID?\n");
   printf(" 4. Forgot Password?\n");
   printf(" 5. The most popular genre\n");
   printf(" 99. Quit\n");
}
