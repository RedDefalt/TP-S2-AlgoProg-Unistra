#include <stdio.h>
#include <math.h>

// Exercice 2 TP1
//  lit au clavier un flottant représentant la longueur du côté d’un carré, affiche le périmètre et la diagonale de ce carré.

// Fonction pour calculer le périmètre et la diagonale du carré
float calculerPerimetre(float longueurCote) {
    return 4 * longueurCote;
}

float DiagonaleCarre(float longueurCote) {
    return sqrt(2) * longueurCote;
}

int test_exercice2() {
    float longueurCote;

    // Demander à l'utilisateur de saisir la longueur du côté du carré
    printf("Veuillez entrer la longueur du cote du carre : ");
    scanf("%f", &longueurCote);

    // Vérifier si la longueur du côté est positive
    if (longueurCote <= 0) {
        printf("La longueur du cote doit etre un nombre positif.\n");
        return 1; // Indiquer une erreur
    }

    // Afficher le résultat
    printf("Le perimetre du carre est : %.2f\n", calculerPerimetre(longueurCote));
    printf("La diagonale du carre est : %.2f\n", DiagonaleCarre(longueurCote));
    return 0;
}

// Exercice 3 TP1

int nbr_jours(int numero_mois){
    if ((numero_mois == 1) || (numero_mois == 3) || (numero_mois == 5) || (numero_mois == 7) || (numero_mois == 8) || (numero_mois == 10) || (numero_mois == 12)) {
        return 31;
    } else if (numero_mois == 2) {
        return 28;
    } else {
        return 30;
    }
}

int test_exercice3(){
    int mois;

    // Demander à l'utilisateur de saisir un entier entre 1 et 12
    printf("Veuillez entrer un entier entre 1 et 12 représentant un mois de l'année : ");
    scanf("%d", &mois);

    // Vérifier si le mois est valide
    if (mois < 1 || mois > 12) {
        printf("Mois invalide. Veuillez entrer un entier entre 1 et 12.\n");
        return 1; // Indiquer une erreur
    }

    // Afficher le résultat
    printf("Le mois %d a %d jours.\n",mois, nbr_jours(mois));
    return 0;
}

int main() {
    test_exercice2();
    test_exercice3();
    return 0;
}
