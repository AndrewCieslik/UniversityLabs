# UniversityLabs

Plik Rational:

Zaprojektuj klasę Rational, reprezentującą liczby wymierne jako pary liczb całkowitych (licznik i mianownik), wraz z podstawowymi działaniami arytmetycznymi i porównaniem. W klasie powinny znaleźć się nastę-pujące metody publiczne (oprócz konstruktora):
1. dodawanie: Rational add(Rational arg);
2. mnożenie: Rational mul(Rational arg);
3. odejmowanie: Rational sub(Rational arg);
4. dzielenie: Rational div(Rational arg);
5. równość: boolean equals(Rational arg);
6. porównanie: int compareTo(Rational arg);
7. tekstowa reprezentacja liczby: String toString().
Metody 1–4 powinny zwracać jako rezultat referencję do nowego obiektu klasy Rational, będącego wynikiem operacji wykonanej na argumencie arg i this. Metoda 5. ma porównywać obiekty klasy Rational na podstawie wartości liczb, np. 1/2 = 2/4. Metoda 6. ma działać podobnie, jak odpowiadająca jej metoda compareTo(Object o) z interfejsu

java.lang.Comparable:
Jeśli this jest równe arg, to zwraca 0.
Jeśli this jest mniejsze od arg, to zwraca −1.
Jeśli this jest większe niż arg, to zwraca 1.
Metoda 7. ma zwracać łańcuch znakowy opisujący ten obiekt. Na przykład może to być napis postaci 1/2 lub -1/1.
Nie trzeba skracać ułamków.


Plik TextFileExercise1:

Read/write to file exercise.
Zadanie 1.

Zapisz w pliku tekstowym 1000 liczb losowych (całkowitych).
Skopiuj do dwóch plików liczby:
Do pierwszego: Większe od średniej
Do drugiego: Mniejsze od średniej

Plik TextFileExercise2:
Zadanie 2.
Plik tekstowy zawiera dane domów w postaci:
NazwaDomu-CenaDomu-LiczbaKondygnacji-Lokalizacja
Np.
Chata-10000.00-1-Wies
Willa-999999.99-4-Miasto
Skopiuj do drugiego pliku tekstowego, parterowe domy wiejskie, zmniejszając ich cenę o 10%

Zadanie 3.
Wykonaj statystykę dziennikarską pliku tekstowego:

    Oblicz liczbę słów
    Oblicz średnią długość zdania (obliczamy stosunek liczby kropek do liczby znaków)
 
Zadanie 4. RandomAccessFile
Pliki o swobodnym dostępie.
Termin: 19 czerwca 2022 23:59
Instrukcje
Istnieje plik danych zawierający opisy domów zapisane jako kolejne czwórki:  
String nazwaDomu
int liczbaKondygnacji
double cena
String lokalizacja (zapisana jako "wies" "miasto")
 
Napisz program, który obnizy w tym pliku ceny domów parterowych znajdujących się na wsi o 10%.
 
Jako odpowiedź wgraj tylko powyższy program.
 
Aby przetestowac działanie, można napisać program, który będzie zapisywał w pliku dane takich domów. Proponuję, aby też użyć klasy RandomAccesFile i napisać program w ten sposób, że będzie dopisywał jeden dom na końcu pliku. W ten sposób można zapisać tyle domów, ile się chce.
