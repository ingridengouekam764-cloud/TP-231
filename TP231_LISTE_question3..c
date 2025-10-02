

#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Cellule
typedef struct Cellule {
    int data;
    struct Cellule* next;
    struct Cellule* prev; // Pointeur vers le nœud précédent
} Cellule;

// Fonction pour insérer un élément dans la liste triée
Cellule* insertSorted(Cellule* head, int value) {
    // Créer un nouveau nœud
    Cellule* new_cellule = (Cellule*)malloc(sizeof(Cellule));
    new_cellule->data = value;
    new_cellule->next = NULL;
    new_cellule->prev = NULL;

    // Si la liste est vide ou si la nouvelle valeur doit être insérée avant la tête
    if (head == NULL || head->data >= value) {
        new_cellule->next = head; // Lier la nouvelle cellule à la tête
        if (head != NULL) {
            head->prev = new_cellule; // Lier la tête au nouveau nœud
        }
        return new_cellule; // La nouvelle cellule devient la tête
    }

    // Recherche de la position d'insertion
    Cellule* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next; // Avancer dans la liste
    }

    // Insérer la nouvelle cellule
    new_cellule->next = current->next; // Lier la nouvelle cellule à la cellule suivante
    if (current->next != NULL) {
        current->next->prev = new_cellule; // Lier la cellule suivante au nouveau nœud
    }
    current->next = new_cellule; // Lier la cellule précédente à la nouvelle cellule
    new_cellule->prev = current; // Lier la nouvelle cellule à la cellule précédente

    return head; // Retourner la tête de la liste
}

// Fonction pour afficher la liste
void printList(Cellule* cellule) {
    while (cellule != NULL) {
        printf("%d <-> ", cellule->data);
        cellule = cellule->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire de la liste
void freeList(Cellule* head) {
    Cellule* current = head;
    Cellule* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Cellule* head = NULL; // Initialisation de la tête de la liste
    int n, value;

    // Demander à l'utilisateur combien de valeurs il souhaite entrer
    printf("Combien de valeurs voulez-vous entrer ? ");
    scanf("%d", &n);

    // Demander à l'utilisateur d'entrer les valeurs triées
    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &value);
        head = insertSorted(head, value); // Insérer chaque valeur dans la liste triée
    }

    printf("Liste triée : ");
    printList(head);

    // Demander à l'utilisateur quelle valeur insérer
    printf("Quelle valeur voulez-vous insérer dans la liste triée ? ");
    scanf("%d", &value);
    
    head = insertSorted(head, value); // Insérer la nouvelle valeur

    printf("Liste après insertion : ");
    printList(head);

    // Libérer la mémoire allouée pour la liste
    freeList(head);

    return 0;
}


