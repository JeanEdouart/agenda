//
// Created by Benjamin on 05/12/2023.
//

#include "liste.h"
#include "stdlib.h"
#include <stdio.h>
#include "math.h"
//Partie 1
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

void print_level_all_cell(t_sk_list* list,int nv){
    t_sk_cell* cell = list->heads[nv];
    printf("[list head_%d @-]-->",nv);
    while (cell!=NULL){
        printf("[ %d|@-]-->",cell->value);
        cell = cell->next[nv];
    }
    printf("NULL\n");
}

void print_all_cell(t_sk_list* list){
    for (int i = 0; i <list->max_level; i++) {
        print_level_all_cell(list,i);
    }
}

void print_all_cell_aligner(t_sk_list* list) {
    //"affiche la liste en alignant les cellules"
    //"affiche les valeur du niveau 0"
    //"pour les niveaux suivant, on affiche des tirets si la valeur de la cellule existe dans le niveau precedent
    //"sinon on affiche la valeur"
    print_level_all_cell(list,0);
    t_sk_cell *temp1;
    t_sk_cell *temp2;
    for (int i = 1; i <list->max_level; i++) {
        temp1 = list->heads[i];
        temp2 = list->heads[0];
        printf("[list head_%d @-]--", i);
        while (temp1 != NULL || temp2 != NULL) {
            if (temp1 == NULL) {
                printf("-----------");
            } else {
                while (temp2->value != temp1->value) {
                    printf("-----------");
                    temp2 = temp2->next[0];
                }
                printf(">[ %d|@-]--", temp1->value);
                temp1 = temp1->next[i];
            }
            temp2 = temp2->next[0];
        }
        printf(">NULL\n");
    }
}

void insert_cell_croissant(t_sk_cell* cell,t_sk_list* list){
    t_sk_cell* c;
    for (int i = 0; i<cell->level;i++) {
        c = list->heads[i];
        if(list->heads[i] == NULL || list->heads[i]->value > cell->value){
            cell->next[i] = list->heads[i];
            list->heads[i] = cell;
        }
        else{
            while (c->next[i] != NULL && c->next[i]->value < cell->value){
                c = c->next[i];
            }
            cell->next[i] = c->next[i];
            c->next[i] = cell;
        }
    }
}
//Partie 2
t_sk_list* create_list_n(int n){
    t_sk_list* list = create_list(n);
    int calc = (int)pow(2,n);
    int nb_cell = calc;
    int* levels = (int*) malloc(nb_cell*sizeof(int));
    for (int i = 0; i<nb_cell;i++){
        levels[i] = 0;
    }

    int step = 2;
    while (step <= nb_cell) {
        for (int i = 0; i <= nb_cell; i += step) {
            levels[i] += 1;
        }
        step *= 2;
    }
    for (int i = 1; i<nb_cell; i++){
        t_sk_cell* cell = create_cell(i,levels[i]+1);
        insert_cell_croissant(cell,list);
    }
    return list;
}

int research_classic(t_sk_list list, int v){
    t_sk_cell* cell = list.heads[0];
    while (cell != NULL){
        if (cell->value == v){
            return 1;
        }
        else {
            cell = cell->next[0];
        }
    }
    return 0;
}

int research_from_top(t_sk_list list, int v){
    t_sk_cell* cell = list.heads[list.max_level-1];
    t_sk_cell* temp = NULL;
    for (int i= list.max_level-1;i>=0;i--){
        if (temp == NULL){
            cell = list.heads [i];
        }
        while (cell != NULL && cell->value <= v) {
            if (cell->value == v) {
                return 1;
            }
            temp = cell;
            cell = cell->next[i];
        }
        cell = temp;
    }
    return 0;
}