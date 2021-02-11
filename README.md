# WPI
Projekty domowe z labolatoriów WPI na MIMUW



## Kostka Rubika:
  ### Wprowadzenie
  Kostka Rubika to łamigłówka, która składa się z ruchomych sześciennych bloków.

  Ściany kostki dzielą się na kolorowe kwadraty, należące do poszczególnych bloków. W stanie ułożonym wszystkie kwadraty danej ściany pokryte   są jednym kolorem, dla każdej ściany innym.

  Blok należy do trzech prostopadłych warstw kostki. Bloki można przemieszczać, obracając warstwy o wielokrotność kąta prostego.

  Celem układającego jest doprowadzenie losowo uporządkowanej kostki do stanu ułożonego.

  Najczęściej używa się kostek rozmiaru 3 x 3 x 3, ale są też większe lub mniejsze.

  ### Polecenie
  Napisz program, który wykonuje ciąg rozkazów obracających warstwy kostki rozmiaru N x N x N. Program zaczyna od kostki ułożonej. Na życzenie   drukuje aktualny stan kostki.

  Stałą symboliczną N, określającą rozmiar kostki, należy zdefiniować dyrektywami:

  #ifndef N
  #define N 5
  #endif
  Wskazują one 5 jako wartość domyślną. Inną wartość stałej można wybrać podczas kompilacji programu za pomocą opcji -DN=wartość.

  ### Postać danych
  Dane programu to ciąg rozkazów obrotu warstw i wydruku aktualnego stanu kostki, zakończony kropką.

  Program ignoruje zawartość wejścia po kropce kończącej dane.

  Rozkazem wydruku stanu kostki jest koniec wiersza.

  Rozkaz obrotu warstw składa się z trzech części, które wskazują:

  ścianę kostki,

  liczbę warstw,

  kąt obrotu.

  Ściana jest określona literą:

  u - góra (ang. up),

  l - lewo (ang. left),

  f - przód (ang. front),

  r - prawo (ang. right),

  b - tył (ang. back),

  d - dół (ang. down).

  Jeśli część rozkazu, określająca liczbę warstw, jest pusta, to wskazuje liczbę 1. W przeciwnym przypadku jest pozycyjnym dziesiętnym zapisem   dodatniej liczby warstw. Wartość tej liczby nie przekracza stałej N, definiującej rozmiar kostki.

  Część rozkazu określająca kąt jest albo pusta albo jest apostrofem lub cudzysłowem. Pusta część wskazuje kąt 90 stopni, apostrof to -90       stopni a cudzysłów to 180 stopni.

  Wykonanie rozkazu obrotu, ze ścianą S, liczbą warstw W i kątem K, powoduje jednoczesne obrócenie W warstw, patrząc od strony ściany S, o kąt   K, zgodnie z ruchem wskazówek zegara.

  Składnię danych opisuje gramatyka z symbolem początkowym Dane:

  Dane → CiągRozkazów Kropka
  CiągRozkazów -> ε | Rozkaz CiągRozkazów
  Rozkaz → Obrót | Drukowanie
  Obrót → Strona LiczbaWarstw Kąt
  Drukowanie → KoniecWiersza
  Strona → Litera
  LiczbaWarstw → Jedna | Wiele
  Jedna → ε
  Wiele → Liczba
  Liczba → Cyfra | Liczba Cyfra
  Kąt → Prosty | MinusProsty | Półpełny
  Prosty → ε
  MinusProsty → Apostrof
  Półpełny → Cudzysłów
  Litera → u | l | f | r | b | d
  Cyfra → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
  Apostrof → '
  Cudzysłów → "
  KoniecWiersza → \n
  Kropka → .
  ### Postać wyniku
  Wynik programu jest efektem wykonania rozkazów drukowania aktualnego stanu kostki.

  Wydruk stanu kostki składa się ze znaków 0, 1, 2, 3, 4, 5, symbolizujących kolory kwadratów na ścianach kostki, oraz ze spacji i kresek       pionowych |.

  Przyjmujemy, że w ułożonej kostce:

  kwadraty ściany górnej mają kolor 0,

  kwadraty ściany lewej mają kolor 1,

  kwadraty ściany przedniej mają kolor 2,

  kwadraty ściany prawej mają kolor 3,

  kwadraty ściany tylnej mają kolor 4,

  kwadraty ściany dolnej mają kolor 5.

  Położenie ścian na wydruku stanu kostki jest zgodne ze schematem:

    u
  l|f|r|b
    d
  gdzie u, l, f, r, b, d to, odpowiednio, ściana górna, lewa, przednia, prawa, tylna i dolna.

  Dla stałej N definiującej rozmiar kostki, wydruk stanu kostki składa się z 3 * N + 1 wierszy:

  pierwszy wiersz jest pusty,

  N kolejnych wierszy opisuje ścianę górną,

  następnych N wierszy to opis ściany lewej, przedniej, prawej i tylnej,

  ostatnich N wierszy opisuje ścianę dolną.

  Każdy wiersz opisu ściany górnej i dolnej zaczyna się od N + 1 spacji, po których jest N cyfr określających kolory kwadratów tej ściany.

  Wiersze opisu ściany lewej, przedniej, prawej i tylnej mają kolejno:

  N cyfr określających kolory kwadratów na ścianie lewej,

  znak |,

  N cyfr określających kolory kwadratów na ścianie przedniej,

  znak |,

  N cyfr określających kolory kwadratów na ścianie prawej,

  znak |,

  N cyfr określających kolory kwadratów na ścianie tylnej.

  Na wydruku stanu kostki, cyfry określające kolory kwadratów każdej ściany zajmują obszar rozmiaru N x N.

  Dla ściany lewej, przedniej, prawej i tylnej, kolory kwadratów opisane są w kolejności, jaką zobaczylibyśmy po obrocie całej kostki o         wielokrotność kąta prostego od strony ściany górnej lub dolnej.

  Dla ściany górnej i dolnej kolejność jest taka, jaką zobaczylibyśmy, gdybyśmy obrócili kostkę o wielokrotność kąta prostego od strony ściany   lewej lub prawej.

  ### Przykłady
  Do treści zadania dołączone są pliki .in z przykładowymi danymi i pliki .out z wynikami wzorcowymi.

  Przykłady zakładają, że stała N, definiująca rozmiar kostki, ma wartość 5.

  Dla danych przyklad1.in poprawny wynik to przyklad1.out.

  Dla danych przyklad2.in poprawny wynik to przyklad2.out.

  Dla danych przyklad3.in poprawny wynik to przyklad3.out.

  Walidacja i testy
  Rozwiązania zostaną poddane walidacji, wstępnie badającej zgodność ze specyfikacją.

  Walidacja sprawdzi działanie programu na przykładach dołączonych do treści zadania.

  Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostanie     zerową ocenę poprawności.

  ### Walidacja i testy zostaną przeprowadzone na komputerze students.

  Programy będą kompilowane poleceniem:

  gcc -DN=wartość -std=c11 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g nazwa.c -o nazwa
  gdzie nazwa.c to nazwa pliku z kodem źródłowym a wartość to wartość stałej N definiującej rozmiar kostki.

  Wymagane są wszystkie wymienione opcje kompilatora. Nie będą do nich dodawane żadne inne.

  Zwracamy uwagę, że poszczególne wersje kompilatora gcc mogą się różnić sposobem obsługi tych samych opcji. Przed wysłaniem rozwiązania warto   więc skompilować je i przetestować na students, w sposób opisany powyżej.

  Podczas walidacji i testów, program nazwa będzie uruchamiany pod kontrolą programu Valgrind poleceniem:

  valgrind --leak-check=full -q ./nazwa
  Jeśli Valgrind wykryje błąd, to nawet, gdyby wynik był prawidłowy uznamy, że program testu nie przeszedł.

  Opcja -q powoduje, że jedynymi komunikatami, wypisywanymi przez program Valgrind, są komunikaty o błędach.

  Opcja --leak-check=full wskazuje Valgrindowi, że powinien, między innymi, szukać wycieków pamięci.

  Przyjmujemy, że wynik funkcji main() inny niż 0 informuje o błędzie wykonania programu.

  Poprawność wyniku sprawdzamy, przekierowując na wejście programu zawartość pliku .in i porównując rezultat, za pomocą programu diff, z         plikiem .out, np.:

  < przyklad.in ./nazwa | diff - przyklad.out
  Ocena poprawności wyniku jest binarna. Uznajemy go za poprawny, jeżeli program diff nie wypisze żadnej różnicy między wynikiem programu a     wynikiem wzorcowym.

  ### Uwagi
  Wolno założyć, że dane są poprawne.

  Wolno założyć, że każdy wiersz danych, także ostatni, będzie zakończony reprezentacją końca wiersza \n.

  Należy zadbać, by warunek ten spełniał także wynik programu.

  Efektywność rozwiązania może mieć wpływ na ocenę jego jakości.

  Rozwiązanie rażąco nieefektywne może nie przejść testów poprawności z powodu przekroczenia limitu czasu.

  ### Wskazówki
  Pod Linuxem, pracując z programem interakcyjnie na konsoli, koniec danych sygnalizujemy, naciskając klawisze Ctrl-D.

  W przygotowaniu danych testowych może pomóc polecenie tee. Przesyła ono dane z wejścia na wyjście, jednocześnie zapisując ich kopię w pliku,   którego nazwa jest argumentem polecenia.

  Wykonanie:

  tee test.in | ./nazwa
  uruchomi program nazwa w trybie interakcyjnym, tworząc kopię danych testowych w pliku test.in. Dzięki temu test na tych samych danych będzie   można powtórzyć, wykonując polecenie:

  < test.in ./nazwa > test.out
  
  
  
  
  
  ## Sokoban:
  ### Wprowadzenie
