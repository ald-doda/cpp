#include <iostream>
#include <cmath>
using namespace std;
//1. Zadatak:
double FtoC(double F){
    return (5*(F-32))/9;
}
//2. Zadatak
double MbitS(double gb){
    double bajtovi = gb * pow(1024, 3);
    double bitovi = bajtovi*8;
    double vrijeme = bitovi/100000000;
    return vrijeme;

}
//3. Zadatak
void piramizaUzWhile(int n){
    int i = 1;
    while(i <= n){
        int j = 0;
        while(j < i){
            cout << "*";
            j++;
        }
        cout << endl;

        i++;
    }
    while(i-1 > 1){
        int j = i-1;
        while(j > 1){
            cout << "*";
            j--;
        }
        cout <<endl;
        i--;
    }

}
//4. zadatak
int razliciteCifre(int n){
    int br = 0;
    int brojevi[10] = {0}; //inicijalizujem sve na 0;
    if(n == 0) return 1;
    if(n < 10) return 1;

    while(n != 0){
        int cif = n%10;
        brojevi[cif]++;
        n /= 10;
    }

    for(int i = 0; i < 10; i++){
        if(brojevi[i] !=0) br++;
    }

    return br;
}
#include <algorithm>
int najvisePojavljivanja(int n){
    int najveca = 0;
    int cifra = 0;
    int brojevi[10] = {0};
    while(n != 0){
        int cif = n %10;
        brojevi[cif]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++){
        if(najveca < brojevi[i]){
            najveca = brojevi[i];
            cifra = i;
        }
    }

    return cifra;
}


int najvisePojavljivanja2(int n){
    int brojevi[10] = {0};
    if(n < 10) return n;
    while(n != 0){
        int cif = n%10;
        brojevi[cif]++;
        n /= 10;
    }

    return max_element(brojevi, brojevi+10) - brojevi;
}
//6. zadatak
bool savrsenBroj(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0) sum +=i;
    }
    if(sum == n) return true;
    else return false; 
}
bool dvojak(int n){
    if(razliciteCifre(n) <= 2) return true;
    else return false;
}

int najbliziDvojak(int n){
    if(dvojak(n)) return n;
    else{
        int dolje = n - 1;
        int gore = n + 1;

        while((dolje < 1 || !dvojak(dolje)) && !dvojak(gore)){
            dolje--;
            gore++;
        }

        if(dolje >= 1 && dvojak(dolje))
            return dolje;
        else
            return gore;
    }
}

