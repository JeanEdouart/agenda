#include <stdio.h>
#include "liste.h"
#include "timer.h"
#include "math.h"
#include "stdlib.h"
int main() {
    printf("----------------------------\n");
    printf("PARTIE 1\n");
    printf("----------------------------\n\n");
    t_sk_list* list = create_list(5);
    t_sk_cell* a = create_cell(18,4);
    t_sk_cell* b = create_cell(25,1);
    t_sk_cell* c = create_cell(31,2);
    t_sk_cell* d = create_cell(32,5);
    t_sk_cell* e = create_cell(56,3);
    t_sk_cell* f = create_cell(59,5);
    t_sk_cell* g = create_cell(59,1);
    t_sk_cell* h = create_cell(91,3);
    insert_cell_croissant(h,list);
    insert_cell_croissant(f,list);
    insert_cell_croissant(e,list);
    insert_cell_croissant(g,list);
    insert_cell_croissant(a,list);
    insert_cell_croissant(b,list);
    insert_cell_croissant(d,list);
    insert_cell_croissant(c,list);
    print_all_cell(list);
    printf("\n");
    printf("----------------------------\n");
    printf("\n");
    print_all_cell_aligner(list);
    printf("\n----------------------------\n");
    printf("PARTIE 2\n");
    printf("----------------------------\n\n");
    //--------------------------------------------------------------------------------------------------------------
    t_sk_list* liste = create_list_n(3);
    print_all_cell_aligner(liste);
    printf("Donne une valeur : ");
    int val;
    scanf("%d",&val);
    if (research_from_top(*liste,val)) printf("Oui c'est dedans\n");
    else printf("Non pas dedans\n");
    srand(time(NULL));
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;
    for (int i=7;i<15;i++){
        t_sk_list* l = create_list_n(i);
        int nb_cell = ((int)pow(2,i))-1;
        printf("niveau teste : %d :\n",i);
        startTimer();
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1;
            research_classic(*l,nb_alea);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        displayTime();
        startTimer();
        for (int j=1;j<10000;j++){
            int nb_alea = (rand()%nb_cell)+1;
            research_from_top(*l,nb_alea);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();
        fprintf(log_file,format,i,time_lvl0, time_all_levels);
    }
    fclose(log_file);
    return 0;
}
