#ifndef _BASE_H_
#define _BASE_H_
#define TRUE 1
#define FALSE 0
#include "record.h"
#define TRUE 1
#define FALSE 0
// function prototypes

void create_new_account_file(Record save[], int c);//CREATE
Record create_new_account(Record save[], int c);//CREATE

void read_DF(Record save[], int *c);//READ
void forget_id(Record a[], int c);//READ
void show_the_information(Record a[], int n);//READ
void store_data(Record a[], int c);//READ

void change_information(Record a[], int n, int c);//UPDATE
void change_pw_forget(Record a[], int c);//UPDATE

void delete_book(Record a[], int n, int c);//DELETE
int delete_account(Record a[], int n, int *c);//DELETE

void forget_pw(Record a[], int c);
int is_same(Record save[], char d[MAX], int count);
int is_over( char d[MAX]);

#endif
