#ifndef DLIST_H
#define DLIST_H

#include "dnode.h"

typedef struct _dlist dlistc;

struct _dlist{
    dnode *head;
    dnode *tail;
    int num;
};

dlistc *create_dlistc();
bool remove_dlistc(dlistc *l);

bool insert_initc(dlistc *l, DATA data);
bool insert_endc(dlistc *l, DATA data);
bool insert_dlistc(dlistc *l, DATA data, int pos);

bool remove_initc(dlistc *l);
bool remove_endc(dlistc *l);
bool remove_posc(dlistc *l ,int pos);

DATA search_dlistc(dlistc *l, int pos);
int locate_dlistc(dlistc *l, DATA data);

void print_dlistc(dlistc *l);

bool is_empty_dlistc(dlistc *l);
void empty_dlistc(dlistc *l);

bool delete_datac(dlistc *l, DATA data);
#endif