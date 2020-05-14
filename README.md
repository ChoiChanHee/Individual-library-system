Individual-library-system
=========================
It is a system that adds and deletes books after creating accounts.

***

## record.h
  member of struct :   
  
    char id[SIZE];   
    char pw[SIZE];   
    char name[SIZE];   
    char p_num[SIZE]; -> phone number   
    char bd[SIZE]; -> birth day   
    char book[MAX]; -> user's favorite genre   

***

## **CRUD**

  ### CREATE
  
    1. void create_new_account_file()   
      --> Create a new data record from a data file   
    2. Record create_new_account()   
      -->Create a new record from the standard input
  
  ### READ
    
    1. void show_the_information() // According to user specified conditions, print multiple or all records to the standard output
    2. void forget_id() // According to user specified conditions, print a record to the standard output
    3. void read_DF() // Read/write the entire data from/to filesystem
    4. void store_data() // Export the entire data in a report format as a .txt file
    
  ### UPDATE
  
    1. void change_information() // Update multiple or all records
    2. void change_pw_forget() // Update a specific field of a record
    
  ### DELETE
    
    1. void delete_book() // Delete a record
    2. int delete_account() // Delete multiple or all records
    
  ### OTHERS
  
    1. void forget_pw() // A bridge to go to change_pw_forget()
    2. int is_same() // check that does id same with one of data in record
    3. int is_over() // check that are lenght of id or pw  over 16 characters.
    
***

## EXTRAS
  
 ##### 1. int defragment() // defragment   
 ##### 2. void sorting_data() // sorting by name order   
 ##### 3. void the_most_like_genre() // show the most selected genre among the genres users have entered when signing up   
 ##### 4. int Login() // when user input id and pw exist in thr record, show the another place to do something   
 ##### 5. void add_book() // after login, if user select add_book, user can enter the tile of book. the input will be stored in under                                 of directory "book", "Username.txt"   
 ##### 6. void show_lib() // after login, if user select show_lib, user can see what he/she added. if there is not a file of username                                 or it's empty, print out error messeage   
 ***
