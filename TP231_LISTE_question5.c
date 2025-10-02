
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Cellule
typedef struct Cellule {
    int data;
    struct Cellule* next;
    struct Cellule* prev;
} Cellule;

// Fonction pour insérer un élément en tête de la liste
Cellule* insertAtHead(Cellule* head, int value) {
    // Créer un nouveau nœud
    Cellule* new_cellule = (Cellule*)malloc(sizeof(Cellule));
    new_cellule->data = value;

    // Si la liste est vide, le nouveau nœud pointe vers lui-même
    if (head == NULL) {
        new_cellule->next = new_cellule;
        new_cellule->prev = new_cellule;
        return new_cellule; // Le nouveau nœud devient la tête
    }

    // Mettre à jour les pointeurs pour insérer en tête
    Cellule* tail = head->prev; // Dernier nœud
    new_cellule->next = head; // Le nouveau nœud pointe vers l'ancienne tête
    new_cellule->prev = tail; // Le nouveau nœud pointe vers le dernier nœud
    head->prev = new_cellule; // L'ancienne tête pointe vers le nouveau nœud
    tail->next = new_cellule; // Le dernier nœud pointe vers le nouveau nœud

    return new_cellule; // Le nouveau nœud devient la nouvelle tête
}

// Fonction pour insérer un élément en queue de la liste
Cellule* insertAtTail(Cellule* head, int value) {
    // Créer un nouveau nœud
    Cellule* new_cellule = (Cellule*)malloc(sizeof(Cellule));
    new_cellule->data = value;

    // Si la liste est vide, le nouveau nœud pointe vers lui-même
    if (head == NULL) {
        new_cellule->next = new_cellule;
        new_cellule->prev = new_cellule;
        return new_cellule; // Le nouveau nœud devient la tête
    }

    // Mettre à jour les pointeurs pour insérer en queue
    Cellule* tail = head->prev; // Dernier nœud
    tail->next = new_cellule; // L'ancien dernier nœud pointe vers le nouveau nœud
    new_cellule->prev = tail; // Le nouveau nœud pointe vers l'ancien dernier nœud
    new_cellule->next = head; // Le nouveau nœud pointe vers la tête
    head->prev = new_cellule; // La tête pointe vers le nouveau nœud

    return head; // La tête reste inchangée
}

// Fonction pour afficher la liste
void printList(Cellule* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Cellule* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("(retour à %d)\n", head->data); // Indique que c'est circulaire
}

// Fonction principale
int main() {
    Cellule* head = NULL; // Initialisation de la tête de la liste
    int choice, value;

    while (1) {
        printf("Choisissez une option:\n");
        printf("1. Insérer en tête\n");
        printf("2. Insérer en queue\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez la valeur à insérer en tête: ");
                scanf("%d", &value);
                head = insertAtHead(head, value);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue: ");
                scanf("%d", &value);
                head = insertAtTail(head, value);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}


