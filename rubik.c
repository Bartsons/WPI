#include <stdio.h>

#ifndef N
#define N 5
#endif // N

//["u", "l", "f", "r", "t", "b", ] = [0, 1, 2, 3, 4, 5]
//kat:  ["", "\"", "\'"] = [1, 2, 3]

void wypelnij(int kostka[][N][N]){
    for(int s = 0; s < 6; s++){
        for(int w = 0; w < N; w++){
            for(int k = 0; k < N; k++){
                kostka[s][w][k] = s;
            }
        }
    }
}

void obr_el_boku(int kostka[][N][N], int znak, int w, int k){
    int pom = kostka[znak][w][k];
    kostka[znak][w][k] = kostka[znak][N - 1 - k][w];
    kostka[znak][N -1 - k][w] = kostka[znak][N - 1 - w][N - 1 - k];
    kostka[znak][N - 1 - w][N -1 - k] = kostka[znak][k][N - 1 - w];
    kostka[znak][k][N -1 -w] = pom;
}

void obrot_bok(int kostka[][N][N], int znak){
    int lw;
    int lk;
    if(N%2 ==0){
        lw = N/2;
        lk = N/2;
    }
    else{
        lw = N/2;
        lk = (N + 1)/2;
    }
    for (int w = 0; w < lw; w++) {
        for (int k = 0; k < lk; k++) {
            obr_el_boku(kostka,znak,  w, k);
        }
    }
}

void obrot_el_w(int kostka[][N][N], int znak, int wier, int i){
    //znak czyli wok�l kt�rej �ciany
    int pom;
    //zmienna pomocnicza, dzia�a zapami�tuj�c jedn� kom�rk�
    // na razie 1 oraz N potem  0 oraz n-1-j
    //  U: k[4][1][i] -> k[3][1][i] -> k[2][1][i] -> k[1][1][i] ->
    //  L: k[0][i][1] -> k[2][i][1] -> k[5][i][1]  -> k[4][i][N] ->
    //  F: k[0][N][i] -> k[3][i][1] -> k[5][1][i] -> k[1][i][N] ->
    //  R: k[0][i][N] -> k[4][i][1] -> k[5][i][N] -> k[2][i][N] ->
    //  T: k[0][1][i] -> k[1][i][1] -> k[5][N][i] -> k[3][i][N] ->
    //  D: k[1][N][i] -> k[2][N][i] -> k[3][N][i] -> k[4][N][i] ->
    if(znak ==5){
        pom = kostka[4][N - 1 - wier][i] ;
        kostka[4][N - 1 - wier][i]   = kostka[3][N - 1 - wier][i];
        kostka[3][N - 1 - wier][i]  =  kostka[2][N - 1 - wier][i];
        kostka[2][N - 1 - wier][i]  =  kostka[1][N - 1 - wier][i];
        kostka[1][N - 1 - wier][i]  = pom;
    }
    if(znak ==4){
        pom = kostka[3][i][N - 1 - wier];
        kostka[3][i][N - 1 - wier]  = kostka[5][N - 1 - wier][i];
        kostka[5][N - 1 - wier][i]   =  kostka[1][i][wier];
        kostka[1][i][wier] =  kostka[0][wier][i];
        kostka[0][wier][i]  = pom;
    }
    if(znak ==3){
        pom = kostka[2][i][N - 1 - wier];
        kostka[2][i][N - 1 - wier]  = kostka[5][i][N - 1 - wier];
        kostka[5][i][N - 1 - wier]  =  kostka[4][i][wier];
        kostka[4][i][wier] =  kostka[0][i][N - 1 - wier];
        kostka[0][i][N - 1 - wier]  = pom;
    }
    if(znak ==2){
        pom = kostka[1][i][N - 1 - wier];
        kostka[1][i][N - 1 - wier]  = kostka[5][wier][i];
        kostka[5][wier][i]  =  kostka[3][i][wier];
        kostka[3][i][wier]= kostka[0][N - 1 - wier][i];
        kostka[0][N - 1 - wier][i]  = pom;
    }
    if(znak ==1){
        pom = kostka[4][i][N - 1 - wier];
        kostka[4][i][N - 1 - wier]  = kostka[5][i][wier];
        kostka[5][i][wier]  =  kostka[2][i][wier];
        kostka[2][i][wier] = kostka[0][i][wier];
        kostka[0][i][wier] = pom;
    }
    if(znak ==0){
        pom = kostka[1][wier][i];
        kostka[1][wier][i] = kostka[2][wier][i];
        kostka[2][wier][i] = kostka[3][wier][i];
        kostka[3][wier][i] = kostka[4][wier][i];
        kostka[4][wier][i] = pom;
    }
}


