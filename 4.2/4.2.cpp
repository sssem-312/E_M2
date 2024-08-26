#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_PRIORITY 255
#define MIN_PRIORITY 0

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

PriorityQueue* createQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    return pq;
}

// Функция для добавления элемента в очередь с приоритетом
void enqueue(PriorityQueue* pq, int data, int priority) {
    if (priority < MIN_PRIORITY || priority > MAX_PRIORITY) {
        printf("Ошибка: Приоритет должен быть в диапазоне от %d до %d.\n", MIN_PRIORITY, MAX_PRIORITY);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    // Если очередь пустая или новый элемент имеет более высокий приоритет, чем передний элемент
    if (pq->front == NULL || pq->front->priority < priority) {
        newNode->next = pq->front;
        pq->front = newNode;
        return;
    }

    // Нахождение позиции для вставки нового узла
    Node* current = pq->front;
    while (current->next != NULL && current->next->priority >= priority) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Функция для извлечения элемента с максимальным приоритетом
int dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Очередь пуста!\n");
        return -1;
    }

    Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;

    free(temp);
    return data;
}

// Функция для извлечения элемента с указанным приоритетом
int dequeueWithPriority(PriorityQueue* pq, int priority) {
    if (pq->front == NULL) {
        printf("Очередь пуста!\n");
        return -1;
    }

    // Проверка на передний элемент
    if (pq->front->priority == priority) {
        return dequeue(pq);
    }

    // Нахождение элемента с указанным приоритетом
    Node* current = pq->front;
    Node* prev = NULL;
    while (current != NULL && current->priority != priority) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Элемент с приоритетом %d не найден!\n", priority);
        return -1;
    }

    int data = current->data;
    prev->next = current->next;
    free(current);
    return data;
}

// Функция для извлечения элемента с приоритетом не ниже заданного
int dequeueWithMinPriority(PriorityQueue* pq, int minPriority) {
  if (pq->front == NULL) {
      printf("Очередь пуста!\n");
      return -1;
  }

  Node* current = pq->front;
  Node* prev = NULL;

  while (current != NULL && current->priority < minPriority) {
      prev = current;
      current = current->next;
  }

  if (current == NULL) {
      printf("Нет элементов с приоритетом не ниже %d!\n", minPriority);
      return -1;
  }

  int data = current->data;

  if (prev == NULL) {
      pq->front = pq->front->next;
  } else {
      prev->next = current->next;
  }

  free(current);
  return data;
}

void freeQueue(PriorityQueue* pq) {
    Node* current = pq->front;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(pq);
}

void menu() 
{ 
    printf(" ---------------- Меню -----------------\n"); 
    printf(" [1] Добавить элемент\n"); 
    printf(" [2] Извлечь элемент с максимальным приоритетом\n"); 
    printf(" [3] Извлечь элемент с указанным приоритетом\n"); 
    printf(" [4] Извлечь элемент с приоритетом не ниже указанного\n"); 
    printf(" [0] Выход\n"); 
    printf(" ---------------------------------------\n"); 
}

int main() 
{ 
  setlocale(LC_ALL, "Russian"); 
    PriorityQueue* pq = createQueue(); 
    fseek(stdin, 0, SEEK_END); 
    menu(); 
    int input, p, d; 
    while (1) 
    { 
        printf("\n Что вы хотите сделать? "); 
        scanf(" %d", &input); 
        printf("\n"); 
        if (input == 0) break; 
 
        switch (input) 
        { 
        case 1: 
            printf(" Элемент с какими данными и приоритетом Вы хотите добавить? \n"); 
            scanf(" %d %d", &d, &p); 
            printf("\n"); 
            enqueue(pq, d, p);
            printf(" Элемент добавлен!\n"); 
            break; 
 
        case 2:
            printf("Элемент с максимальным приоритетом и данными %d извлечен!\n", dequeue(pq)); 
            break; 
 
        case 3:
            printf(" Элемент с каким приоритетом Вы хотите извлечь?\n"); 
            scanf(" %d", &p);
			      printf("\n");
            printf(" Элемент с приоритетом %d и данными %d извлечен!\n", p, dequeueWithPriority(pq, p));
            break; 
 
        case 4:
            printf(" Элемент с приоритетом не ниже какого Вы хотите извлечь?\n"); 
            scanf(" %d", &p); 
            printf("\n");
            printf(" Элемент с приоритетом не ниже %d и данными %d извлечен!\n", p, dequeueWithMinPriority(pq, p));
            break; 
 
        default: 
            break; 
        } 
        menu(); 
    } 
    freeQueue(pq);
    return 0; 
}