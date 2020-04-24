#include <stdio.h>
#include "base.h"
#include "extras.h"
#include <stdlib.h>
#include <string.h>
// Function: void read_DF()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void read_DF(Record save[], int *c){

   FILE* fp=NULL;
  fp= fopen("member.txt", "r");

  if(fp ==NULL){
    printf("%s: file does not open.\n", "member.txt");
    exit(-1);
  }
int n=0;
  while(1){
  n= fscanf(fp, "%s %s %s %s %s %s\n", save[*c].name, save[*c].p_num, save[*c].bd, save[*c].id, save[*c].pw, save[*c].book);
  if(n==EOF)
  break;

  
  (*c)++;
  }
fclose(fp);
}

int is_same(Record save[], char d[], int count){
  int check=0;
  for(int i=0; i<count; i++){
  if(!(strcmp(save[i].id, d)))
  return 0;
  }
  return 1;
}
int is_over(char d[]){
  if(strlen(d)>16)
  return 0; 
  return 1;
}


Record sign_in(Record save[], int c){
   // TODO: Modify this function as you need
  Record a;
  char buff[MAX];
  char d[MAX]="";

   printf("your name: ");
  scanf("%s", d);
  scanf("%c", buff);
  a.name[strlen(d)]='\0';
  strncpy(a.name, d, strlen(d));
  

   printf("your phone number: ");
  scanf("%s", d);
  scanf("%c", buff);
  a.p_num[strlen(d)]='\0';
  strncpy(a.p_num, d, strlen(d));

  printf("your birthday: ex)DD/MM/YYYY: ");
  scanf("%s", d);
  scanf("%c", buff);
  while(!(d[2]=='/' && d[5]=='/')){
    d[0]='\0';
    printf("please enter your birthday like example\n");
    scanf("%s", d);
  }
  a.bd[strlen(d)]='\0';
  strncpy(a.bd, d, strlen(d));
  


  printf("set your id: ");
  scanf("%s", d);
  scanf("%c", buff);
   while(!((is_over(d)) && (is_same(save, d, c)))){
     d[0]='\0';
      printf("Error. \nyour id is over 16 characters or does already exist. please use other id: "); 
      scanf("%s", d);
  scanf("%c", buff);
    }
  a.id[strlen(d)]='\0';
  strncpy(a.id, d, strlen(d));


  printf("set your password: ");
  scanf("%s", d);
  scanf("%c", buff);
   while(!(is_over(d))){
      printf("Error. \nyour password is over 16 characters. please use other pw: ");
      d[0]='\0';
    scanf("%s", d);
  scanf("%c", buff);
  }
  a.pw[strlen(d)]='\0';
  strncpy(a.pw, d, strlen(d));

  printf("Which genre do you like? \n(NOVEL : N)(MISTERY : M)\n(SPORT : S)(CARTOON : C)\n(BEAUTY : B)(FATRION : F) : ");
  scanf("%s", d);
  scanf("%c", buff);
  a.book[strlen(d)]='\0';
  strncpy(a.book, d, strlen(d));


  return a;

}

void forget_id(Record a[], int count){
  char c_name[SIZE];
  char c_pnum[SIZE];
  char c_bd[SIZE];
  char buff[MAX];
  printf("what is your name?: ");
  scanf("%s", c_name);
  printf("what is your phone number?: ");
  scanf("%s", c_pnum);
  printf("when is your birthday?: ex)DD/MM/YYYY ");
  scanf("%s", c_bd);

  for(int i=0; i<count; i++){
    if(!(strcmp(a[i].name, c_name))){
      if(!(strcmp(a[i].p_num, c_pnum))){
        if(!(strcmp(a[i].bd, c_bd)))
        printf("\nYour ID is %s\n\n", a[i].id);
        scanf("%c", buff);
        return;
      }
    }
  }
   printf("\nWe don't hava any accounts with your information\n\n");
    scanf("%c", buff);
}

