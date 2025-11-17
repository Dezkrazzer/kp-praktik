/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[50];
    char nim[20];
    struct Node* next;
};

struct Node* createNode(char nama[], char nim[]);
void insertAtEnd(struct Node** head, char nama[], char nim[]);
void insertAtBeginning(struct Node** head, char nama[], char nim[]);
void insertAtPosition(struct Node** head, char nama[], char nim[], int position);
void deleteFirst(struct Node** head);
void deleteLast(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void printList(struct Node* head, char title[]);
void freeList(struct Node** head);

int main()
{
    struct Node* head = NULL;
    
    printf("=========================================================\n");
    printf("|                     List Mahasiswa                    |\n");
    printf("=========================================================\n\n");
    
    // 1. Buat 5 list mahasiswa
    insertAtEnd(&head, "Eldarie Irma Fanomenel", "L0125000");
    insertAtEnd(&head, "Muchammad Abdurohim", "L0120120");
    insertAtEnd(&head, "Lelouch VI Britannia", "L0124123");
    insertAtEnd(&head, "John Doe", "L0125200");
    insertAtEnd(&head, "Yolde Leela Fenomenea", "L0125120");
    
    // 2. Cetak list awal
    printList(head, "Student List (Initially)");
    
    // 3. Hapus node posisi pertama dan terakhir
    deleteFirst(&head);
    deleteLast(&head);
    
    // 4. Cetak hasil list setelahnya
    printList(head, "Student List (After deleting the first and last student)");
    
    // 5. Tambahkan mahasiswa baru di node posisi pertama, ketiga, dan terakhir
    insertAtBeginning(&head, "Kaiser de Emperana Beelzebub IV", "L0123000");
    insertAtPosition(&head, "Legolas", "L0122222", 3);
    insertAtEnd(&head, "Houshou Marine", "L0121221");
    
    // 6. Cetak hasil list setelahnya
    printList(head, "Student List (After adding new students at the first, third, and last position)");
    
    // Hapus mahasiswa di posisi ke-3
    printf("\n--- Delete at Position ---\n");
    deleteAtPosition(&head, 3);
    printList(head, "Student List (After deleting the third position student)");
    
    // Bersihkan memori
    freeList(&head);
    
    printf("\n=========================================================\n");
    printf("      Program selesai. Semua memori telah dibersihkan.    \n");
    printf("              Lazuardi Akbar Imani - L0125105             \n");
    printf("=========================================================\n");
    
    return 0;
}

// Fungsi membuat node baru
struct Node* createNode(char nama[], char nim[])
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("[ERROR] Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->nama, nama);
    strcpy(newNode->nim, nim);
    newNode->next = NULL;
    return newNode;
}

// Fungsi menambahkan node di akhir list
void insertAtEnd(struct Node** head, char nama[], char nim[])
{
    struct Node* newNode = createNode(nama, nim);
    
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi menambahkan node di awal list
void insertAtBeginning(struct Node** head, char nama[], char nim[])
{
    struct Node* newNode = createNode(nama, nim);
    newNode->next = *head;
    *head = newNode;
}

// Fungsi menambahkan node di posisi tertentu
void insertAtPosition(struct Node** head, char nama[], char nim[], int position)
{
    if (position == 1)
    {
        insertAtBeginning(head, nama, nim);
        return;
    }
    
    struct Node* newNode = createNode(nama, nim);
    struct Node* temp = *head;
    
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)
    {
        printf("[ERROR] Position out of range!\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi menghapus node pertama
void deleteFirst(struct Node** head)
{
    if (*head == NULL)
    {
        printf("[ERROR] List is empty!\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Fungsi menghapus node terakhir
void deleteLast(struct Node** head)
{
    if (*head == NULL)
    {
        printf("[ERROR] List is empty!\n");
        return;
    }
    
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
}

// Fungsi menghapus node di posisi tertentu
void deleteAtPosition(struct Node** head, int position)
{
    if (*head == NULL)
    {
        printf("[ERROR] List is empty!\n");
        return;
    }
    
    if (position == 1)
    {
        deleteFirst(head);
        return;
    }
    
    struct Node* temp = *head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL)
    {
        printf("[ERROR] Position out of range!\n");
        return;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Fungsi mencetak seluruh list
void printList(struct Node* head, char title[])
{
    printf("\n%s:\n", title);
    
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    int count = 1;
    
    while (temp != NULL)
    {
        printf("%d. %s - %s\n", count, temp->nama, temp->nim);
        temp = temp->next;
        count++;
    }
}

// Fungsi membersihkan semua node (free memory)
void freeList(struct Node** head)
{
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}