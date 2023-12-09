//
// Created by Benjamin on 05/12/2023.
//

#ifndef AGENDAME_LISTE_H
#define AGENDAME_LISTE_H

typedef struct s_sk_cell {
    int value;
    int level;
    struct s_sk_cell **next;
} t_sk_cell;

typedef struct s_sk_list {
    t_sk_cell **heads;
    int max_level;
} t_sk_list;

t_sk_cell* create_cell(int v, int l);
t_sk_list* create_list (int lmax);
void insert_head_list(t_sk_cell* cell, t_sk_list* list);
void print_level_all_cell(t_sk_list* list,int nv);
void print_all_cell(t_sk_list* list);
void print_all_cell_aligner(t_sk_list* list);
void insert_cell_croissant(t_sk_cell* cell,t_sk_list* list);
t_sk_list* create_list_n(int n);
int research_classic(t_sk_list list, int v);
int research_from_top(t_sk_list list, int v);
#endif //AGENDAME_LISTE_H