void change_pw_forget(Record a[], int n){
  char input_pw_f[SIZE]="";
  char input_pw_s[SIZE]="";
  char buff[MAX];
    printf("\nChange your password: ");
    scanf("%s", input_pw_f);
    scanf("%c", buff);
    while(!(is_over(input_pw_f))){
      printf("Error. \nyour password is over 16 characters. please use other pw: ");
      input_pw_f[0]='\0';
      scanf("%s", input_pw_f);
      scanf("%c", buff);
      }
    printf("Write one more time: ");
    scanf("%s", input_pw_s);
    scanf("%c", buff);
    if(!(strcmp(input_pw_f, input_pw_s))){
   a[n].pw[0]='\0';
   strncpy(a[n].pw, input_pw_s, strlen(input_pw_s));
   printf("DONE\n");
    }
    else{
      printf("The two passwords do not match. Try again.");
      change_pw_forget(a, n);
    }
}

void forget_pw(Record a[], int count){
  char c_name[SIZE]="";
  char c_id[SIZE]="";
  char c_pnum[SIZE]="";
  char c_bd[SIZE]="";
  char buff[MAX];
  int checker=0;
  int n=0;
  printf("what is your name?: ");
  scanf("%s", c_name);
  printf("what is your ID?: ");
  scanf("%s", c_id);
  printf("what is your phone number?: ");
  scanf("%s", c_pnum);
  printf("when is your birthday?: ex)DD/MM/YYYY ");
  scanf("%s", c_bd);

  for(int i=0; i<count; i++){
    if(!(strcmp(a[i].name, c_name))){
      if(!(strcmp(a[i].id, c_id))){
      if(!(strcmp(a[i].p_num, c_pnum))){
        if(!(strcmp(a[i].bd, c_bd))){
          checker +=1;
          n=i;
          break;
          }
        }
      }
    }
  }
  if(checker == 1){
    change_pw_forget(a, n);
    }
  else{
    printf("\nWe don't hava any accounts with your information\n");
    scanf("%c", buff);
    }
  }

int Login(Record save[], int count){
  char c_id[SIZE];
  char c_pw[SIZE];
printf("Enter your id: ");
scanf("%s", c_id);
printf("Enter your password: ");
scanf("%s", c_pw);

for(int i=0; i<count; i++){
  if(!(strcmp(save[i].id, c_id))){
    if(!(strcmp(save[i].pw, c_pw))){
      printf("\nWelcome, %s", save[i].name);
    return i;
    }
  }
}
return -1;
}

int display_login(Record a[], int n, int *c){
  int num=0;
  int result=0;
  char buff[MAX];
 
 do {
  printf("\n******************************\n");
  printf(" 1. My account\n");
  printf(" 2. My liabrary\n");
  printf(" 3. Add Book \n");
  printf(" 4. Delete book\n");
  printf(" 5. Delete my account\n");
  printf(" 6. go back to menu\n");
  printf("\nSelect a menu> ");
  scanf("%d", &num);
   
  if(num==1){
    printf("\nyour name is: %s\nyour birth day is: %s\nyour phone number is: %s\n", a[n].name, a[n].bd, a[n].p_num);
  }
else if(num==2){
    show_lib(a, n, *c);
  }
else if(num==3){
    add_book(a, n, *c);
  }
else if(num==4){
    delete_book(a, n, *c);
  }
else if(num==5){ //delete part
  delete_account(a, n, c);
  return 5;
  }
else if(num==6){
  scanf("%c", buff);
  break;
  }  
else
  printf("Unknown menu: %d\n", num);
  } while(!( num==6));
  return 1;
}
void show_lib(Record a[], int n, int c){

  char fname[MAX]="";
  char show[MAX]="";

  FILE*fp =NULL;
  strncat(fname, "book/", 5);
  strncat(fname, (a[n].name), strlen((a[n].name)));
  strncat(fname, ".txt", 4);
  
  fp= fopen(fname, "r");

    if(fp ==NULL){
    printf("\nNONE\n");
      return;
    }

  int q=0;
  while(1){
  q= fscanf(fp, "%s", show);
  if(q==0){
    printf("\nNONW\n");
  }
  if(q==EOF)
  break;
   printf("%s ", show);
  }
  fclose(fp);
printf("\n");
}

