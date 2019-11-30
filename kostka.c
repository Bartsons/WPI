#include <stdio.h>

#ifndef N
#define N 5
#endif

//Oznaczenia numerow scianek jak w zadaniu u-0 itd

void wypelnij_sciane(int kostka[][N][N], int sciana){
    //Funkcja wypelniajaca wszystkie pola jednej scianki
    for (int w = 0; w < N; ++w) {
        for (int k = 0; k < N; ++k) {
            kostka[sciana][w][k] = sciana;
        }
    }
}

void wypelnij_kostke(int kostka[][N][N]){
    //W kazdej sciance w kazde pole wpisuje numer scianki
    for (int s = 0; s < 6; ++s) {
        wypelnij_sciane(kostka, s);
        }
}

void obrot_el_boku(int kostka[][N][N], int sciana, int w, int k){
    //Funkcja zamienia 4 elementy symetryczne wzg srodka
    int pom = kostka[sciana][w][k];
    kostka[sciana][w][k] = kostka[sciana][N -1 - k][w];
    kostka[sciana][N -1 - k][w] = kostka[sciana][N -1 - w][N -1 - k];
    kostka[sciana][N -1 - w][N -1 - k] = kostka[sciana][k][N -1 - w];
    kostka[sciana][k][N -1 - w] = pom;
}

void obrot_bok(int kostka[][N][N], int sciana){
    //Funkcja obraca cala scianke biorac wszystkie czworki elementow
    //zawierajace jeden z pierwszej cwiartki
    int wiersze;
    int kolumny;
    if(N % 2 == 0) {
        wiersze = N / 2;
        kolumny = N / 2;
    }
    else{
        wiersze = N/2;
        kolumny = (N + 1)/2;
    }
    for (int w = 0; w < wiersze; ++w) {
        for (int k = 0; k < kolumny; ++k) {
            obrot_el_boku(kostka, sciana, w, k);
        }
    }
}

void obrot_el_wier(int kostka[][N][N], int sciana, int w, int k){
    //Funkcja zamieniajaca 4 elementow z roznych scianek
    int pom;
    if(sciana == 0){
        pom = kostka[1][w][k];
        kostka[1][w][k] = kostka[2][w][k];
        kostka[2][w][k] = kostka[3][w][k];
        kostka[3][w][k] = kostka[4][w][k];
        kostka[4][w][k] = pom;
    }
    if(sciana == 1){
        pom = kostka[4][N - 1 - k][N -1 - w];
        kostka[4][N - 1 - k][N -1 - w] = kostka[5][k][w];
        kostka[5][k][w] = kostka[2][k][w];
        kostka[2][k][w] = kostka[0][k][w];
        kostka[0][k][w] = pom;
    }
    if(sciana == 2){
        pom = kostka[1][k][N -1 - w];
        kostka[1][k][N -1 - w] = kostka[5][w][k];
        kostka[5][w][k] = kostka[3][N - 1 -k][w];
        kostka[3][N - 1 -k][w] = kostka[0][N -1 - w][N - 1 -k];
        kostka[0][N -1 - w][N - 1 - k] = pom;
    }
    if(sciana == 3){
        pom = kostka[2][k][N -1 - w];
        kostka[2][k][N -1 -w] = kostka[5][k][N - 1 -w];
        kostka[5][k][N - 1 -w] = kostka[4][N -1 - k][w];
        kostka[4][N -1 - k][w] = kostka[0][k][N -1 - w];
        kostka[0][k][N -1 - w] = pom;
    }
    if(sciana == 4){
        pom = kostka[3][N - 1 -k][N -1 - w];
        kostka[3][N - 1 -k][N -1 - w] = kostka[5][N -1 - w][k];
        kostka[5][N -1 - w][k] = kostka[1][k][w];
        kostka[1][k][w] = kostka[0][w][N - 1 -k];
        kostka[0][w][N - 1 - k] = pom;
    }
    if(sciana == 5){
        pom = kostka[4][N - 1 - w][k];
        kostka[4][N - 1 - w][k] = kostka[3][N - 1 - w][k];
        kostka[3][N - 1 - w][k] = kostka[2][N - 1 - w][k];
        kostka[2][N - 1 - w][k] = kostka[1][N - 1 - w][k];
        kostka[1][N - 1 - w][k] = pom;
    }

}

