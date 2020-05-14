Individual-library-system
=========================
# It is a system that adds and deletes books after creating accounts.

***

## record.h
  member of struct :
	  char id[SIZE];   
    char pw[SIZE];   
    char name[SIZE];   
    char p_num[SIZE];//phone number   
    char bd[SIZE];//birth day   
    char book[MAX];//user's favorite genre   

***

## CRUD

  ### CREATE
  
    1. void create_new_account_file(Record save[], int c) // Create a new data record from a data file   
    2. Record create_new_account(Record save[], int c) // Create a new record from the standard input
  
  ### READ
    
    1. 
