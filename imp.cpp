#include "appel.h"

Appel::Appel() : nomPersonne(""), numAppel(""), duree(0), cost(0) {}

Appel::Appel(string nom, string num, int d, float c)
    : nomPersonne(nom), numAppel(num), duree(d), cost(c) {}

string Appel::getNomPersonne() {
    return nomPersonne;
}

void Appel::saisie() {
    cout << "Donner le nom de personne : ";
    cin >> nomPersonne;
    cout << "Donner le numero d'appel : ";
    cin >> numAppel;
    while (numAppel.length() < 8) {
        cout << "Erreur : le numero doit avoir au moins 8 chiffres. Reessayez : ";
        cin >> numAppel;
    }
    cout << "Donner la duree (minutes) : ";
    cin >> duree;
    while (duree < 0) {
        cout << "Erreur : la duree doit etre positive. Reessayez : ";
        cin >> duree;
    }
    cout << "Donner le cout : ";
    cin >> cost;
    while (cost < 0) {
        cout << "Erreur : le cout doit etre positif. Reessayez : ";
        cin >> cost;
    }
}

void Appel::affiche() {
    cout << "Nom : " << nomPersonne << endl;
    cout << "Numero : " << numAppel << endl;
    cout << "Duree : " << duree << " min" << endl;
    cout << "Cout : " << cost << " euros" << endl;
}

AppelSurtaxe::AppelSurtaxe(double t, string nom, string num, int d, float c)
    : Appel(nom, num, d, c), taxe(t) {}

void AppelSurtaxe::saisie() {
    Appel::saisie();
    cout << "Donner le taux de taxe (%) : ";
    cin >> taxe;
    while (taxe < 0) {
        cout << "Erreur : le taux ne peut pas etre negatif. Reessayez : ";
        cin >> taxe;
    }
    while (taxe > 100) {
        cout << "Erreur : le taux ne peut pas depasser 100%. Reessayez : ";
        cin >> taxe;
    }
}

void AppelSurtaxe::affiche() {
    Appel::affiche();
    cout << "Taxe : " << taxe << "%" << endl;
    cout << "Cout total (avec taxe) : " << cost * (1 + taxe / 100) << " euros" << endl;
}

ListeAppels::ListeAppels(int n) : nb(n) {
    for (int i = 0; i < 3; i++) {
        T[i] = nullptr;
    }
}

ListeAppels::~ListeAppels() {
    for (int i = 0; i < nb; i++) {
        delete T[i];
    }
}

void ListeAppels::saisie() {
    int choix, i = 0;
    do {
        if (i >= 20) {
            cout << "Erreur : limite de 20 appels atteinte." << endl;
            break;
        }
        cout << "1. Appel normal" << endl;
        cout << "2. Appel surtaxe" << endl;
        cout << "3. Quitter" << endl;
        cout << "Donner votre choix : ";
        cin >> choix;
        switch (choix) {
            case 1:
                T[i] = new Appel();
                T[i]->saisie();
                nb++;
                i++;
                break;
            case 2:
                T[i] = new AppelSurtaxe();
                T[i]->saisie();
                nb++;
                i++;
                break;
            case 3:
                break;
            default:
                cout << "Choix invalide. Reessayez." << endl;
        }
    } while (choix != 3);
}

void ListeAppels::affiche_listeappel() {
    if (nb == 0) {
        cout << "Aucun appel dans la liste." << endl;
        return;
    }
    for (int i = 0; i < nb; i++) {
        cout << "Appel N" << i + 1 << ":" << endl;
        T[i]->affiche();
        cout << endl;
    }
}

void ListeAppels::nbreappel(string ch) {
    int nombre = 0;
    for (int i = 0; i < nb; i++) {
        if (T[i]->getNomPersonne() == ch) {
            nombre++;
        }
    }
    cout << "Le nombre d'appels effectues par " << ch << " est : " << nombre << endl;
}
