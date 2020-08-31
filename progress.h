/**
 * @file progress.h
 * A f�ggv�nyek �ltal haszn�lt l�ncolt lista deklar�l�sa, A tanul�k adatait �sszefog� strukt�ra deklar�l�sa. A progress f�ggv�ny deklar�l�sa.
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
