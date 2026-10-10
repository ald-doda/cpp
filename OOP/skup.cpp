#include <iostream>
#include "skup.h"


bool Skup::sadrzi(int x) const{
    for(int i = 0; i < brojElemenata; i++){
        if(data[i] == x){
            return true;
        }
    }
    return false;
}

void Skup::realociraj(int noviKapacitet){
    int* novaData = new int[noviKapacitet];
    for(int i = 0; i < brojElemenata; i++){
        novaData[i] = data[i];
    }
    delete[] data;
    data = novaData;
    kapacitet = noviKapacitet;
}

void Skup::dodajElement(int x){
    if(sadrzi(x)){
        return;
    }
    if(brojElemenata == kapacitet){
        realociraj(kapacitet == 0 ? 1 : kapacitet * 2);
    }
    data[brojElemenata++] = x;
}

Skup::Skup(){
    data = new int[10];
    kapacitet = 10;
    brojElemenata = 0;
    

}
Skup::Skup(const Skup &drugi){
    kapacitet = drugi.kapacitet;
    brojElemenata = drugi.brojElemenata;
    data = new int [kapacitet];
    for(int i = 0; i < brojElemenata; i++){
        data[i] = drugi.data[i];
    }

}
Skup::Skup(int element){
    kapacitet = 1;
    brojElemenata = 1;
    data = new int[kapacitet];
    data[0] = element;

}
Skup::~Skup(){
    delete[] data;
}

Skup& Skup::dodaj(const Skup &drugi) {
    for (int i = 0; i < drugi.brojElemenata; i++) {
        dodajElement(drugi.data[i]);
    }
    return *this;
}

Skup Skup::unija(const Skup &drugi) const {
    Skup rezultat(*this);
    rezultat.dodaj(drugi);
    return rezultat;
}

Skup Skup::presjek(const Skup &drugi) const {
    Skup rezultat;
    for (int i = 0; i < brojElemenata; i++) {
        if (drugi.sadrzi(data[i])) {
            rezultat.dodajElement(data[i]);
        }
    }
    return rezultat;
}

Skup Skup::razlika(const Skup &drugi) const {
    Skup rezultat;
    for (int i = 0; i < brojElemenata; i++) {
        if (!drugi.sadrzi(data[i])) {
            rezultat.dodajElement(data[i]);
        }
    }
    return rezultat;
}

Skup& Skup::ukloni(const Skup &drugi) {
    int noviBroj = 0;
    for (int i = 0; i < brojElemenata; i++) {
        if (!drugi.sadrzi(data[i])) {
            data[noviBroj++] = data[i];
        }
    }
    brojElemenata = noviBroj;
    return *this;
}

void Skup::ispisi() const {
    for (int i = 0; i < brojElemenata; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Skup::size() const{
    return brojElemenata;
}
