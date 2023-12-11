#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hasard(int min, int max) {
    return (int)(min + ((float)rand() / RAND_MAX * (max - min + 1)));
}

void devinerNombre(int nombreADeviner) {
    int proposition;

    printf("Entrez votre proposition : ");
    scanf("%d", &proposition);

    if (proposition == nombreADeviner) {
        printf("Félicitations ! Vous avez deviné le nombre %d !\n", nombreADeviner);
    } else if (proposition < nombreADeviner) {
        printf("Plus grand. Essayez encore.\n");
        devinerNombre(nombreADeviner);
    } else {
        printf("Plus petit. Essayez encore.\n");
        devinerNombre(nombreADeviner);
    }
}

// int main() {
//     srand(time(NULL));

//     int nombreADeviner = hasard(1, 100);

//     printf("Bienvenue dans le jeu de devinette !\n");
//     printf("Devinez le nombre entre 1 et 100.\n");

//     devinerNombre(nombreADeviner);

//     return 0;
// }

#include <stdio.h>

// Fonction pour afficher R barres verticales
void afficherBarresVerticales(int R) {
    for (int i = 0; i < R; ++i) {
        printf("| ");
    }
    printf("\n");
}

// Fonction pour jouer au jeu des allumettes
void jouerAuJeuDesAllumettes() {
    int allumettes = 15;  // Nombre initial d'allumettes
    int joueurActuel = 1; // 1 pour le joueur 1, 2 pour le joueur 2
    int choix;

    printf("Bienvenue au jeu des allumettes !\n");

    while (allumettes > 0) {
        printf("\nJoueur %d, c'est votre tour.\n", joueurActuel);
        printf("Il reste %d allumettes. Combien d'allumettes voulez-vous retirer (entre 1 et 3) ? ", allumettes);

        do {
            scanf("%d", &choix);
            if (choix < 1 || choix > 3 || choix > allumettes) {
                printf("Veuillez entrer un nombre valide d'allumettes (entre 1 et 3 et pas plus que le nombre restant).\n");
            }
        } while (choix < 1 || choix > 3 || choix > allumettes);

        allumettes -= choix;

        // Afficher les barres verticales représentant les allumettes restantes
        afficherBarresVerticales(allumettes);

        joueurActuel = (joueurActuel == 1) ? 2 : 1; // Changer de joueur
    }

    printf("\nJoueur %d a retiré la dernière allumette. Joueur %d a gagné !\n", joueurActuel, (joueurActuel == 1) ? 2 : 1);
}

// int main() {
//     jouerAuJeuDesAllumettes();

//     return 0;
// }

#include <stdio.h>
#include <math.h>

double calculer_e_approximation(double epsilon) {
    double e_approximation = 1.0;  // La première approximation est 1.0
    double terme_suivant = 1.0;    // Initialiser le terme suivant à 1.0
    int k = 1;

    while (fabs(terme_suivant) >= epsilon / 3.0) {
        terme_suivant /= k;        // Calculer le prochain terme
        e_approximation += terme_suivant;  // Ajouter le terme à l'approximation de e
        k++;
    }

    return e_approximation;
}

// int main() {
//     double epsilon;
//     printf("Entrez la precision (epsilon) souhaitee : ");
//     scanf("%lf", &epsilon);

//     double e_approximation = calculer_e_approximation(epsilon);

//     printf("L'approximation de e avec une precision de %.15f est : %.15f\n", epsilon, e_approximation);

//     return 0;
// }

// Hanoi

void toursHanoi(int n, char D, char A, char I) {
    if (n == 1)
      printf("Disque 1 de %c a %c \n" , D , A);
    else {
      toursHanoi(n - 1, D, I, A);
      printf("Disque %d de %c a %c \n", n , D ,A);
      toursHanoi(n - 1, I, A, D);
    }
}

int main() {
    int nDisques = 3;
    toursHanoi(nDisques, 'A', 'B', 'C');
    system("pause");
}

