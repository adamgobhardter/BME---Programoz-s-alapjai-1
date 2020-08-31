/**
 * @file progress.h
 * A függvények által használt láncolt lista deklarálása, A tanulók adatait összefogó struktúra deklarálása. A progress függvény deklarálása.
 */

#ifndef PROGRESS_H_INCLUDED
#define PROGRESS_H_INCLUDED

typedef struct Student
{
    char vez_nev[50+1];
    char ker_nev[50+1];
    char neptun[6+1];
    char eloadas_kod[3+1];
    char gyakorlat_kod[3+1];
    char gyakvez_vez_nev[50+1];
    char gyakvez_ker_nev[50+1];
    int hianyzas;
    int nZH;
    int kZH;
    char NHF[4+1];

}Student;

typedef struct ListaElem
{
    Student tanulo;
    struct ListaElem *kov;

}ListaElem;

ListaElem *progress(int valasztas, ListaElem *eleje);

#endif // PROGRESS_H_INCLUDED