void obrot_wiersz(int kostka[][N][N], int znak, int wier){
    for(int i = 0; i < N; i++){
        obrot_el_w(kostka, znak, wier, i);
    }
}

void obracaj(int kostka[][N][N], int znak, int liczba_war){
    //, int kat=1
//k�t czyli ile razy obracamy wok� osi znak
//for(int i = 0; i < kat; i++)
    obrot_bok(kostka, znak);
    for(int wier = 0; wier < liczba_war; wier++){
        obrot_wiersz(kostka, znak, wier);
    }
    //dla N warstw obraca cala kostke
    if(liczba_war == N){
        //Dla gornej i dolnej
        int nowy_znak;
        if(znak%5 == 0)
            nowy_znak = 5 - znak;
        else {
            //dla bocznych scianek
            nowy_znak = (znak + 2)%4;
            if(nowy_znak == 0)
                nowy_znak = 4;
        }
        obrot_bok(kostka, nowy_znak);
        obrot_bok(kostka, nowy_znak);
        obrot_bok(kostka, nowy_znak);
        }

    }



void pisz(int kostka[][N][N]){
    putchar('\n');
    for(int w =0; w < N; w++){
        for(int i = 0; i < N+1; i++){
            putchar(' ');
        }
        for(int k = 0; k < N; k++){
            printf("%d",kostka[0][w][k]);
        }
        putchar('\n');
    }
    for(int w =0; w < N; w++){
        for(int k = 0; k < N; k++){
            printf("%d",kostka[1][w][k]);
        }
        putchar('|');
        for(int k = 0; k < N; k++){
            printf("%d", kostka[2][w][k]);
        }
        putchar('|');
        for(int k = 0; k < N; k++){
            printf("%d",kostka[3][w][k]);
        }
        putchar('|');
        for(int k = 0; k < N; k++){
            printf("%d",kostka[4][w][k]);
        }
        putchar('\n');
    }
    for(int w =0; w < N; w++){
        for(int i = 0; i < N + 1; i++){
            putchar(' ');
        }
        for(int k = 0; k < N; k++){
            printf("%d",kostka[5][w][k]);
        }
        putchar('\n');
    }
}


int main(){

    int kostka[6][N][N];
    wypelnij(kostka);

    int dziala = 1;
    //zmienna wskazuj�ca czy zako�czy� wykonywanie programu

    int komenda;


    int liczba_war = 1;
    int pot_Licz_war = 0;

    int znak;

    int pocz_lini = 1;

    while(dziala){
        komenda = getchar();

        if(komenda > 47 && komenda < 58){
            if(pot_Licz_war == 0)
                //aby liczyć od zera nie od 1
                liczba_war--;
            liczba_war *= 10;
            liczba_war += (komenda - 48);
            pot_Licz_war++;
        }


        if(komenda == 34)
            //34 - "
            //obraca dodatkowy raz a znak pozostaje ten sam bo zmienia się przy nowym symbolu komendy
            obracaj(kostka,znak, liczba_war);

        if(komenda == 39) {
            // 39 - '
            obracaj(kostka,znak, liczba_war);
            obracaj(kostka, znak, liczba_war);
        }

        if(komenda == 10) {
            // 10- \n
            if(pocz_lini == 0)
                obracaj(kostka, znak, liczba_war);
            pisz(kostka);
            pocz_lini = 1;
        }

        if(komenda > 96 && komenda < 123) {
            //gdy komenda jest litera
            //wykonuje poprzednią komendę potem zmienia wartość zmiennej ostatnia komenda
            if(pocz_lini==0)
                obracaj(kostka,znak, liczba_war);
            //obraca to o poprzedni symbol o ile to nie jest początek lini
            pocz_lini = 0;
            //ostatnia_komenda = komenda;

            //Zerowanie liczby warstw do następnego polecenia
            liczba_war = 1;
            pot_Licz_war = 0;

            if (komenda == 117)
                //u  -117
                znak = 0;
            if (komenda == 108)
                //l - 108
                znak = 1;
            if (komenda == 102)
                //f - 102
                znak = 2;
            if (komenda == 114)
                //r - 114
                znak = 3;
            if (komenda == 98)
                //b - 98
                znak = 4;
            if (komenda == 100)
                //d - 100
                znak = 5;
        }

        if(komenda == 46)
        // "." - 46
            dziala = 0;
    }

    getchar();
    return 0;
}