Sokoban jest jednoosobową grą logiczną rozgrywaną na dwuwymiarowej planszy o kwadratowych polach.

Niektóre pola planszy są puste, na innych są ściany lub skrzynie.

Pewna liczba pól jest oznaczona jako pola docelowe. Polem docelowym może być pole puste lub pole, na którym jest skrzynia.

Na jednym z pól planszy jest postać sterowana przez gracza. Może się ona przesuwać na pola sąsiadujące z aktualnym w pionie lub poziomie.

Za sąsiadujące z polem w wierszu w i kolumnie k uznajemy pola, które są w:

wierszu w - 1, kolumnie k,

wierszu w + 1, kolumnie k,

wierszu w, kolumnie k - 1,

wierszu w, kolumnie k + 1.

Postać może się przesunąć na pole, jeśli jest ono puste lub jest na nim skrzynia, którą postać może pchnąć.

Pchnięcie skrzyni jest możliwe, jeśli bezpośrednio za nią, w kierunku ruchu postaci, jest pole puste. Nie jest możliwe przesunięcie postaci lub pchnięcie skrzyni poza planszę. Nie jest możliwe pchnięcie na raz więcej niż jednej skrzyni.

Celem gry jest umieszczenie skrzyń na polach docelowych.

### Polecenie
Napisz program umożliwiający grę w Sokobana.

