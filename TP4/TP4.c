#include <stdio.h>

// a. Fonction pour afficher un tableau d'entiers
void afficher_tab(int tab[], int taille) {
    for (int i = 0; i < taille; ++i) {
        printf("%d\t", tab[i]);
    }
    printf("\n");
}

// c. Fonction tri à bulles
void bulle(int t[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (t[j] > t[j + 1]) {
                // Échanger t[j] et t[j+1]
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

// 1. Fonction pour trouver la valeur maximale dans un tableau d'entiers
int maximum(int t[], int n) {
    int max = t[0];
    for (int i = 1; i < n; ++i) {
        if (t[i] > max) {
            max = t[i];
        }
    }
    return max;
}

// 2. Fonction pour trouver l'indice du maximum dans un tableau d'entiers
int indiceDuMaximum(int t[], int n) {
    int indiceMax = 0;
    for (int i = 1; i < n; ++i) {
        if (t[i] > t[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

// 3. Fonction pour rechercher un élément dans un tableau d'entiers
int recherche(int t[], int n, int element) {
    for (int i = 0; i < n; ++i) {
        if (t[i] == element) {
            return i; // Retourne l'indice si l'élément est trouvé
        }
    }
    return -1; // Retourne -1 si l'élément n'est pas trouvé
}

// 4. Fonction pour supprimer un élément dans un tableau de flottants
void suppression(float t[], int *n, int indice) {
    if (indice >= 0 && indice < *n) {
        for (int i = indice; i < *n - 1; ++i) {
            t[i] = t[i + 1];
        }
        (*n)--;
    }
}

// 5. Fonction pour insérer un élément dans un tableau de flottants à une position donnée
void insertion(float t[], int *n, int position, float element) {
    if (position >= 0 && position <= *n) {
        for (int i = *n; i > position; --i) {
            t[i] = t[i - 1];
        }
        t[position] = element;
        (*n)++;
    }
}

int main() {
    // Exemple d'utilisation

    // a. Affichage d'un tableau
    int tableau1[] = {5, 3, 2, 4, 1};
    int taille1 = sizeof(tableau1) / sizeof(tableau1[0]);

    printf("Tableau 1 : ");
    afficher_tab(tableau1, taille1);

    // b. Tri à bulles
    bulle(tableau1, taille1);

    printf("Tableau 1 (après tri) : ");
    afficher_tab(tableau1, taille1);

    // 1. Maximum
    printf("Maximum dans tableau 1 : %d\n", maximum(tableau1, taille1));

    // 2. Indice du maximum
    printf("Indice du maximum dans tableau 1 : %d\n", indiceDuMaximum(tableau1, taille1));

    // 3. Recherche
    int position = recherche(tableau1, taille1, 4);
    printf("Position de 4 dans tableau 1 : %d\n", position);

    // 4. Suppression
    float tableau2[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int taille2 = sizeof(tableau2) / sizeof(tableau2[0]);

    printf("Tableau 2 avant suppression : ");
    for (int i = 0; i < taille2; ++i) {
        printf("%.2f\t", tableau2[i]);
    }
    printf("\n");

    suppression(tableau2, &taille2, 2);

    printf("Tableau 2 après suppression à l'indice 2 : ");
    for (int i = 0; i < taille2; ++i) {
        printf("%.2f\t", tableau2[i]);
    }
    printf("\n");

    // 5. Insertion
    insertion(tableau2, &taille2, 2, 3.7);

    printf("Tableau 2 après insertion de 3.7 à la position 2 : ");
    for (int i = 0; i < taille2; ++i) {
        printf("%.2f\t", tableau2[i]);
    }
    printf("\n");

    return 0;
}
