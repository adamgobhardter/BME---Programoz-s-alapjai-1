/**
 * @file progress.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h> // Windows(curses.h alternatíva)
#include <curses.h> // Linux (conio.h alternatíva)
//#include <windows.h>
#include <unistd.h>

#include "progress.h"
#include "progress_functions.h"
#include "debugmalloc.h"


/**
 * A menü egy opcióját hajtja végre a felhasználó választása alapján.
 * @param Egy választott menüpont (egész szám) és az adatokat tároló láncolt lista elejére mutató pointer.
 * @return Láncolt lista.
 */
ListaElem *progress(int valasztas, ListaElem *eleje)
{
    switch(valasztas)
    {
        case 1:

            database_content();
            printf("\n\n\nA menube valo visszatereshez nyomjon meg egy billentyut! ");

            int enter = getchar(); // enter - Linux
            if('\n' == enter)
                {enter = getchar();}
            printf("%c", enter);

            //getch(); // Windows

            break;

        case 2:

            //system("cls");
			system("clear");
            printf("\t\t\tUj tanulo adatainak felvetele\n\n\n");

            int a;

            eleje = list_new();

            printf("\n\nA menube valo visszatereshez nyomja meg az 1-es billentyut!\n");
            printf("Uj tanulo adatainak felvetelehez nyomja meg a 2-es billentyut! ");
            scanf("%d", &a);

            while(a != 1)
            {
                eleje = list_add(eleje);

                printf("\n\nA menube valo visszatereshez nyomja meg az 1-es billentyut!\n");
                printf("Uj tanulo adatainak felvetelehez nyomja meg a 2-es billentyut! ");
                scanf("%d", &a);
            }

            list_save(eleje);

            eleje = list_free(eleje);
            eleje = NULL;

            break;

        case 3:

            //system("cls");
			system("clear");
            printf("\t\t\tAdatok torlese\n\n\n");

            FILE *file;                                     //Létezik a fájl?
            int exist = 0;
            if ((file = fopen("database.txt", "r")))
            {
                fclose(file);
                exist = 1;
            }

            if(exist == 1)
            {
                FILE *proba = fopen("database.txt", "rt");     //Üres a fájl?
                fseek(proba, 0, SEEK_END);
                int meret = ftell(proba);

                if(meret == 0)
                {
                    fclose(proba);
                    printf("Az adatbazis tartalma ures! ");
                    sleep(1);
                }
                else
                {
                    eleje = read_from_file();

                    printf("Kerem irja be a torlendo tanulo Neptun kodjat: ");
                    char neptun[6+1];
                    scanf("%s", neptun);

                    eleje = del_from_list(eleje, neptun);

                    FILE *pointer = fopen("database.txt", "w");

                    fclose(pointer);

                    list_save(eleje);

                    eleje = list_free(eleje);

                    printf("\n\n\n");
                    printf("Adatbazis modositva! ");
                    sleep(1);
                }
            }
            else{printf("Az adatbazis tartalma ures! "); sleep(1);}

            break;

        case 4:

            //system("cls");
			system("clear");
            printf("\t\t\tnZH-t potlok nevsora\n\n\n");

            eleje = read_from_file();

            int hossz = no_of_nodes(eleje);

            list_sort_ABC_Nev(&eleje,hossz);

            nZH_potlas(eleje);

            printf("\n\nA menube valo visszatereshez nyomjon meg egy billentyut! ");

            enter = getchar();
            if('\n' == enter)
                {enter = getchar();}
            printf("%c", enter);

            //getch();

            eleje = list_free(eleje);

            break;

        case 5:

            //system("cls");
			system("clear");
            printf("\t\t\tNHF-ot potlok nevsora\n\n\n");

            eleje = read_from_file();

            int hossz2 = no_of_nodes(eleje);

            list_sort_ABC_Nev(&eleje,hossz2);

            NHF_potlas(eleje);

            printf("\n\nA menube valo visszatereshez nyomjon meg egy billentyut! ");

            enter = getchar();
            if('\n' == enter)
                {enter = getchar();}
            printf("%c", enter);

            //getch();

            eleje = list_free(eleje);

            break;

        case 6:

            //system("cls");
			system("clear");
            printf("\t\t\tnZH eredmenyek rangsora\n\n\n");

            FILE *teszt = fopen("database.txt", "rt");
            fseek(teszt, 0, SEEK_END);
            int meret = ftell(teszt);

            if(meret == 0)
            {
                fclose(teszt);
                printf("Az adatbazis tartalma ures! ");
                sleep(1);
            }
            else
            {
                eleje = read_from_file();

                int hossz3 = no_of_nodes(eleje);

                list_sort_decrease_nZH(&eleje, hossz3);

                nZH_eredmenyek(eleje);

                printf("\n\nA menube valo visszatereshez nyomjon meg egy billentyut! ");

                enter = getchar();
                if('\n' == enter)
                {enter = getchar();}
                printf("%c", enter);

                //getch();

                eleje = list_free(eleje);
            }

            break;

        case 7:

            //system("cls");
			system("clear");
            printf("\t\t\tHianyzasok rangsora\n\n\n");

            FILE *test = fopen("database.txt", "rt");
            fseek(test, 0, SEEK_END);
            int tartalom = ftell(test);

            if(tartalom == 0)
            {
                fclose(test);
                printf("Az adatbazis tartalma ures! ");
                sleep(1);
            }
            else
            {
                eleje = read_from_file();

                int hossz4 = no_of_nodes(eleje);

                list_sort_decrease_Hianyzas(&eleje,hossz4);

                hianyzas_rangsor(eleje);

                printf("\n\nA menube valo visszatereshez nyomjon meg egy billentyut! ");

                enter = getchar();
                if('\n' == enter)
                {enter = getchar();}
                printf("%c", enter);

                //getch();

                eleje = list_free(eleje);
            }

            break;

        case 8:

            //system("cls");
			system("clear");

            fopen("database.txt", "w");

            printf("Az adatbazis torlese sikeresen megtortent. ");
            sleep(1);

            break;
    }

    return eleje;
}
