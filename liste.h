//
// Created by Emile on 25/10/2023.
//

#ifndef AGENDA_LISTE_H
#define AGENDA_LISTE_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;

#endif //AGENDA_LISTE_H
