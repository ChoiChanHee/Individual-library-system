#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
int defragment(Record a[], int n, int *c);
void sorting_data(Record a[], int c);
void the_most_like_genre(Record a[], int c);
int Login(Record a[], int c);
void add_book(Record a[], int n, int c);
void show_lib(Record a[], int n, int c);
#endif
