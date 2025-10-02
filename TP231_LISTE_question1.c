
#include <stdio.h>
#include <stdlib.h>

// Définition d'un noeud de la liste simplement chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour supprimer les occurrences d'une valeur dans la liste
Node* removeOccurrences(Node* head, int value) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            // Si le noeud à supprimer est le premier
            if (previous == NULL) {
                Node* temp = current; // Stocke le noeud à libérer
                head = current->next; // Met à jour la tête de la liste
                current = head; // Avance au prochain noeud
                free(temp); // Libère le noeud
            } else {
                previous->next = current->next; // Supprime le noeud en le contournant
                free(current); // Libère le noeud
                current = previous->next; // Avance au prochain noeud
            }
        } else {
            previous = current; // Avance le pointeur précédent
            current = current->next; // Avance au prochain noeud
        }
    }
    return head; // Retourne la nouvelle tête de la liste
}

// Fonction pour afficher la liste
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Fonction principale pour tester la fonction de suppression
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);

    printf("Liste avant suppression:\n");
    printList(head);

    int valueToRemove = 2;
    head = removeOccurrences(head, valueToRemove); // Met à jour la tête de la liste

    printf("Liste après suppression de %d:\n", valueToRemove);
    printList(head);

    // Libération de la mémoire restante
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


