#include <stdio.h>

// 1. Fonction pour coder un caractère selon ROT13
char code_cara(char c) {
    return (c >= 'A' && c <= 'Z') ? ((c - 'A' + 13) % 26) + 'A' : c;
}

// 2. Fonction pour coder un message selon ROT13
void code_message(char message[]) {
    for (int i = 0; message[i] != '\0'; ++i) {
        message[i] = code_cara(message[i]);
    }
}

// 4. Fonction pour coder un message selon ROTn (généralisation)
void code_message_rot_n(char message[], int n) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + n) % 26) + 'A';
        }
    }
}

// 5. Fonction pour trouver l'indice du maximum dans un tableau d'entiers
int indiceDuMaximum(int tab[], int taille) {
    int indiceMax = 0;
    for (int i = 1; i < taille; ++i) {
        if (tab[i] > tab[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

// 6. Fonction pour trouver la lettre la plus fréquente dans un message
char lettrePlusFrequente(char message[]) {
    int occurrences[26] = {0};  // Initialiser le tableau d'occurrences à zéro

    // Compter les occurrences de chaque lettre
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            occurrences[message[i] - 'A']++;
        }
    }

    // Trouver l'indice de la lettre la plus fréquente
    int indiceMax = indiceDuMaximum(occurrences, 26);

    // Retourner la lettre correspondante
    return indiceMax + 'A';
}

int main() {
    // 3. Demander à l'utilisateur d'entrer un message
    char message[100];

    printf("Entrez un message en majuscules (max 99 caractères) : ");
    fgets(message, sizeof(message), stdin);

    // Supprimer le caractère de nouvelle ligne ajouté par fgets
    int i = 0;
    while (message[i] != '\n') {
        i++;
    }
    message[i] = '\0';

    // 3. Afficher le message codé
    printf("Message original : %s\n", message);

    // 4. Coder le message selon ROT13
    code_message(message);
    printf("Message codé ROT13 : %s\n", message);

    // 4. Coder le message selon ROTn (généralisation)
    int n;
    printf("Entrez la valeur de n pour le code ROTn : ");
    scanf("%d", &n);

    code_message_rot_n(message, n);
    printf("Message codé ROT%d : %s\n", n, message);

    // 6. Trouver la lettre la plus fréquente
    char lettreFrequente = lettrePlusFrequente(message);
    printf("Lettre la plus fréquente : %c\n", lettreFrequente);

    return 0;
}
