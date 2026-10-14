#include <iostream>
using namespace std;
void ucitajNiz(int niz[], int n){
    for(int i = 0; i < n; i++){
        cin >> niz[i];
    }
}
void stampajNiz(int niz[], int n){
    for(int i = 0; i < n; i++){
        cout << niz[i] << " ";
    }
    cout << endl;
}
//26. Parni i veci od k
int zad26(int niz[], int n, int k){
    int br = 0;
    for(int i = 0; i < n; i++){
        if(niz[i] > k && niz[i] % 2 == 0) br++;
    }


    return br;
}
//27.dvaNiza od parnih i neparnih
void zad27(int a[], int n){
    int c[n] = {0};
    int b[n] = {0};
    int z = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            b[z++] = a[i];
        } else{
            c[k++] = a[i];
        }
    }

    for(int i = 0; i < z; i++){
        cout << b[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < k; i++){
        cout << c[i] << " ";
    }
    cout << endl;
}
//28. Dupliraj elemente npr 123 112233
void zad28(int a[], int n){
    int b[2*n] = {0};
    int k = 0;
    for(int i = 0; i < n; i++){
        b[k++] = a[i];
        b[k++] = a[i];
    }

    for(int j = 0; j < 2*n; j++){
        cout << b[j] << " ";
    }
    cout << endl;
}
//29. premjestanje parnih i neparnih
void zad29(int a[], int n){
    int* privremeni = new int[n];
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            privremeni[k++] = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            privremeni[k++] = a[i];
        }
    }

    for(int i = 0; i < k; i++){
        a[i] = privremeni[i];
    }
    delete[] privremeni; 

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
//30 prosjek studenta
float zad30(int* ocjene, int* ects, int n){
    float sumOcjena = 0.0;
    float krediti = 0.0;
    for(int i = 0; i < n; i++){
        sumOcjena += ocjene[i] * ects[i];
        krediti += ects[i];
    }
    return sumOcjena/krediti;
}
//31. ima li ponavljanja u nizu
int brPojavljivanja(int niz[], int n, int k){
    int br = 0;
    for(int i = 0; i < n; i++){
        if(niz[i] == k) br++;
    }
    return br;
}
bool duplikati(int niz[], int n){
    for(int i = 0; i < n; i++){
        if(brPojavljivanja(niz, n, niz[i]) > 1) return true;
    }
    return false;

}
//32. konfuzna postavka al da probam
void zad32(int niz[], int n){
    int* pomocni = new  int[n];
    int k = 0;
    for(int i = 1; i <= n; i++){
        pomocni[k++] = i;
    }
    int* vidjen = new int[n]{};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(niz[j] == pomocni[i]){
                vidjen[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(vidjen[i] == 0){
            cout << pomocni[i] << " ";
        }
    }
    cout << endl;
    delete[] pomocni;
    delete[] vidjen;
}
#include <algorithm>
int najvisePojavljivanja(int niz[], int n){
    int* pomniz = new int[n];
    for(int i = 0; i < n; i++){
        pomniz[i] = brPojavljivanja(niz, n, niz[i]);
    }

    int najvise = *max_element(pomniz, pomniz+n);

    int rezultat = 0;
    for(int i = 0; i < n; i++){
        if(najvise == pomniz[i]){
            rezultat = niz[i];
            break;
        }
    }


    delete[] pomniz;
    return rezultat;
}
void zbirPolinoma(int a[], int b[], int n){
    int c[n] = {0};

    for(int i = 0; i < n; i++){
        c[i] = a[i]+b[i];
    }
}
void proizvodPolinoma(int a[], int b[], int n){
    int c[2*n-1] = {0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i+j] += a[i]*b[j];
        }
    }

}
int sumaPrije(int niz[], int n, int k){
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += niz[i];
    }
    return sum;
}
int sumPoslije(int niz[], int n, int k){
    int sum = 0;
    for(int i = k+1; i < n; i++){
        sum += niz[i];
    }

    return sum;
}
void zad35(int niz[], int n){
    int br = 0;
    for(int i = 0; i < n; i++){
        if(sumaPrije(niz, n, i) == sumPoslije(niz, n, i)){
            cout << i << " ";
            br++;
        }
        
    }
    if(br == 0) cout << -1 << " ";
    cout << endl;
}
void zad35optimizovan(int niz[], int n){
    int ukupna = 0;
    int lijeva = 0;
    int br = 0;

    for(int i = 0; i < n; i++){
        ukupna += niz[i];
    }
    for(int i = 0; i < n; i++){
        int desna = ukupna - lijeva - niz[i];

        if(desna == lijeva){
            cout << i << " ";
            br++;
        }

        lijeva += niz[i];
    }
    if(br== 0){
        cout << -1 << "";
    }
    cout << endl;
}

    void zad36S(int a[], int b[], int n){
    int* c = new int[n+1]{};
    int prenos = 0;

    for(int i = n-1; i >= 0; i--){
    int suma = a[i] + b[i] + prenos;

    c[i+1] = suma % 10;
    prenos = suma / 10;
}

    c[0] = prenos;

    for(int i = 0; i < n+1; i ++){
        cout << c[i] << " ";
    }
    cout << endl;

    delete[] c;
}
void zad36O(int a[], int b[], int n){
    int* c = new int[n]{};
    int pozajmica = 0;

    for(int i = n-1; i >= 0; i--){
        int razlika = a[i]-b[i]-pozajmica;

        if(razlika < 0){
            razlika += 10;
            pozajmica = 1;
        }
        else{
            pozajmica = 0;
        }
        c[i] = razlika;
    }


    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    cout << endl;
    delete[] c;
}
void zad36S2(int a[], int b[], int n, int m){
    int duzina = max(n, m) + 1;
    int* c = new int[duzina]{};

    int i = n-1;
    int j = m-1;
    int k = duzina-1;
    int prenos = 0;
    while(i >= 0 || j >= 0){
        int cifraA = (i >= 0) ? a[i] : 0;
        int cifraB = (j >= 0) ? b[j] : 0;

        int suma = cifraA + cifraB + prenos;

        c[k] = suma % 10;
        prenos = suma / 10;



        i--;
        j--;
        k--;
    }

    c[k] = prenos;

    for(int i = 0; i < duzina; i++){
        cout << c[i] << " ";
    }
    cout << endl;
    delete[] c;

}

void zad36SO(int a[], int b[], int n, int m){
    int duzina = max(n, m) + 1;
    int* c = new int[duzina]{};

    int i = n-1;
    int j = m-1;
    int k = duzina-1;
    int pozajmica = 0;
    while(i >= 0 || j >= 0){
        int cifraA = (i >= 0) ? a[i] : 0;
        int cifraB = (j >= 0) ? b[j] : 0;

        int razlika = cifraA - cifraB - pozajmica;

        if(razlika < 0){
            razlika += 10;
            pozajmica = 1;
        }
        else{
            pozajmica = 0;
        }
        c[k] = razlika;


        i--;
        j--;
        k--;
    }


    int pocetak = 0;

    while(pocetak < duzina - 1 && c[pocetak] == 0){
        pocetak++;
    }

    for(int i = pocetak; i < duzina; i++){
        cout << c[i] << " ";
     }
    cout << endl;
    delete[] c;

}
int main(){
    int n;
    cin >> n;
    int niz[n];
    ucitajNiz(niz, n);
    stampajNiz(niz, n);
    zad28(niz, n);
    zad29(niz, n);
    zad32(niz, n);
    


    return 0;
}