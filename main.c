/**
 * @file main.c
 */
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h> // Windows (unistd.h alternatíva)
#include <unistd.h> // Linux (windows.h alternatíva)

#include "debugmalloc.h"
#include "progress.h"
#include "progress_functions.h"

/**
 * Megjeleníti a képernyőn a menürendszert.
 * @param Nincs
 * @return Nincs
 */
void menu(void)
{
    //system("cls"); //Képernyõ törlése (Windows)
    system("clear"); // Képernyő törlése (Linux)

    printf("\t\t\tProgramozas alapjai 1 nyilvantartas\n\n");
    printf("FIGYELEM! A programbol valo nem megfelelo kilepes adatvesztest okozhat!\n\n");
    printf("Menu:\n\n");
    printf("1. Teljes adatbazis megjelenitese\n2. Uj adatok felvetele\n3. Meglevo adatok torlese\n4. NZH-t potlok listaja\n5. NHF-ot potlok listaja\n6. NZH eredmenyek rangsora\n7. Hianyzasok rangsora\n8. A teljes adatbazis torlese\n\n9. Kilepes\n\n\n\n");
}

/**
 * Addig kér be a felhasználótól egy számot, amíg az bele nem esik az 1-9 intervallumba, a határokat is beleértve.
 * @param Nincs
 * @return Egy egész szám, ami a menüből választható opciók közül reprezentál egyet.
 */
int choice(void)
{
    int valasztas;

    printf("Kerem valasszon a menubol (1-9): ");
    scanf("%d", &valasztas);

    printf("\n");

    while(valasztas <= 0 || valasztas > 9)
    {
        printf("A kivalasztott menupont nem erheto el!\n");

        printf("\n");

        printf("Kerem valasszon ujra a menubol (1-9): ");
        scanf("%d", &valasztas);

        printf("\n");
    }

    return valasztas;
}


/**
 * Ciklusban alkalmazza a menu, choice és progress függvényeket egészen addig, amíg a felhasználó ki nem választja a 11-es menüpontot. Ezután felszabadítja a megmaradt teljes láncolt listát.
 * @param Nincs
 * @return 0, ami a program hiba nélküli lefutását jelenti.
 */
int main(void)
{
    int valasztas;
    ListaElem *eleje = NULL;

    do
    {
        menu();
        valasztas = choice();
        eleje = progress(valasztas, eleje);

    }while(valasztas != 9);

    //system("cls");
    system("clear");

    eleje = list_free(eleje);

    //system("cls");
    system("clear");

    printf("\t\t\tSikeres kilepes, viszontlatasra!");
    sleep(1); // Linux
    //Sleep(1000);

    return 0;
}
