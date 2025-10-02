
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Cellule
typedef struct Cellule {
    int data;
    struct Cellule* next;
} Cellule;

// Fonction pour insérer un élément en tête de la liste
Cellule* insertAtHead(Cellule* head, int value) {
    // Créer un nouveau nœud
    Cellule* new_cellule = (Cellule*)malloc(sizeof(Cellule));
    new_cellule->data = value;

    // Si la liste est vide, le nouveau nœud pointe vers lui-même
    if (head == NULL) {
        new_cellule->next = new_cellule;
        return new_cellule; // Le nouveau nœud devient la tête
    }

    // Trouver le dernier nœud pour maintenir la circularité
    Cellule* current = head;
    while (current->next != head) {
        current = current->next;
    }

    // Insérer le nouveau nœud en tête
    current->next = new_cellule; // L'ancien dernier nœud pointe vers le nouveau nœud
    new_cellule->next = head; // Le nouveau nœud pointe vers l'ancienne tête

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
        return new_cellule; // Le nouveau nœud devient la tête
    }

    // Trouver le dernier nœud pour maintenir la circularité
    Cellule* current = head;
    while (current->next != head) {
        current = current->next;
    }

    // Insérer le nouveau nœud en queue
    current->next = new_cellule; // L'ancien dernier nœud pointe vers le nouveau nœud
    new_cellule->next = head; // Le nouveau nœud pointe vers la tête

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
        printf("%d -> ", current->data);
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


