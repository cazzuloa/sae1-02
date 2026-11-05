#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Struct pour le Tournois 
struct Joueur
{
    string nom;
    string prenom;
    int score;
};

struct Match
{
    int Joueur1;
};

//Mini jeux
Joueur pileOuFace (const Joueur &j1, const Joueur &j2) {
    int choix;
    // 50% de chance de gagner
    choix = rand()%2;
    if (choix ==0) return j1;
    return j2;
}

Joueur pileOuFaceTruque (const Joueur &j1, const Joueur &j2) {
    int choix;
    // 75% de chance que j1 gagne, 25% pour j2
    choix = rand()%100;
    if (choix < 75) return j1;
    return j2;
}

Joueur pierreFeuilleCiseau (const Joueur &j1, const Joueur &j2) {
    cout << "Mini jeux : Pierre Feuille Ciseau" << endl;
    string entreeJ1, entreeJ2;
    cout << "Joueur 1, quel coup : " << endl;
    cin >> entreeJ1;
    cout << "Joueur 2, quel coup : " << endl;
    cin >> entreeJ2;
    if (entreeJ1 == "Pierre" || "pierre" && entreeJ2 == "Ciseau" || "ciseau") return j1;
    if (entreeJ1 == "Feuille" || "feuille" && entreeJ2 == "Pierre" || "pierre") return j1;
    if (entreeJ1 == "Ciseau" || "ciseau" && entreeJ2 == "Feuille" || "feuille") return j1;

    return j2;
}

int main() {
    srand(time(NULL));
    
    return 0;
}
