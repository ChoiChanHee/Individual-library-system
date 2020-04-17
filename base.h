#ifndef _BASE_H_
#define _BASE_H_
#define TRUE 1
#define FALSE 0
#include "record.h"
#define TRUE 1
#define FALSE 0
// function prototypes

void read_DF(Record save[], int *c);

Record sign_in(Record a[], int c);
void forget_id(Record a[], int c);
void forget_pw(Record a[], int c); //change part with change_pw_forget
void change_pw_forget(Record a[], int c);

int Login(Record a[], int c);
void fail_login();
void in_longin(Record[]);
int display_login(Record[], int n, int *c);

void my_account(Record[]);
void show_lib(Record a[], int n, int c);
void add_book(Record a[], int n, int c);
void delete_book(Record a[], int n, int c);
int delete_account(Record a[], int n, int *c);

int is_same(Record save[], char d[MAX], int count);
int is_over( char d[MAX]);
void store_data(Record a[], int c);
#endif