void add_book(Record a[], int n, int c){

FILE*fp =NULL;
char fname[MAX]="";
  strncat(fname, "book/", 5);
  strncat(fname, (a[n].name), strlen((a[n].name)));
  strncat(fname, ".txt", 4);
  
  fp= fopen(fname, "a");

    if(fp ==NULL){
    printf("\nnone. Add books!\n");
      return;
    }
  printf("Write the book's name. \n* use underbar instead of spacebar*\n ex) The_Old_Man_and_The_Sea: ");
  char save[MAX]="";

  scanf("%s", save);
  fprintf(fp, "%s ", save);


  fclose(fp);
printf("\n");
}

void delete_book(Record a[], int n, int c){

   char fname[MAX]="";
  char show[MAX]="";
  char input[MAX]="";
  FILE*fp =NULL;
  FILE*save =NULL;
  strncat(fname, "book/", 5);
  strncat(fname, (a[n].name), strlen((a[n].name)));
  strncat(fname, ".txt", 4);
  
  fp= fopen(fname, "r");
    if(fp ==NULL){
    printf("\nNONE\n");
      return;
    }

  int q=0;
  while(1){
  q= fscanf(fp, "%s", show);
  if(q==0){
    printf("\nNONW\n");
    return;
  if(q==EOF)
  break;
   printf("%s ", show);
  }
  }
fclose(fp);
 fp= fopen(fname, "r");
 save= fopen("book/save_data.txt", "w");
 printf("\nEnter a title of book to delete: ");
  scanf("%s", input);
  int r=0;
  show[0]='\0';
  while(1){
  r= fscanf(fp, "%s", show);
   if(r==EOF){
    printf("DONE");
    break;
  }
  if((strcmp(show, input)))
  fprintf(save, "%s ", show);

  }

  fclose(fp);
  remove(fname);
  fclose(save);
  rename("book/save_data.txt", fname);
}

int delete_account(Record a[], int n, int *c){
  
  char c_pw[SIZE]="";
  char check;
  char buff[MAX];
  int checker=0;
  char fname[MAX]="";
  
  strncat(fname, "book/", 5);
  strncat(fname, (a[n].name), strlen((a[n].name)));
  strncat(fname, ".txt", 4);
  
  printf("Write your password agian:  ");
  scanf("%s", c_pw);
  scanf("%c", buff);

  if(!(strcmp(a[n].pw, c_pw))){
    printf("\nAre you sure? (y/n): ");
    scanf("%c", &check);
    scanf("%c", buff);
    if(check=='y'){
      a[n].name[0]='\0';
      a[n].p_num[0]='\0';
      a[n].bd[0]='\0';
      a[n].id[0]='\0';
      a[n].pw[0]='\0';
      a[n].book[0]='\0';
      //scanf("%c", buff);
      remove(fname);
      return 1;;
    
    return 0;
    }
    if(check=='n')
    return 0;
    else{
    printf("write only 'y' or 'n'");
    scanf("%c", buff);
    return 0;
    }
  }
  printf("\nYour password does not match\n");
  scanf("%c", buff);
  return 0;
}
void store_data(Record a[], int count){

  FILE*fp=NULL;


  fp= fopen("a.txt", "w");
   fprintf(fp, "%s", "N: NOVEL || M: MISTERY || S: SPORT || C: CARTOON || B: BEAUTY || F: FATRION \n");
  for(int i=0; i<count; i++){

    fprintf(fp, "%s\n", "=============================");
    fprintf(fp, "NAME : %s\nPHONE NUM : %s\nBIRTH DAY : %s\nID : %s\nPW : %s\nPREFER GENRE : %s\n", a[i].name, a[i].p_num, a[i].bd, a[i].id, a[i].pw, a[i].book);
  }
  fclose(fp);
}

