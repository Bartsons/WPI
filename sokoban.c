#include <stdio.h>
#include <stdlib.h>

char* wejscie(int *n, int *m, int *l){

    char *wiersz = NULL;
    char c = getchar();
    char lc = c;

    int len = 0;
    int w = 0;

    *m = 0;
    *n = 0;

    while(c != 10 || lc != 10){
        if(c == 10){
            *m = *m + 1;
            w = 0;
        }
        w ++;
        len++;
        wiersz = realloc(wiersz, len * sizeof(char));
        wiersz[len - 1] = c;

        lc = c;
        c = getchar();
        if(w > *n)
            *n = w;
    }
    *l = len;
    return wiersz;
}

void print_map(int n, int m, char mapa[][n]){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mapa[i][j] > 32 && mapa[i][j] < 123)
                putchar(mapa[i][j]);
        }
        printf("\n");
    }
}
void zeruj(int n, int m, char odw[][n]){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            odw[i][j] = 0;
        }
    }
}
void zeruj_mape(int n, int m, char map[][n]){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = 32;
        }
    }
}

void mapuj(char* plansza, int n, int m, char mapa[][n]){
    zeruj_mape(n, m,  mapa);
    int i = 0;
    int k = 0;
    while(plansza[i] != 10){
        mapa[0][i] = plansza[i];
        i++;
    }
    i++;

    for (int w = 1; w < m; w++) {
        k=0;
        while(plansza[i] != 10){
            mapa[w][k] = plansza[i];
            i++;
            k++;
        }
        i++;
        while(k < n){
            mapa[w][k] = 32;
            k++;
        }
    }
}


void znajdz(int *czy_cel, int n,  int m,  char mapa[][n], char znak, char kier, int wsp[]){
    int w;
    int k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mapa[i][j] == znak || mapa[i][j] == znak - 32){
                w = i;
                k = j;
            }
        }
    }
    int a = w;
    int b = k;
    if(kier == 56)
        a--;
    if(kier == 50)
        a++;
    if(kier == 52)
        b--;
    if(kier == 54)
        b++;
    if(a < 0 || b < 0 || a >= m || b >= n ||
        mapa[a][b] == 32 || mapa[a][b] == 35 ||
        mapa[a][b] == 10 || (mapa[a][b] > 64 && mapa[a][b] < 123 ))
        (*czy_cel) = 0;
    else{
        if(mapa[a][b] == 43 || mapa[a][b] == 45 || mapa[a][b] ==  64
            || mapa[a][b] == 42)
            (*czy_cel) = 1;}
    wsp[0] = w;
    wsp[1] = k;
    wsp[2] = a;
    wsp[3] = b;
}

void znajdz_postac(int n, int m, char mapa[][n], int wsp[]){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mapa[i][j] == 64 || mapa[i][j] == 42){
                wsp[4] = i;
                wsp[5] = j;
            }
        }
    }
}

int dozw_pom(int n, int m, char mapa[][n], char odw[][n], int y, int x){
    //Czy pole jest poza mapa
    if(y < 0 || y >= m || x < 0 || x >= n)
        return 0;
    //Czy gracz stoi na polu
    if(mapa[y][x] == 42 || mapa[y][x] == 64)
        return 1;
    //Czy juz odwiedzone
    if(odw[y][x] == 1)
        return 0;
    odw[y][x] = 1;
    //Czy na pole nie da sie wejsc
    if(mapa[y][x] == 32 || mapa[y][x] == 10 || mapa[y][x] == 35 || (mapa[y][x] > 64 && mapa[y][x] < 123))
        return 0;
    //Czy pole jest wolne
    if(mapa[y][x] == 43 || mapa[y][x] == 45){
       if(dozw_pom(n, m, mapa, odw, y - 1, x) || dozw_pom(n, m, mapa, odw, y + 1, x) ||
                dozw_pom(n, m, mapa, odw, y, x - 1) || dozw_pom(n, m, mapa, odw, y, x + 1))
           return 1;
       else
           return 0;
    }
    else{
        return 0;
    }
}


int dozwolony(int n, int m, char mapa[][n], char odw[][n], int wsp[]){
    //Sprawdza czy nie ma dwoch skrzyn kolo siebie
    if(mapa[wsp[2]][wsp[3]] > 64 && mapa[wsp[2]][wsp[3]] < 123 )
        return 0;
    //Czy nowe pole gracza jest wolne
    char pom = mapa[2 * wsp[0] - wsp[2]][2 * wsp[1] - wsp[3]];

    if(pom == 43 || pom == 45 || pom == 42 || pom == 64){
        return(dozw_pom(n, m, mapa, odw, 2 * wsp[0] - wsp[2], 2 * wsp[1] - wsp[3]));
    }
    else{
        return 0;
    }
}

