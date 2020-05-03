#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main(){
    dlist *l;
    l = create_dlist();
    insert_dlist(l, 0, 0);
    insert_dlist(l, 2, 1);
    print_dlist(l);
    insert_dlist(l, 1, 1);
    insert_dlist(l, 3, 1);
    print_dlist(l);
    remove_pos(l, 1);
    print_dlist(l);
    remove_pos(l, 1);
    remove_pos(l, 1);
    print_dlist(l);
    remove_dlist(l);
    l = NULL;
    return 0;
}