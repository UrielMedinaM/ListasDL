#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlistc.h"

dlistc *create_dlistc(){
    dlistc *l = (dlistc*)malloc(sizeof(dlistc));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}

bool remove_dlistc(dlistc *l){
    if(!is_empty_dlist(l))
        empty_dlist(l);
    free(l);
    return true;
}

DATA search_dlistc(dlistc *l, int pos){
    if(pos == 0) return l->head->data;
    else if(pos == l->num-1) return l->tail->data;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for(int i=1; i<l->num-2; i++){
            if(i==pos) return i;
            t = t->next;
        }
    }
    return -1;
}

dnode* search_dnode_dlistc(dlistc *l, int pos){
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for(int i=1; i<l->num-1; i++){
            if(i==pos) return t;
            t = t->next;
        }
    }
    return NULL;
}

int locate_dlistc(dlistc *l, DATA data){
    dnode *t = l->head;
    for(int i= 0; i < l->num-1; i++){
        if(t->data==data) return i;
        t = t->next;
    }
    return -1;
}

void print_dlistc(dlistc *l){
    dnode *t = l->head;
    printf("[ ");
    for(int i=0; i < l->num-1; i++){
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
    printf("]\n");
}

void empty_dlistc(dlistc *l){
    if(is_empty_dlistc(l)) return;
    dnode *t = l->head;
    while(remove_init(l));
}

bool delete_data(dlistc *l, DATA data){
    dnode *t = l->head;
    for(int i =0; i < l->num; i++){
        if(t->data == data){
            if(t == l->head) return remove_init(l);
        }
    }
}

bool is_empty_dlistc(dlistc *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}

bool insert_init(dlistc* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlist(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->head->next = nuevo;
        l->head->prev = nuevo;
        l->num =1;
        return true;
    }
    nuevo->next = l->head;
    l->head->prev = nuevo;
    l->head = nuevo;
    l->head->prev = l->tail;
    l->tail->next = l->head;
    l->num++;
    return true;
}

bool insert_end(dlistc* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlist(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->head->next = nuevo;
        l->head->prev = nuevo;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->head->prev = l->tail;
    l->tail->next = l->head;
    l->num++;
    return true;
}

bool insert_dlistc(dlistc* l, DATA data,  int pos){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(pos ==0) return insert_init(l, data);
    else if(pos == l->num)
        return insert_end(l,data);
    else if(pos >0 && pos< l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){ // i = 1 Y pos = 1
            t= t->next;
        }
        dnode *prev = t->prev;    
        prev->next = nuevo;
        nuevo->next = t;
        nuevo->prev = prev;        
        t->prev = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool remove_init(dlistc *l){
    if(l == NULL || is_empty_dlistc(l)) return false;
    if(l->head ==l->tail){
        l->head->next = l->tail->prev = NULL;
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->head->next;    
    t->prev = NULL;
    l->head->next= NULL;
    remove_dnode(l->head);
    l->head = t;
    l->tail->next = l->head;
    l->head->prev = l->tail;
    l->num--;
    return true;
}

bool remove_end(dlistc *l){
    if(l == NULL || is_empty_dlistc(l)) return false;
    if(l->head ==l->tail){
        l->head->next = l->tail->prev = NULL;
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->tail->prev;
    t->next= NULL;
    l->tail->prev = NULL;
    remove_dnode(l->tail);
    l->tail = t;
    l->tail->next = l->head;
    l->head->next = l->tail;
    l->num--;
    return true;
}



bool remove_pos(dlistc *l ,int pos){
    if(pos == 0){
        return remove_init(l);
    }else if(pos == l->num-1){
        return remove_end(l);
    }else if(pos>0 && pos < l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        dnode *prev = t->prev;    
        dnode *next = t->next;        
        prev->next = next;        
        next->prev = prev;
        t->next = NULL;
        t->prev = NULL;
        remove_dnode(t);
        l->num--;
        return true;
    }
    return false;
}


