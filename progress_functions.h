/**
 * @file progress_functions.h
 * A menürendszer opcióit végrehajtó függvények deklarálása.
 */

#ifndef PROGRESS_FUNCTIONS_H_INCLUDED
#define PROGRESS_FUNCTIONS_H_INCLUDED

#include "progress.h"

ListaElem *read_from_file(void);
ListaElem *list_new(void);
ListaElem *list_add(ListaElem *eleje);
ListaElem *list_free(ListaElem *eleje);
void list_save(ListaElem *eleje);
void list_print(ListaElem *eleje);
ListaElem *del_eleje(ListaElem *eleje);
ListaElem *del_from_list(ListaElem *eleje, char *neptun);
int no_of_nodes(ListaElem *eleje);
ListaElem *list_node_swap(ListaElem *node1, ListaElem *node2);
void list_sort_ABC_Nev(ListaElem **eleje, int hossz);
void nZH_potlas(ListaElem *eleje);
void NHF_potlas(ListaElem *eleje);
void list_sort_decrease_nZH(ListaElem **eleje, int hossz);
void nZH_eredmenyek(ListaElem *eleje);
void list_sort_decrease_Hianyzas(ListaElem **eleje, int hossz);
void hianyzas_rangsor(ListaElem *eleje);
void database_content(void);

#endif // PROGRESS_FUNCTIONS_H_INCLUDED
