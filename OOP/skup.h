#ifndef SKUP_H
#define SKUP_H
class Skup{
    private:
    int* data;
    int kapacitet;
    int brojElemenata;


    bool sadrzi(int x) const;
    void realociraj(int noviKapacitet);
    void dodajElement(int x);

    public:
    Skup();
    Skup(const Skup &drugi);
    Skup(int element);
    ~Skup();
    Skup unija(const Skup &drugi) const;
    Skup& dodaj(const Skup &drugi);
    Skup razlika(const Skup &drugi) const;
    Skup& ukloni(const Skup &drugi); 
    Skup presjek(const Skup &drugi) const;
    void ispisi() const;
    int size() const;



};
#endif