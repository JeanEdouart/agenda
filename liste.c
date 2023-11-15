//
// Created by Emile on 25/10/2023.
//

#include "liste.h"
#include "stdlib.h"
#include <stdio.h>

t_sk_cell* create_cell(int v, int l){ // fonction qui crée une cellule
    t_sk_cell* cell = (t_sk_cell*) malloc(sizeof(t_sk_cell)); //alloue la mémoire a la cellule crée
    cell->value = v; // allocation de la valeur de la cellule
    cell->level = l; // allocation du nombre de niveau de la cellule
    cell->next = (t_sk_cell**) malloc(l*sizeof(t_sk_cell*)); // alloue la mémoire nécessaire pour la prochaine cellule
    for (int i = 0; i<l;i++){
        cell->next[i] = NULL;
    }
    return cell;
}

t_sk_list* create_list (int lmax){
    t_sk_list* list = (t_sk_list*) malloc(sizeof(t_sk_list));
    list->max_level = lmax;
    list->heads = (t_sk_cell**) malloc(lmax*sizeof(t_sk_cell*));
    for (int i = 0; i<lmax;i++){
        list->heads[i] = NULL;
    }
    return list;
}

void insert_head_list(t_sk_cell* cell, t_sk_list* list){
    for (int i = 0; i<cell->level;i++) {
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}

void print_level_all_cell(t_sk_list list,int nv){
    printf("[list head_%d @-]-->",nv);
    while (list.heads[nv]!=NULL){
        printf("[ %d|@-]-->",list.heads[nv]->value);
        list.heads[nv] = (list.heads[nv]->next[nv]);
    }
    printf("NULL\n");
}