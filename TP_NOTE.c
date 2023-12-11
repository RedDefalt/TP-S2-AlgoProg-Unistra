#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Retourne un nombre pseudo aleatoire entre 0 et 1
int hasard()
{
    return rand() % 2;
}

// Libère la grille du jeux
void liberer_grille (int **grille, int taille){
    for (int i=0; i<taille; i++){
        free (grille[i]);
        }
    free (grille);
}

// Initialie la grille avec des valeurs aléatoires pour les celules
void init_grille(int **grille, int taille) {
    for (int n = 0; n < taille; n++) {
        for (int m = 0; m < taille; m++) {
            grille[n][m] = hasard();
        }
    }
}

// Affiche la grille en fonction de si la celule est active ou pas
void affiche_grille(int **grille, int taille) {
    for (int n = 0; n < taille; n++) {
        for (int m = 0; m < taille; m++) {
            if (grille[n][m] == 1) {
              printf("O ");
            } else {
              printf("  ");
            }
        }
        printf("\n");
    }
}

// Fonctione qui alloue dynamiquement de l'espace pour grille
int **allocate_grille (int taille){
    int ** gril = malloc(taille * sizeof(int*));
    if (gril==NULL) exit (-1);
    for(int i = 0; i < taille; i++) {
        gril[i] = malloc(taille * sizeof(int));
        if (gril[i]==NULL) exit (-2);
    }
    return gril;
}

// Calcule la densite du plateau de jeux
void densite(int **grille, int **densite, int taille) {
  int **density = allocate_grille(taille);
  for (int n = 1; n < taille-1; n++) {
      for (int m = 1; m < taille-1; m++) {
          int somme = 0;
          for (int x = n-1; x <= n+1; x++) {
            for (int y = m-1; y <= m+1; y++) {
              if (((x != n) || (y != m)) && (grille[x][y] == 1)) {
                somme += 1;
              }
            }
          }
          density[n][m] = somme;
      }
  }
  for (int n = 0; n < taille; n++) {
    for (int m = 0; m < taille; m++) {
      densite[n][m] = density[n][m];
    }
  }
}

// Fait evoluer les celules en fonction des conditions
void evolution(int **grille, int **dense, int taille) {
  for (int n = 1; n < taille-1; n++) {
      for (int m = 1; m < taille-1; m++) {
        if (dense[n][m] >= 2 && dense[n][m] <= 3 && grille[n][m] == 1) {
          grille[n][m] = 1;
        } else if (dense[n][m] >= 4 && dense[n][m] <= 8 && grille[n][m] == 1) {
          grille[n][m] = 0;
        } else if (dense[n][m] >= 0 && dense[n][m] <= 1 && grille[n][m] == 1) {
          grille[n][m] = 0;
        } else if (dense[n][m] == 3 && grille[n][m] == 0) {
          grille[n][m] = 1;
        }
      }
  }
}

int main ()
{
    // DO NOT TOUCH : init seed for random number generation with rand()
    srand(time(NULL));

    // Variables interface homme machine
    int taille = 0;
    int iteration = 0;
    printf("Entrer la taille de la grille ! : ");
    scanf("%d",&taille);
    printf("Entrer le nombre de evolution shoueter ! : ");
    scanf("%d",&iteration);

    // Variables fonctionnelles
    int **grille = allocate_grille(taille); // plateau de jeux
    int **dense = allocate_grille(taille); // tableau des densité

    // Fonctionnelle du programme
    init_grille(grille,taille); // Initialie la grille avec des valeurs aléatoires pour les celules
    for (int i = 1; i <= iteration; i++) {
      printf("\033[H\033[J"); // Actualise l'affichage
      printf("Nieme generation : %d\n",i ); // Compteur
      densite(grille,dense,taille); // Calcule la dansite en fonction du temps
      evolution(grille,dense,taille); // Fait evolution de T + 1
      affiche_grille(grille,taille); // afiche la grille a l'instant T
      usleep(200000); // Fait des micro pauses
    }
    liberer_grille(grille, taille); // Libère les tableaux dynamique
    return 0;
}
