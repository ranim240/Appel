#include <iostream>
#include <string>
using namespace std;

class Appel {
protected:
    string nomPersonne;
    string numAppel;
    int duree;
    float cost;

public:
    Appel();
    Appel(string nom, string num, int d, float c);
    string getNomPersonne();

    virtual void saisie();
    virtual void affiche();
    virtual ~Appel() {}
};

class AppelSurtaxe : public Appel {
private:
    double taxe;

public:
    AppelSurtaxe(double t = 0, string nom = "", string num = "", int d = 0, float c = 0);
    void affiche();
    void saisie();
};

class ListeAppels {
private:
    Appel *T[20];
    int nb;

public:
    ListeAppels(int n = 0);
    ~ListeAppels();
    void saisie();
    void affiche_listeappel();
    void nbreappel(string ch);
};
