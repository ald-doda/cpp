#include <iostream>
using namespace std;

double FtoC(double F) {
    return (F - 32) * 5.0 / 9.0;
}

double vrijeme(double gb) {
    double bajti = gb * 1024.0 * 1024 * 1024;
    double biti = bajti * 8;
    double brzina = 100000000.0;

    return biti / brzina;
}

void piramidaUzWhile(int n) {
    int i = 0;

    while (i < n) {
        int j = 0;

        while (j <= i) {
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    while (i > 1) {
        i--;
        int j = 0;

        while (j < i) {
            cout << "*";
            j++;
        }

        cout << endl;
    }
}

int brRazlicitih(int n) {
    int brojac = 0;
    bool vidjeno[10] = {false};

    // Pretvaranje prije negacije izbjegava prekoracenje int.
    long long broj = n;

    if (broj < 0) {
        broj = -broj;
    }

    if (broj == 0) {
        return 1;
    }

    while (broj != 0) {
        int cif = broj % 10;

        if (!vidjeno[cif]) {
            vidjeno[cif] = true;
            brojac++;
        }

        broj /= 10;
    }

    return brojac;
}

// Vraca indeks najveceg elementa.
// Pretpostavka: niz ima najmanje jedan element.
int najcesciElement(const int niz[], int n) {
    int indeks = 0;

    for (int i = 1; i < n; i++) {
        if (niz[i] > niz[indeks]) {
            indeks = i;
        }
    }

    return indeks;
}

int najcescaCifra(int n) {
    int pojavljivanja[10] = {0};
    long long broj = n;

    if (broj < 0) {
        broj = -broj;
    }

    if (broj < 10) {
        return static_cast<int>(broj);
    }

    while (broj != 0) {
        int cif = broj % 10;
        pojavljivanja[cif]++;
        broj /= 10;
    }

    return najcesciElement(pojavljivanja, 10);
}

int savrsenBroj(int n) {
    if (n <= 1) {
        return 0;
    }

    long long sum = 0;

    // Nijedan pravi djelilac nije veci od n / 2.
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

bool dvojak(int n) {
    return brRazlicitih(n) <= 2;
}

// Pretpostavka: n je pozitivan prirodan broj.
int najbliziDvojak(int n) {
    int d = 0;

    while (true) {
        if (n - d > 0 && dvojak(n - d)) {
            return n - d;
        }

        // Racunanje u long long izbjegava prekoracenje.
        long long veci = static_cast<long long>(n) + d;

        // Ako veci kandidat ne staje u int, trazimo dalje naniže.
        if (veci <= 2147483647LL &&
            dvojak(static_cast<int>(veci))) {
            return static_cast<int>(veci);
        }

        d++;
    }
}

int main() {
    cout << "Celzijusi: " << FtoC(212) << endl;
    cout << "Vrijeme za 1 GB: " << vrijeme(1) << endl;

    piramidaUzWhile(5);

    cout << "Razlicitih cifara: " << brRazlicitih(122333) << endl;
    cout << "Najcesca cifra: " << najcescaCifra(122333) << endl;
    cout << "Da li je 28 savrsen: " << savrsenBroj(28) << endl;
    cout << "Da li je 2020 dvojak: " << dvojak(2020) << endl;
    cout << "Najblizi dvojak broju 123: "
         << najbliziDvojak(123) << endl;

    return 0;
}