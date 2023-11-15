//
// Created by Emile on 25/10/2023.
//

#ifndef AGENDA_LISTE_H
#define AGENDA_LISTE_H

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
t_sk_list create_list (int lmax);
#endif //AGENDA_LISTE_H