void obrot_wiersza(int kostka[][N][N], int sciana, int w){
    //Funkcja obracajaca caly wiekrsz wokol osi odpowadajacej sciance
    for (int k = 0; k < N; ++k)
        obrot_el_wier(kostka, sciana, w, k);
}

void obracaj(int kostka[][N][N], int sciana, int warstwy){
    //Funkcja obracajaca wiersze wokol osi
    obrot_bok(kostka, sciana);
    for (int w = 0; w < warstwy; ++w)
        obrot_wiersza(kostka, sciana, w);
    //Dla n warstw obraca cala kostke
    if(warstwy == N){
        int druga_sciana;
        if(sciana%5 ==0)
            druga_sciana = 5 - sciana;
        else{
            druga_sciana = (sciana + 2)%4;
            if(druga_sciana == 0)
                druga_sciana = 4;
        }
        obrot_bok(kostka, druga_sciana);
        obrot_bok(kostka, druga_sciana);
        obrot_bok(kostka, druga_sciana);
    }
}

void pisz(int kostka[][N][N]){
    //Funkcja wypisujaca kostke
    putchar('\n');
    for(int w = 0; w < N; ++w) {
        for (int i = 0; i < N +1; ++i)
            putchar(' ');
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[0][w][k]);
        putchar('\n');
    }
    for(int w = 0; w < N; ++w) {
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[1][w][k]);
        putchar('|');
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[2][w][k]);
        putchar('|');
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[3][w][k]);
        putchar('|');
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[4][w][k]);
        putchar('\n');
    }
    for(int w = 0; w < N; ++w) {
        for (int i = 0; i < N +1; ++i)
            putchar(' ');
        for (int k = 0; k < N; ++k)
            printf("%d", kostka[5][w][k]);
        putchar('\n');
    }
}

int main(){
    //Najpierw inicjalizujemy i wypełniamy kostke
    int kostka[6][N][N];
    wypelnij_kostke(kostka);

    int dzialaj = 1;

    //zmienna odszyfrowujaca komende z wejscia
    int komenda;
    int liczba_warstw = 1;
    int pot_liczby_warstw = 0;
    //sciana wokol ktorej nastapi obrot
    int sciana;
    //zmienna sprawdzajaca czy obrot jest pierwszym w lini wejscia
    int pocz_lini = 1;

    while(dzialaj) {
        komenda = getchar();

        //Gdy na wejsciu jest cyfra
        if (komenda > 47 && komenda < 58) {
            if (pot_liczby_warstw == 0)
                //bo domyslnie obracamy 1 warstwe
                liczba_warstw--;
            liczba_warstw *= 10;
            liczba_warstw += (komenda - 48);
            pot_liczby_warstw++;
        }

        if(komenda > 96 && komenda < 123){
            //gdy na wejsciu jest litera
            if(pocz_lini==0)
                //obraca o poprzedia litere
                obracaj(kostka, sciana, liczba_warstw);
            pocz_lini = 0;

            //Ustawia liczbe warstw do domyslnej 1
            liczba_warstw = 1;
            pot_liczby_warstw = 0;
            if(komenda == 117)
                //117 - u
                sciana = 0;
            if(komenda == 108)
                //108 - l
                sciana = 1;
            if(komenda == 102)
                //102 - f
                sciana = 2;
            if(komenda == 114)
                //114 - r
                sciana = 3;
            if(komenda == 98)
                //98 - b
                sciana = 4;
            if(komenda == 100)
                //100 - d
                sciana = 5;
        }


        if (komenda == 34)
            // 34 - "
            //wykonuje drugi- dodatkowy obrot
            obracaj(kostka, sciana, liczba_warstw);
        if (komenda == 39) {
            // 39 - '
            //wykonuje dwa dodatkowe obroty
            obracaj(kostka, sciana, liczba_warstw);
            obracaj(kostka, sciana, liczba_warstw);
        }

        if (komenda == 10) {
            // 10 - \n
            //wykonuje ostatni obrot oraz wypisuje kostke
            if (pocz_lini == 0)
                obracaj(kostka, sciana, liczba_warstw);
            pisz(kostka);
            pocz_lini = 1;
        }

        if (komenda == 46)
            // 46 - "."
            //Konczy dzialanie programu
            dzialaj = 0;
    }
    getchar();
    return 0;
}
