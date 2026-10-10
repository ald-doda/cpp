#include <iostream>
using namespace std;

void ucitajNiz(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
}

void stampajNiz(const int niz[], int n) {
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
}

// 26. Broj parnih elemenata vecih od k
int parniveciodK(const int niz[], int n, int k) {
    int brojac = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0 && niz[i] > k) {
            brojac++;
        }
    }

    return brojac;
}

// 27. Razdvajanje na parne i neparne
// Reference omogucavaju da pozivalac dobije duzine nizova.
void formirajNoveNizove(const int niz[], int n,
                       int a[], int b[], int& na, int& nb) {
    na = 0;
    nb = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0) {
            a[na++] = niz[i];
        } else {
            b[nb++] = niz[i];
        }
    }
}

// 28. Dupliranje svakog elementa i ispis
void duplirajNiz(const int niz[], int n) {
    int* newNiz = new int[2 * n];
    int k = 0;

    for (int i = 0; i < n; i++) {
        newNiz[k++] = niz[i];
        newNiz[k++] = niz[i];
    }

    stampajNiz(newNiz, k);
    delete[] newNiz;
}

// 29. Parni na pocetak, neparni na kraj
void parniPaNeparni(int niz[], int n) {
    int* newNiz = new int[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0) {
            newNiz[j++] = niz[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 != 0) {
            newNiz[j++] = niz[i];
        }
    }

    for (int i = 0; i < n; i++) {
        niz[i] = newNiz[i];
    }

    delete[] newNiz;
}

// 30. Prosjek ponderisan ECTS kreditima
// Pretpostavka: ukupan broj kredita je pozitivan.
double prosjek(const int krediti[], const int ocjene[], int n) {
    double suma = 0;
    int ukupnoKredita = 0;

    for (int i = 0; i < n; i++) {
        suma += static_cast<double>(krediti[i]) * ocjene[i];
        ukupnoKredita += krediti[i];
    }

    return suma / ukupnoKredita;
}

bool vidjen(const int niz[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (niz[i] == k) {
            return true;
        }
    }

    return false;
}

// 31. Provjera duplikata
bool imaLiDuplikata(const int niz[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niz[i] == niz[j]) {
                return true;
            }
        }
    }

    return false;
}

int brPojavljivanja(const int niz[], int n, int k) {
    int br = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] == k) {
            br++;
        }
    }

    return br;
}

// 32. Ispis brojeva od 1 do n koji nedostaju
void daLiSePojavljuju(const int niz[], int n) {
    for (int broj = 1; broj <= n; broj++) {
        if (!vidjen(niz, n, broj)) {
            cout << broj << " ";
        }
    }

    cout << endl;
}

// 34. Koeficijenti su poredjani od konstantnog clana:
// a[0] + a[1]*x + a[2]*x*x + ...
// Oba ulazna niza imaju duzinu n.

// Niz c mora imati mjesta za n elemenata.
void zbirPolinoma(const int a[], const int b[], int c[], int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

// Niz c mora imati mjesta za 2*n - 1 elemenata.
void proizvodPolinoma(const int a[], const int b[], int c[], int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
}

// Primjer pokretanja zadatka 26:
// unos: n, zatim n elemenata, zatim k
int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    int* niz = new int[n];
    ucitajNiz(niz, n);

    int k;
    cin >> k;

    cout << "Parnih vecih od k ima: "
         << parniveciodK(niz, n, k) << endl;

    delete[] niz;
    return 0;
}
int main(){
    int n;
    cin >> n;
    int niz[n];
    ucitajNiz(niz, n);
    stampajNiz(niz, n);
    cout << "Parnih vecih od k ima:" << parniveciodK(niz, n, 4) << endl;

    return 0;
}