#include "appel.h"

int main() {

    cout << "TEST APPEL" << endl;
    Appel A;
    A.saisie();
    cout << "AFFICHAGE APPEL" << endl;
    A.affiche();
    cout << endl;


    cout << "TEST APPEL SURTAXE" << endl;
    AppelSurtaxe AST;
    AST.saisie();
    cout << "AFFICHAGE APPEL SURTAXE" << endl;
    AST.affiche();
    cout << endl;


    cout << "TEST LISTE DES APPELS" << endl;
    ListeAppels LA;
    LA.saisie();
    cout << "AFFICHAGE LISTE DES APPELS" << endl;
    LA.affiche_listeappel();
    cout << endl;


    string name;
    cout << "Entrez un nom pour compter les appels : ";
    cin >> name;
    LA.nbreappel(name);

    return 0;
}
