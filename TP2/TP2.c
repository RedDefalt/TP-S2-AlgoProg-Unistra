#include <stdio.h>

// Fonction pour déterminer si une année est bissextile
int estBissextile(int annee) {
    // Si l'année n'est pas divisible par 4, elle n'est pas bissextile
    if (annee % 4 != 0) {
        return 0;
    }
    // Si l'année est divisible par 100 mais pas par 400, elle n'est pas bissextile
    else if (annee % 100 == 0 && annee % 400 != 0) {
        return 0;
    }
    // Sinon, l'année est bissextile
    else {
        return 1;
    }
}

// Fonction pour vérifier si une date est valide
int estDateValide(int jour, int mois, int annee) {
    if (mois < 1 || mois > 12) {
        return 0; // Mois invalide
    }

    int joursDansMois;
    if (mois == 2) {
        joursDansMois = 28; // On ignore les années bissextiles
    } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        joursDansMois = 30;
    } else {
        joursDansMois = 31;
    }

    if (jour < 1 || jour > joursDansMois) {
        return 0; // Jour invalide
    }

    return 1; // Date valide
}

// Fonction pour afficher la date du lendemain
void lendemain(int jour, int mois, int annee) {
    if (!estDateValide(jour, mois, annee)) {
        printf("Date invalide.\n");
        return;
    }

    // Traitement pour le lendemain
    jour++;
    if (jour > 28 && mois == 2) {
        jour = 1;
        mois++;
    } else if (jour > 30 && (mois == 4 || mois == 6 || mois == 9 || mois == 11)) {
        jour = 1;
        mois++;
    } else if (jour > 31) {
        jour = 1;
        mois++;
        if (mois > 12) {
            mois = 1;
            annee++;
        }
    }

    // Affichage de la date du lendemain
    printf("La date du lendemain est : %d/%d/%d\n", jour, mois, annee);
}
// Calculatrice

#include <stdio.h>

// Fonction pour effectuer une opération
float effectuerOperation(float operand1, char operateur, float operand2) {
    float resultat;

    switch (operateur) {
        case '+':
            resultat = operand1 + operand2;
            break;
        case '-':
            resultat = operand1 - operand2;
            break;
        case '*':
            resultat = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                resultat = operand1 / operand2;
            } else {
                printf("Erreur : Division par zero.\n");
                return 0;
            }
            break;
        default:
            printf("Erreur : Operateur invalide.\n");
            return 0;
    }

    return resultat;
}

int main() {
    float operand1, operand2, resultat;
    char operateur;

    // Demander à l'utilisateur de saisir l'opération
    printf("Veuillez entrer un operande, un operateur (+, -, *, /), puis un autre operande : ");
    scanf("%f %c %f", &operand1, &operateur, &operand2);

    // Appeler la fonction effectuerOperation et afficher le résultat
    resultat = effectuerOperation(operand1, operateur, operand2);
    printf("Le resultat de l'operation est : %.2f\n", resultat);

    return 0; // Indiquer une exécution réussie
}