Program czyta opis stanu początkowego planszy, pisze go na wyjście a następnie czyta i wykonuje kolejne polecenia.

Po wykonaniu każdego polecenia program pisze aktualny stan planszy. Robi to niezależnie od tego, czy stan planszy, w rezultacie wykonania polecenia, zmienił się.

Rozpoznawane są polecenia pchnięcia skrzyni i cofnięcia wykonanego wcześniej pchnięcia.

Inaczej, niż w typowych implementacjach Sokobana, użytkownik nie musi podawać ruchów przesuwających postać po pustych polach. Program sam ustala, jak doprowadzić postać na pole, z którego będzie możliwe pchnięcie skrzyni we wskazanym kierunku.

### Postać danych
Na wejściu programu jest opis stanu początkowego planszy, pusty wiersz i ciąg jednowierszowych poleceń, zakończony wierszem zaczynającym się od kropki ..

Program ignoruje zawartość wejścia po kropce kończącej dane.

Opis planszy składa się z niepustych wierszy, w których są jednoznakowe reprezentacje stanu pól:

-

puste pole, które nie jest polem docelowym,

+

puste pole, które jest polem docelowym,

#

ściana,

@

pole, nie będące polem docelowym, na którym jest postać,

*

pole docelowe, na którym jest postać,

[a .. z] (mała litera)

pole, które nie jest polem docelowym, na którym jest skrzynia o podanej nazwie,

[A .. Z] (wielka litera)

pole docelowe, na którym jest skrzynia o nazwie będącej małą literą odpowiadającą podanej wielkiej literze.

W poprawnym opisie planszy jest dokładnie jedna postać. Każda skrzynia, oznaczona literą alfabetu łacińskiego, może wystąpić tylko raz.

Program rozpoznaje polecenia:

[a .. z][2 | 4 | 6 | 8] (mała litera, po której jest cyfra 2, 4, 6 lub 8)

Pchnięcie skrzyni o nazwie, będącej pierwszym znakiem polecenia, w kierunku określonym drugim znakiem. Cyfra 2 oznacza pchnięcie w dół, 8 w górę, 4 w lewo a 6 w prawo.

Na pole, z którego można wykonać pchnięcie, postać doprowadzana jest ścieżką składającą się z pustych pól. Nie może być na niej ściany ani skrzyni.

Jeśli wykonanie pchnięcia nie jest możliwe, bo postać nie może podejść do skrzyni lub skrzyni nie da się pchnąć, stan planszy nie zmienia się.

0

Cofnięcie ostatniego wykonanego i jeszcze nie cofniętego pchnięcia.

Postać wraca na pole, na którym była przed cofanym pchnięciem.

