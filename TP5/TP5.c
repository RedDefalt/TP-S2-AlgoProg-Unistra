#include <stdio.h>

// a. Définition du type point
typedef struct {
    int x;
    int y;
} Point;

// b. Afficher un point
void afficher_point(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

// c. Afficher un tableau de points
void afficher_point_tab(Point tab[], int taille) {
    for (int i = 0; i < taille; ++i) {
        afficher_point(tab[i]);
    }
}

// d. Comparer deux points selon l'ordre lexicographique
int compare_points_lexico(const Point *p1, const Point *p2) {
    if (p1->x > p2->x || (p1->x == p2->x && p1->y > p2->y)) {
        return 1; // p1 > p2
    } else {
        return 0; // p1 <= p2
    }
}

// e. Comparer deux points selon l'ordre diagonal
int compare_points_diagonal(const Point *p1, const Point *p2) {
    if (p1->x + p1->y > p2->x + p2->y || (p1->x + p1->y == p2->x + p2->y && p1->x > p2->x)) {
        return 1; // p1 > p2
    } else {
        return 0; // p1 <= p2
    }
}

// f. Tri à bulles pour un tableau de points avec ordre lexicographique
void bulle_lexico(Point t[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (compare_points_lexico(&t[j], &t[j + 1])) {
                // Échanger t[j] et t[j+1]
                Point temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

// g. Tri à bulles pour un tableau de points avec ordre diagonal
void bulle_diagonal(Point t[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (compare_points_diagonal(&t[j], &t[j + 1])) {
                // Échanger t[j] et t[j+1]
                Point temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

// 2. Matrices

// Définition du type matrice
#define MAX_SIZE 100

typedef struct {
    int lignes;
    int colonnes;
    double elements[MAX_SIZE][MAX_SIZE];
} Matrice;

// 1. Affichage d'une matrice
void affiche(Matrice *m) {
    for (int i = 0; i < m->lignes; ++i) {
        for (int j = 0; j < m->colonnes; ++j) {
            printf("%.2f\t", m->elements[i][j]);
        }
        printf("\n");
    }
}

// 2. Compter le nombre d'éléments nuls dans une matrice
int nombreDeZeros(Matrice *m) {
    int count = 0;
    for (int i = 0; i < m->lignes; ++i) {
        for (int j = 0; j < m->colonnes; ++j) {
            if (m->elements[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

// 3. Teste si une matrice est diagonale
int estDiagonale(Matrice *m) {
    if (m->lignes != m->colonnes) {
        return 0; // Une matrice n'est pas diagonale si le nombre de lignes est différent du nombre de colonnes
    }

    for (int i = 0; i < m->lignes; ++i) {
        for (int j = 0; j < m->colonnes; ++j) {
            if (i != j && m->elements[i][j] != 0) {
                return 0; // Si un élément en dehors de la diagonale n'est pas nul, la matrice n'est pas diagonale
            }
        }
    }

    return 1; // La matrice est diagonale
}

// 4. Teste si une matrice est symétrique
int estSymetrique(Matrice *m) {
    if (m->lignes != m->colonnes) {
        return 0; // Une matrice n'est pas symétrique si le nombre de lignes est différent du nombre de colonnes
    }

    for (int i = 0; i < m->lignes; ++i) {
        for (int j = 0; j < m->colonnes; ++j) {
            if (m->elements[i][j] != m->elements[j][i]) {
                return 0; // Si les éléments ne sont pas symétriques par rapport à la diagonale, la matrice n'est pas symétrique
            }
        }
    }

    return 1; // La matrice est symétrique
}

// 5. Transposition d'une matrice
void transpose(Matrice *m) {
    Matrice temp;
    temp.lignes = m->colonnes;
    temp.colonnes = m->lignes;

    for (int i = 0; i < m->lignes; ++i) {
        for (int j = 0; j < m->colonnes; ++j) {
            temp.elements[j][i] = m->elements[i][j];
        }
    }

    *m = temp;
}

// 6. Addition de deux matrices
void addition(Matrice *m1, Matrice *m2, Matrice *resultat) {
    if (m1->lignes != m2->lignes || m1->colonnes != m2->colonnes) {
        printf("Les matrices doivent avoir la même taille pour l'addition.\n");
        return;
    }

    resultat->lignes = m1->lignes;
    resultat->colonnes = m1->colonnes;

    for (int i = 0; i < m1->lignes; ++i) {
        for (int j = 0; j < m1->colonnes; ++j) {
            resultat->elements[i][j] = m1->elements[i][j] + m2->elements[i][j];
        }
    }
}

// 7. Multiplication de deux matrices
void multiplication(Matrice *m1, Matrice *m2, Matrice *resultat) {
    if (m1->colonnes != m2->lignes) {
        printf("Le nombre de colonnes de la première matrice doit être égal au nombre de lignes de la deuxième matrice pour la multiplication.\n");
        return;
    }

    resultat->lignes = m1->lignes;
    resultat->colonnes = m2->colonnes;

    for (int i = 0; i < m1->lignes; ++i) {
        for (int j = 0; j < m2->colonnes; ++j) {
            resultat->elements[i][j] = 0;
            for (int k = 0; k < m1->colonnes; ++k) {
                resultat->elements[i][j] += m1->elements[i][k] * m2->elements[k][j];
            }
        }
    }
}

int main() {
    // Test avec des points
    Point points[] = {{5, 3}, {2, 4}, {1, 6}, {3, 1}, {4, 5}, {6, 2}};
    int taille_points = sizeof(points) / sizeof(points[0]);

    printf("Points avant tri lexicographique :\n");
    afficher_point_tab(points, taille_points);

    // Tri lexicographique
    bulle_lexico(points, taille_points);

    printf("Points après tri lexicographique :\n");
    afficher_point_tab(points, taille_points);

    printf("\nPoints avant tri diagonal :\n");
    afficher_point_tab(points, taille_points);

    // Tri diagonal
    bulle_diagonal(points, taille_points);

    printf("Points après tri diagonal :\n");
    afficher_point_tab(points, taille_points);

    // Test avec des matrices
    Matrice matrice1 = {3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrice matrice2 = {3, 3, {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}};
    Matrice resultat;

    printf("\nMatrice 1 :\n");
    affiche(&matrice1);

    printf("\nMatrice 2 :\n");
    affiche(&matrice2);

    // Addition de matrices
    addition(&matrice1, &matrice2, &resultat);
    printf("\nAddition de matrices :\n");
    affiche(&resultat);

    // Multiplication de matrices
    multiplication(&matrice1, &matrice2, &resultat);
    printf("\nMultiplication de matrices :\n");
    affiche(&resultat);

    // Transposition d'une matrice
    transpose(&matrice1);
    printf("\nTransposée de la Matrice 1 :\n");
    affiche(&matrice1);

    // Test si une matrice est diagonale
    printf("\nLa Matrice 1 est diagonale : %s\n", estDiagonale(&matrice1) ? "Oui" : "Non");

    // Test si une matrice est symétrique
    printf("\nLa Matrice 1 est symétrique : %s\n", estSymetrique(&matrice1) ? "Oui" : "Non");

    // Nombre d'éléments nuls dans une matrice
    printf("\nNombre d'éléments nuls dans la Matrice 1 : %d\n", nombreDeZeros(&matrice1));

    return 0;
}
