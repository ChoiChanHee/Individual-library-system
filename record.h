#ifndef _RECORD_H_
#define _RECORD_H_
#define SIZE 16
#define MAX 100
// type defition


typedef struct{
  	// TODO: define your own structure type here
	char id[SIZE];
  char pw[SIZE];
  char name[SIZE];
  char p_num[SIZE];//phone number
  char bd[SIZE];//birth day, dd/mm/yyyy
  char book[MAX];
} Record;

#endif
