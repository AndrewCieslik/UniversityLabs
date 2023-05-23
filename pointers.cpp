#include <cstdlib>
#include <iostream>

using namespace std;
const int MAX_LEN = 128;

int str_len(char *s) {
    int str_length = 0;
    for (; *s != '\0'; ++s) {
        str_length++;
    }
    return str_length;
}

int lwr_str_cnt(char *s) {
    int lwr = 0;
    for (; *s != '\0'; s++) {
        if (*s >= 97 && *s <= 122) {
            lwr++;
        }
    }
    return lwr;
}

int upr_str_cnt(char *s) {
    int upper = 0;
    for (; *s != '\0'; s++) {
        if (*s >= 65 && *s <= 90) {
            upper++;
        }
    }
    return upper;
}

int dgt_str_cnt(char *s) {
    int dgt = 0;
    for (; *s != '\0'; s++) {
        if (*s >= 48 && *s <= 57) {
            dgt++;
        }
    }
    return dgt;
}

int nalpha_str_cnt(char *s) {
    int nalpha = 0;
    for (; *s != '\0'; s++) {
        if (*s >= 48 && *s <= 57 || *s >= 65 && *s <= 90 || *s >= 97 && *s <= 122) {
            nalpha++;
        }
    }
    return nalpha;
}

int chr_str_cnt(char c, char *s) {
    int char_counter = 0;
    for (; *s != '\0'; s++) {
        if (*s == c) {
            char_counter++;
        }
    }
    return char_counter;
}

char *chr_str_pos(char c, char *s) {
    int i = -1;
    char *result = NULL;
    for (; *s != '\0'; s++) {
        if (*s == c) {
            result = s;
            return result;
        }
        i++;
    }
    return NULL;
}

char *chr_str_rpos(char c, char *s) {
    char *result = NULL;
    for (; *s != '\0'; s++) {
        if (*s == c) {
            result = s;
        }
    }
    return (result == NULL) ? NULL : result;
}

char *str_rev(char *s) {
    int length = 0;
    char *end = s;

    while (*end != '\0') {
        length++;
        end++;
    }

    end--;  // before '\0'

    char *start = s;
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return s;
}

/*
  int str_word_count(char * s)

  Funkcja wyznacza liczbe slow w tablicy s. Jako slowo
  rozumiemy ciag liter cyfr i znakow podkreslenia. Slowa
  moga być rozdzielane jednym lub wieloma znakami spacji, tabulacji,
  podzialu wiersza.

  Przyklad:
  Napis: "Ala _ma_    kot_ta i    dwa psy"
  Liczba slow: 6

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba slow w napisie s
*/

int str_word_count(char *s) {
    if (*s == '\0') {
        return 0;
    }
    int word_counter = 0;
    bool found_new_word;
    for (; *s != '\0'; s++) {
        if (*s == ' ' && *(s + 1) == ' ') {
            s++;
            continue;
        }
        if (*s >= 48 && *s <= 57 || *s >= 65 && *s <= 90 || *s >= 97 && *s <= 122 || *s == '_') {
            found_new_word = true;
        } else {
            found_new_word = false;
            while (*s != '\0' && *s != ' ') {
                s++;
            }
        }
        if (*(s + 1) == ' ' || *(s + 1) == '\0' && found_new_word == true) {
            word_counter++;
        }
    }
    return word_counter;
}

int main() {
    char line[MAX_LEN];
    char c;
    char *pos;

    cout << "\n\nWpisz linie tekstu: ";
    cin.getline(line, MAX_LEN - 1);

    cout << "\nLiczba znakow         : " << str_len(line);
    cout << "\nLiczba malych liter   : " << lwr_str_cnt(line);
    cout << "\nLiczba duzych liter   : " << upr_str_cnt(line);
    cout << "\nLiczba cyfr           : " << dgt_str_cnt(line);
    cout << "\nLiczba znakw alphanum : " << nalpha_str_cnt(line);

    cout << "\n\nPodaj pojedynczy znak: ";
    cin >> c;

    cout << "\nLiczba wystapien znaku " << c << ": " << chr_str_cnt(c, line);

    if ((pos = chr_str_pos(c, line)) != 0)
        cout << "\nPierwsze wystapienie znaku " << *pos << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    if ((pos = chr_str_rpos(c, line)) != 0)
        cout << "\nOstatnie wystapienie znaku " << *pos << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    cout << "\n\nNapis oryginalny : " << line;
    cout << "\nNapis odwrocony  : " << str_rev(line);
    cout << "\nLiczba slow w napisie: " << str_word_count(line);
    cin.ignore();
    cin.get();
    return EXIT_SUCCESS;
}