void pitagoriniBrojevi(){
    for(int c = 10; c < 100; c++){
        bool pronadjen = false;
        for(int a = 1; a < c; a++){
            for(int b = 1; b < c; b++){
                if(b*b + a*a == c*c){
                    pronadjen = true;
                }
            }
        }
        if(pronadjen)
                    cout << c << endl;
    }

}
void amstrongoviBrojevi(){
    for(int c = 100; c < 1000; c++){
     int sum = pow(c%10, 3) + pow((c/10)%10, 3) + pow((c/100)%10, 3);
        if(sum == c){
            cout << c << endl;
        }
    }
}
void prostiFaktori(int n){
    for(int i = 2; i <= n; i++){
        int brDjelioca = 0;
        for(int j = 1; j < i-1; j++){
            if(i % j == 0) brDjelioca++;
        }
        if(brDjelioca != 1){
            continue;
        } else{
            if(n % i == 0){
                cout << i << endl;
            }
        }

    }
}
int zbirCifara(int n){
    int sum = 0;
    while(n != 0){
        int cif = n % 10;
        sum += cif;
        n /= 10;
    }
    return sum;
}
int otpornostBroja(int n){
    if(n < 10) return 0;
    int sum = zbirCifara(n);
    int koraci = 1;
    while(sum >= 10){
        sum = zbirCifara(sum);
        koraci++;
    }

    return koraci;
}
//12. Zadatak
void mnMax(){
    int maxSum = -1;
    int i, j;
    for(int n = 1; n <= 100; n++){
        for(int m = 1; m <= 100; m++){
            int sum = abs(pow(n, 2) + m*n + pow(m, 2));
            if(sum == 100 && (pow(n,2) + pow(m,2) > maxSum)){
                maxSum = n*n + m*m;
                i = n;
                j = m;
            }

        }
    }
    if(maxSum == -1){
        cout << "Nema realnog rjesenja." << endl;
    } else {
        cout << "M i n su: " << j << " i " << i << " ,a suma je " << maxSum << endl;
    }
}
//13. zad
double sumaReda(int n){
    double s = 0.0;

    for(int i = 1; i <=n; i++){
        s += pow(-1, i)/i;
    }

    return s;

}
//14, zad
double sumaReda2(double e){
    double s = 0;
    double i = 1;
    double sabirak = 1.0;
    while(sabirak >= e){
        s += sabirak;
        i++;
        sabirak = (2.0 * i - 1) / (i * i);
        cout << s << endl;
    }
    return s;

}
//15. zad
int faktorijel(int n){
    int fakt = 1;
    if(n <= 1) return 1;
    for(int i = 1; i <= n; i++){
        fakt *= i;
    }
    return fakt;
}
double sumaReda3(double x, int n){
    double s = 0.0;
    for(int i = 1; i <= n; i++){
        s += pow(-1, i-1)*pow(sin(x-2), 2)/faktorijel(i);
    }
    return s;
}
//16. zad
double sumReda4(double x, int n){
    double suma = 0.0;
    for(int i = 1; i <= n; i++){
        suma += pow(-1, i)*pow(x+1, 2*i+1)/faktorijel(i);
        }

    return suma;
}
void kvadrat(int a, int b){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(i == 0 || i == a-1 || j == 0 || j == b-1){
                cout << "*";
            } else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
//18. zadatak
bool trougao(float x1, float y1, float x2, float y2, float x3, float y3){
    float a = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    float b = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    float c = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    if((a+b > c) && (a+c > b) && (b+c > a)){
    return true;
} else {
    return false;
}
}
float povrsinaTrougla(float x1, float y1, float x2, float y2, float x3, float y3){
    float a = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    float b = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    float c = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    float obim = a+b+c;
    float s = obim/2;

    float p = sqrt(s*(s-a)*(s-b)*(s-c));
    return p;
  
}
void stampaj_trougao(float x1, float y1, float x2, float y2, float x3, float y3){
    float dA = sqrt(pow(0-x1, 2) + pow(0-y1, 2));
    float dB = sqrt(pow(0-x2, 2) + pow(0-y2, 2));
    float dC = sqrt(pow(0-x3, 2) + pow(0-y3, 2));
    
    float najmanji = min(min(dA, dB), dC);

    if(najmanji == dA){
    cout << "A(" << x1 << "," << y1 << ")" << endl;
    cout << "B(" << x2 << "," << y2 << ")" << endl;
    cout << "C(" << x3 << "," << y3 << ")" << endl;

    }    else if(najmanji == dB){
    cout << "B(" << x2 << "," << y2 << ")" << endl;
    cout << "A(" << x1 << "," << y1 << ")" << endl;
    cout << "C(" << x3 << "," << y3 << ")" << endl;
    }    else{
    cout << "C(" << x3 << "," << y3 << ")" << endl;
    cout << "B(" << x2 << "," << y2 << ")" << endl;
    cout << "A(" << x1 << "," << y1 << ")" << endl;
}
}

int okreniIterativno(int n){
    int br = 0;
    while(n != 0){
        int cif = n %10;
        br = br * 10 + cif;
        n /= 10;
    }
    return br;
}
int brCifRekurzija(int n){
    if(n < 10) return 1;
    else return 1 + brCifRekurzija(n/10);
}
int okreniRekurzvino(int n){
    if(n == 0) return 0;
    if(n < 10) return n;
    else return (n%10)*pow(10, brCifRekurzija(n)-1) + okreniRekurzvino(n/10);

}
int iterativanBezParnih(int n){
    int br = 0;
    while(n != 0){
        int cif = n %10;
        if(cif % 2 != 0){
            br = br*10+cif;
        }
        n /= 10;
    }
    br = okreniIterativno(br);
    return br;
}
int rekurzivnoBezParnih(int n){
    if(n == 0) return 0;
    if(n < 10 && n % 2 != 0) return n;
    else if((n%10) % 2 != 0) return (n%10) + rekurzivnoBezParnih(n/10)*10;
    else return rekurzivnoBezParnih(n / 10);
}
float brojRiba(int x, int p, float s){
    float sNovo = s;
    int godine = 0;
    while(sNovo >= x){

        sNovo = sNovo - sNovo*(p/100.0);
        godine++;
    }
    return godine;
}
int brojRibaRek(int x, int p, float s){
    if(s < x) return 0;
    float sNew = s-s*(p/100.0);
    return 1 + brojRibaRek(x, p,sNew);
}
bool djeljivostSaSvimCiframa(int n){
    int broj = n;
    while(n != 0){
        int cif = n %10;
        if(cif == 0) return false;
        if(broj % cif != 0) return false;
        n /= 10;
    }
    return true;

}
bool prostiFaktori235(int n){
    if(n <= 0) return false;
    while(n % 2 == 0){
        n /= 2;
    }
    while(n % 3 == 0){
        n /= 3;
    }
    while(n % 5 == 0){
        n /= 5;
    }
    if(n == 1) return true;
    else return false;
}
int main(){
    cout << iterativanBezParnih(12345) << endl;
    cout << brCifRekurzija(322) << endl;
     cout << okreniRekurzvino(322) << endl;
    cout << okreniIterativno(322) << endl;
    kvadrat(7, 3);
    int a = 1;
    int b = 2;
    int c = 3;
    cout << faktorijel(4) << " " << faktorijel(5) << " " <<faktorijel(c) << endl;
    amstrongoviBrojevi();
    double F;
    cin >> F;
    cout << savrsenBroj(F) << endl;
    cout << razliciteCifre(F) << endl;
    cout << FtoC(F) << endl;
    piramizaUzWhile(4);

    return 0;
}