Jeśli nie było żadnego pchnięcia, które można cofnąć, polecenie nie zmienia stanu planszy.

### Postać wyniku
Wynikiem programu jest ciąg opisów planszy. Pierwszy z nich to opis stanu początkowego a kolejne to opisy stanu planszy po wykonaniu każdego polecenia.

Opis planszy w wyniku programu ma postać taką, jak w danych, ale bez kończącego pustego wiersza.

### Przykłady
Do treści zadania dołączone są pliki .in z przykładowymi danymi i pliki .out z wynikami wzorcowymi.

Dla danych przyklad1.in poprawny wynik to przyklad1.out.

Dla danych przyklad2.in poprawny wynik to przyklad2.out.

Dla danych przyklad3.in poprawny wynik to przyklad3.out.

Walidacja i testy
Rozwiązania zostaną poddane walidacji, wstępnie badającej zgodność ze specyfikacją.

Walidacja sprawdzi działanie programu na przykładach dołączonych do treści zadania.

Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostanie zerową ocenę poprawności.

Walidacja i testy zostaną przeprowadzone na komputerze students.

Programy będą kompilowane poleceniem:

gcc -std=c11 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g nazwa.c -o nazwa
gdzie nazwa.c to nazwa pliku z kodem źródłowym a wartość to wartość stałej N definiującej rozmiar kostki.

Wymagane są wszystkie wymienione opcje kompilatora. Nie będą do nich dodawane żadne inne.

Zwracamy uwagę, że poszczególne wersje kompilatora gcc mogą się różnić sposobem obsługi tych samych opcji. Przed wysłaniem rozwiązania warto więc skompilować je i przetestować na students, w sposób opisany powyżej.

Podczas walidacji i testów, program nazwa będzie uruchamiany pod kontrolą programu Valgrind poleceniem:

valgrind --leak-check=full -q ./nazwa
Jeśli Valgrind wykryje błąd, to nawet, gdyby wynik był prawidłowy uznamy, że program testu nie przeszedł.

Opcja -q powoduje, że jedynymi komunikatami, wypisywanymi przez program Valgrind, są komunikaty o błędach.

Opcja --leak-check=full wskazuje Valgrindowi, że powinien, między innymi, szukać wycieków pamięci.

Przyjmujemy, że wynik funkcji main() inny niż 0 informuje o błędzie wykonania programu.

Poprawność wyniku sprawdzamy, przekierowując na wejście programu zawartość pliku .in i porównując rezultat, za pomocą programu diff, z plikiem .out, np.:

< przyklad.in ./nazwa | diff - przyklad.out
Ocena poprawności wyniku jest binarna. Uznajemy go za poprawny, jeżeli program diff nie wypisze żadnej różnicy między wynikiem programu a wynikiem wzorcowym.

### Uwagi
Wolno założyć, że dane są poprawne.

Planszy, której nie da się rozwiązać, np. dlatego, że jest więcej skrzyń niż pól docelowych, nie uznajemy za błędną.

Wolno założyć, że każdy wiersz danych, także ostatni, będzie zakończony reprezentacją końca wiersza \n.

Należy zadbać, by warunek ten spełniał także wynik programu.

Efektywność rozwiązania może mieć wpływ na ocenę jego jakości.

Rozwiązanie rażąco nieefektywne może nie przejść testów, a nawet walidacji, z powodu przekroczenia limitu czasu.

Powyższa uwaga odnosi się, w szczególności, do rozwiązań, w których koszt sprawdzenia możliwości wykonania pchnięcia jest wykładniczy względem liczby wolnych pól na planszy.

Wskazówki
Pod Linuxem, pracując z programem interakcyjnie na konsoli, koniec danych sygnalizujemy, naciskając klawisze Ctrl-D.

Jeśli opis stanu początkowego planszy, zakończony pustym wierszem, jest w pliku plansza.txt, to program uruchomiony poleceniem:

cat plansza.txt - | ./sokoban
wczyta planszę z pliku plansza.txt a następnie będzie pobierał polecenia z klawiatury.

Taki sposób uruchomienia programu umożliwi pracę interakcyjną.

W przygotowaniu danych testowych może pomóc polecenie tee. Przesyła ono dane z wejścia na wyjście, jednocześnie zapisując ich kopię w pliku, którego nazwa jest argumentem polecenia.

Wykonanie polecenia:

cat plansza.txt - | tee test.in | ./sokoban
uruchomi program sokoban w trybie interakcyjnym, zapisując kopię danych testowych w pliku test.in.

Test na tych samych danych będzie można powtórzyć poleceniem:

< test.in ./sokoban > test.out