void wyk_ruch(int n, int m, char mapa[][n], char odw[][n], char znak, char kier, int *pchniecia, int *stos){
    int wsp[6];
    //wps 1, 2 - y, x skrzyni, 3, 4 nowe y, x skrzyni, 5, 6 - y, x gracza
    int czy_cel = 0;

    znajdz(&czy_cel, n,  m,  mapa, znak, kier, wsp);
    char doc = mapa[wsp[2]][wsp[3]];
    if(czy_cel && (doc == 42 || doc == 43 || doc == 45 || doc == 64)){
        znajdz_postac(n, m, mapa, wsp);
        if(dozwolony(n, m, mapa, odw, wsp)){
            for(int i = 0; i < 6; i++){
                stos[6 * (*pchniecia) + i] = wsp[i];
            }
            (*pchniecia) += 1;
            //Zmieniamy pozycje na ktorej byl gracz
            if(mapa[wsp[4]][wsp[5]] == 64)
                mapa[wsp[4]][wsp[5]] = 45;
            else
                mapa[wsp[4]][wsp[5]] = 43;
            //przwsuniecie skrzyni na nowa pozycje, 43+, 45-
            if(mapa[wsp[2]][wsp[3]] == 43){
                //Duza litera
                if(mapa[wsp[0]][wsp[1]] < 91 && mapa[wsp[0]][wsp[1]] > 64){
                    mapa[wsp[2]][wsp[3]] = mapa[wsp[0]][wsp[1]];
                    mapa[wsp[0]][wsp[1]] = 43;
                }
                else{//Mala litera
                    mapa[wsp[2]][wsp[3]] = mapa[wsp[0]][wsp[1]] - 32;
                    mapa[wsp[0]][wsp[1]] = 45;
                }

            }//Na minusa
            else{//Duza litera
                if(mapa[wsp[0]][wsp[1]] < 91 && mapa[wsp[0]][wsp[1]] > 64){
                    mapa[wsp[2]][wsp[3]] = mapa[wsp[0]][wsp[1]] + 32;
                    mapa[wsp[0]][wsp[1]] = 43;
                } else{
                    mapa[wsp[2]][wsp[3]] = mapa[wsp[0]][wsp[1]];
                    mapa[wsp[0]][wsp[1]] = 45;
                }
            }
            //Przesuniecie gracza na pozycje skrzyni
            if(mapa[wsp[0]][wsp[1]] == 43)
                mapa[wsp[0]][wsp[1]] = 42;
            else
                mapa[wsp[0]][wsp[1]] = 64;
        }
    }
}


void cofnij(int n,char mapa[][n], int pchniecia, int *stos){
    char g = mapa[stos[6 * pchniecia + 4]][stos[6 * pchniecia + 5]];
    if(g == 43 || g == 42 || (g > 64 && g < 91 ))
        mapa[stos[6 * pchniecia + 4]][stos[6 * pchniecia + 5]] = 42;
    else
        mapa[stos[6 * pchniecia + 4]][stos[6 * pchniecia + 5]] = 64;
    //Powrot skrzyni na poprzednia pozycja
    if(mapa[stos[6 * pchniecia + 0]][stos[6 * pchniecia + 1]] == 42){
        //gracz stoi na docelowym
        if(mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] > 96){
            //mala litera
            mapa[stos[6 * pchniecia + 0]][stos[6 * pchniecia + 1]] =
                    mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] - 32;
            mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] = 45;
        } else{//duza litera
            mapa[stos[6 * pchniecia + 0]][stos[6 * pchniecia + 1]] =
                    mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]];
            mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] = 43;
        }
    }else{//gracz nie jest na docelowym
        if(mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] > 96){//mala litera
            mapa[stos[6 * pchniecia + 0]][stos[6 * pchniecia + 1]] =
                    mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]];
            mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] = 45;
        } else{//duza litera
            mapa[stos[6 * pchniecia + 0]][stos[6 * pchniecia + 1]] =
                    mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] + 32;
            mapa[stos[6 * pchniecia + 2]][stos[6 * pchniecia + 3]] = 43;
        }
    }
    if(g == 43 || g == 42 || (g > 64 && g < 91 ))
        mapa[stos[6 * pchniecia + 4]][stos[6 * pchniecia + 5]] = 42;
    else
        mapa[stos[6 * pchniecia + 4]][stos[6 * pchniecia + 5]] = 64;
}

void czytaj_ruchy(int n, int m, char mapa[][n]){

    int pchniecia = 0;
    int wysokosc = 1;
    int *stos = (int*)malloc(6 * sizeof(int));
    for (int i = 0; i < 6 ; i++) {
        stos[i] = 0;
    }
    char odw[m][n];

    char znak;
    char kier;
    znak = getchar();

    while(znak != 46){
        if(znak == 48){
            if(pchniecia > 0) {
                pchniecia -= 1;
                cofnij(n, mapa, pchniecia, stos);
            }
        }
        else{
            kier = getchar();
            zeruj(n, m, odw);
            wyk_ruch(n, m, mapa, odw, znak, kier, &pchniecia, stos);
            if(pchniecia == wysokosc){
                wysokosc++;
                stos = realloc(stos, wysokosc * 6 * sizeof(int));
            }
        }
        znak = getchar();//nowa linia
        print_map(n, m, mapa);
        znak = getchar();
    }
    free(stos);
}


int main(){

    char *plansza;
    int n;
    int m;
    int len;

    plansza = wejscie(&n, &m, &len);

    char mapa[m][n];
    mapuj(plansza, n,  m, mapa);
    print_map(n, m, mapa);

    czytaj_ruchy(n, m, mapa);

    free(plansza);
    return 0;
}

