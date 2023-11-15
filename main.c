#include <stdio.h>
#include "liste.h"
int main() {
    printf("Hello, World!\n");
    t_sk_cell* s1 = create_cell(5,1);
    t_sk_cell* s2 = create_cell(6,3);
    t_sk_list* l = create_list(5);
    insert_head_list(s1,l);
    insert_head_list(s2,l);
    print_level_all_cell(*l,1);
    return 0;
}
