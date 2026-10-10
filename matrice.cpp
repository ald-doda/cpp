#include <iostream>
#include <cmath>
using namespace std;

void ucitajMatricu(int m, int n, int** mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
}
void stampajMatricu(int m, int n, int** mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
            cout << endl;
    }
            cout << endl;
}
//47. Suma elemenata sa indeksom parne vrste i neparne kolone
int suma_matrice(int **mat, int m, int n){
    int sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 == 0 && j % 2 != 0){
                sum += mat[i][j];
            }
        }
    }


    return sum;
}
//48. Mijenjamo r-tu i s-tu kolonu matrice
void zamijeni_kolone(int** mat, int m, int n, int r, int s){
    for(int i = 0; i < m; i++){
        int temp = mat[i][r];
        mat[i][r] = mat[i][s];
        mat[i][s] = temp;
    }
}
//49. Provjera je li matrica simetricna
bool simetricna(int** mat, int m, int n){
    if(m != n){
        return false; //Matrica nije kvadratna 
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] != mat[j][i]){
                return false;
            }
        }
    }
    return true;
}
//50. Lokalni maksimum u matrici
void lokalni_maksimumi(int** mat, int m, int n){
    bool zastavica = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i > 0 && mat[i][j] < mat[i-1][j]) zastavica = false;
            if(i < m-1 && mat[i][j] < mat[i+1][j]) zastavica = false;
            if(j > 0 && mat[i][j] < mat[i][j-1]) zastavica = false;
            if(j < n-1 && mat[i][j] < mat[i][j+1]) zastavica = false;
            if(i > 0 && j > 0 && mat[i][j] < mat[i-1][j-1]) zastavica = false;
            if(i < m-1 && j < n-1 && mat[i][j] < mat[i+1][j+1]) zastavica = false;
            if(i > 0 && j < n-1 && mat[i][j] < mat[i-1][j+1]) zastavica = false;
            if(i < m-1 && j > 0 && mat[i][j] < mat[i+1][j-1]) zastavica = false;
            if(zastavica){
                cout << "Lokalni maksimum: " << mat[i][j] << " na poziciji: (" << i << ", " << j << ")" << endl;
            }
            zastavica = true;
        }
    }
}
// 51. Suma elemenata podmatrice
int sumPodmatrice(int** mat, int m, int n,
                 int gore, int dolje, int lijevo, int desno) {
    int sum = 0;

    for (int i = gore; i <= dolje; i++) {
        for (int j = lijevo; j <= desno; j++) {
            sum += mat[i][j];
        }
    }

    return sum;
}

// Pronalazi i stampa podmatricu sa najvecom sumom.
// Pretpostavka: m > 0 i n > 0.
void najvecaPodmatrica(int** mat, int m, int n) {
    int maxSum = mat[0][0];
    int gore = 0, dolje = 0, lijevo = 0, desno = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < m; k++) {
                for (int l = j; l < n; l++) {
                    int sum = sumPodmatrice(mat, m, n, i, k, j, l);

                    if (sum > maxSum) {
                        maxSum = sum;
                        gore = i;
                        dolje = k;
                        lijevo = j;
                        desno = l;
                    }
                }
            }
        }
    }

    for (int i = gore; i <= dolje; i++) {
        for (int j = lijevo; j <= desno; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
//Najveca kvadratna podmatrica sa sumom <= S
#include <algorithm> //treba nam za min
int sumaKvadrata(int** mat, int i, int j, int k){
    int sum = 0;
    for(int vrsta = i; vrsta < i+k; vrsta++){
        for(int kolona = j; kolona < j+k; kolona++){
            sum += mat[vrsta][kolona];
        }
    }
    return sum;
}
void najvecaKvadratna(int** mat, int m, int n, int S){
    
    int maxK = min(m, n);
    for(int k = maxK; k >= 1; k--){
        for(int i = 0; i <= m-k; i++){
            for(int j = 0; j <= n-k; j++){
                if(sumaKvadrata(mat, i, j, k) <= S){
                    cout << "Najveca kvadratna podmatrica sa sumom <= " << S << " je: " << endl;
                    for(int vrsta = i; vrsta < i+k; vrsta++){
                        for(int kolona = j; kolona < j+k; kolona++){
                            cout << mat[vrsta][kolona] << " ";
                        }
                        cout << endl;
                    }
                    return;
                }
            }
        }
    }
    cout << "Nema kvadratne podmatrice sa sumom <= " << S << endl;
}
//53. Najveci kvadrat sastavljen od jedinica
int najveciKvadratJedinica(int** mat, int m, int n){
    int maxK = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 1){
                int k = 1;
                while(i+k < m && j+k < n){
                    bool valid = true;
                    for(int vrsta = i; vrsta <= i+k; vrsta++){
                        if(mat[vrsta][j+k] != 1){
                            valid = false;
                            break;
                        }
                    }
                    for(int kolona = j; kolona <= j+k; kolona++){
                        if(mat[i+k][kolona] != 1){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        k++;
                    } else {
                        break;
                    }
                }
                if(k > maxK){
                    maxK = k;
                }
            }
        }
    }
    return maxK;
}
int main(){
    int m, n;
    cin >> m >> n;
    int** mat = new int*[m];
    for(int i = 0; i < m; i++){
        mat[i] = new int[n];
    }
    ucitajMatricu(m, n, mat);
    stampajMatricu(m, n, mat);

    for(int i = 0; i < m; i++){
        delete[] mat[i];
    }
    delete[] mat;


    return 0;
}