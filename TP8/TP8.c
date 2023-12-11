#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int hasard(int min, int max){
    return (int) (min + ((float) rand() / RAND_MAX * (max - min + 1)));
}

void liberer_sapin (char **sapin, int hauteur_sapin){
    for (int i=0; i<hauteur_sapin; i++){
        free (sapin[i]);
        }
    free (sapin);
}

int **affiche_sapin(char **sapin, int hauteur_sapin) {
    int largeur_sapin = hauteur_sapin * 2 - 1;
    for (int n = 0; n < hauteur_sapin; n++) {
        for (int m = 0; m < largeur_sapin; m++) {
            printf("%c", sapin[n][m]);
        }
        printf("\n");
    }
    return 0;   
}

int **init_sapin(char **sapin, int hauteur_sapin) {
    int largeur_sapin = hauteur_sapin * 2 - 1;
    for (int n = 0; n < hauteur_sapin; n++) {
        for (int m = 0; m < largeur_sapin; m++) {
            sapin[n][m] = ' ';
        }
    }
    return 0;
}

char **allouer_sapin(int hauteur_sapin){
    int largeur_sapin = hauteur_sapin * 2 - 1;
    char ** tab = malloc(hauteur_sapin * sizeof(char*));
    if (tab==NULL) exit (-1);
    for(int i = 0; i < hauteur_sapin; i++) {
        tab[i] = malloc(largeur_sapin * sizeof(char));
        if (tab[i]==NULL) exit (-2);
    }
    return tab;
}

int **dessin_sapin(char **sapin, int hauteur_sapin) {
    int alea;
    int min = 0;
    int max = 10;
    int largeur_sapin = hauteur_sapin * 2 - 1;
    int milieu = largeur_sapin/2;
    for (int n = 0; n < hauteur_sapin; n++) {
        for (int m = milieu; m < milieu + 2*n+1; m++) {
            alea = hasard(min, max);
            if (alea < 9) {
                sapin[n][m] = '*';
            } else {
                sapin[n][m] = 'o';
            }
        }
        milieu = milieu - 1;
    }
    return 0;
}


int main() {
    srand(time(NULL));
    int hauteur_sapin;
    printf("Entrer la taille du sapin : ");
    scanf("%d", &hauteur_sapin);
    char **sapin = allouer_sapin(hauteur_sapin);
    init_sapin(sapin, hauteur_sapin);
    dessin_sapin(sapin, hauteur_sapin);
    affiche_sapin(sapin, hauteur_sapin);
    liberer_sapin(sapin, hauteur_sapin);
    return 0;
}