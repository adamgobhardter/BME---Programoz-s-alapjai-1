# BME-Programozas-alapjai-1
A Programozás alapjai 1 tárgyból kiadott kötelező házi feladat.
__________________________________________________________________________________________________________________________________________________________________

Prog1 nyilvántartás *

Készíts programot, amely képes hallgatók adatait nyilvántartani, és Prog1 eredményeiket számolni! A megjegyzendő adatok a következők:

    - A hallgatók neve, neptun kódja, előadás- és gyakcsoportja.
    - Az oktatóik neve, csoportjaik.
    - Hiányzások, kis ZH eredmények, NZH pontok stb. 

„Tanítsd meg” a programnak a tárgykövetelményeket! Legyen képes a program listát készíteni azokról, akiknek PZH-t kell írniuk vagy nagy házi pótlást kell leadniuk! Legyen képes rangsorokat készíteni (pontszámok alapján), és ehhez hasonló listákat kiírni a képernyőre!
__________________________________________________________________________________________________________________________________________________________________


__________________________________________________________________________________________________________________________________________________________________
KÖVETELMÉNYEK:

    • Dinamikus memóriakezelést kell használni a program lényegét adó adatszerkezetnél. Nem elegendő ilyet beépíteni a programnak olyan részébe, amely akár    elhagyható is lenne. Például egy olyan játék, amelyben dinamikus memóriakezelés csak a dicsőséglistánál van, nem teljesíti ezt a követelményt.
    
    • A dinamikus memóriakezelés követelményt formálisan is megadjuk. Az adatszerkezetben az indirekciók száma legalább kettő kell legyen, azaz dinamikusan foglalt területen kell legyen dinamikusan foglalt terület címe. Az egydimenziós tömb nem elegendő – olyan feladatot kell választani, amely ennél összetettebb adatszerkezetet igényel. Az indirekciók száma az adatszerkezet működéséből kell adódjon; pl. egydimenziós tömb, amelynek kezdőcíme céltalanul dinamikus memóriaterületen van, nem teljesíti a követelményt.
    
    • A dinamikus memóriakezelés ellenőrzésére a programnak használnia kell a tárgyban használt debugmalloc könyvtárat vagy ahhoz hasonló eszközt.
    
    • A fájlkezelésben olyan adatokat kell tudni kezelni, amelyek száma változik, vagy változhatna. Nem teljesíti a követelményt pl. egy olyan program, amelyik az elindításainak számát (egyetlen egy egész számot) tárol fájlban. Teljesíti viszont egy olyan, amelyik egy játék 10 elemű dicsőséglistáját tárolja. A 10 ugyan fix, de akár változhatna is. A fájlkezelés saját programkódon kell alapuljon, pl. grafikus könyvtár által betöltött kép nem számít saját fájlkezelésnek.

ELUTASÍTVA HA:
    • Az egész program egy forrásfájlban van, nincsen több modulra bontva. A programot logikusan több modulra kell bontani, tehát több *.c és *.h forrásfájlnak kell lennie.
    
    • A program nem használ fájlkezelést.
    
    • A program nem használ kellően összetett dinamikus memóriakezelést a lényegi funkcionalitásának megvalósításához. A programban megfelelő adatszerkezetet, pl. dinamikus tömböt (legalább két dimenziósat), láncolt listát vagy bináris fát kell használni, a feladat jellege által megkívánt módon. Lásd a követelményeknél.
    
    • A program nem használja a debugmalloc memóriakezelést ellenőrző modult, vagy azzal ekvivalens eszközt. (Az utóbbit a programozói dokumentációban említeni kell. Ha technikai akadály miatt a debugmalloc használata nem lehetséges, a laborvezetővel ezt előzetesen, a leadást megelőzően egyeztetni kell.)
    
    • A program a fő adatszerkezeteihez (telefonkönyvnél a nevek, kukacos játéknál a játék állapota és a kukac stb.) globális változót vagy fájlokat használ. A globális változók sokszor indokoltak lehetnek, de nem arra valók, hogy a megfelelő függvényparaméterezést vagy a cím szerinti paraméterátadást kiváltsák.
    
    • A program a függvényhívást ciklusként/goto-ként használja: pl. a menu() meghívja az adatbevitel()-t, az pedig visszatérés nélkül meghívja a menu()-t, hogy    az meghívhassa a keres()-t, ami megint meghívja a menu()-t... stb.; esetleg indokolatlanul soha vissza nem térő függvények vannak benne (pl. játék végén exit() hívása). 
    
__________________________________________________________________________________________________________________________________________________________________
MEGJEGYZÉSEK:

- A program Windows-on és Linuxon lett tesztelve.
- A kód fejleszthető és hibákat tartalmaz. A feltöltött fájlok megegyeznek a bwadott és elfogadott változattal.
- Terminálból fordítva: gcc debugmalloc.h debugmalloc-impl.h progress.h progress_functions.h main.c progress.c progress_functions.c

