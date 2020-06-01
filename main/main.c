#include <stdio.h>
#include <stdlib.h>

typedef struct sCell {
  int data;
  struct sCell *next;
  struct sCell *prev;
} Cell;

typedef struct sList {
  Cell *init;
  Cell *end;
  struct sList *next;
} List;

void initList( List * list ) {
  list->init = NULL;
}

void printList( List * list ) {
  Cell *p;
  printf("[");
  for( p = list->init; p != NULL; p = p->next ) {
    printf( "%d ", p->data );
  }
  printf("]\n");
}

void insertValueOnList( List * list, int data ) {
  Cell *p;
  p = (Cell *) malloc(sizeof(Cell));
  p->prev = NULL;
  p->data = data;
  p->next = list->init;
  if ( list->init != NULL ) {
    list->init->prev = p;
  }
  list->init = p;
}

List* concatLists( List *l1, List *l2 ) {
  List *p;
  if ( l1->init == NULL ) {
    l1->init = l2->init;
  } else {
    Cell * p = l1->init;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = l2->init;
  }
  return l1;
}

int height( Cell *p ) {
  int result = 0;
  while (p->next != NULL) {
    p = p->next;
    result++;
  }
  return result;
}

int depth( List *l, Cell *p ) {
  int result = 0;
  Cell *q = l->init;
  while (q != NULL && q != p) {
    q = q->next;
    result++;
  }
  return result;
}

int main( int argc, const char *argv[] ) {
  List *firstList;
  List *secondList;
  List *concatenatedLists;
  Cell *p1;
  Cell *p2;
  firstList = (List *) malloc(sizeof(List));
  secondList = (List *) malloc(sizeof(List));
  concatenatedLists = (List *) malloc(sizeof(List));
  p1 = (Cell *) malloc(sizeof(Cell));
  p2 = (Cell *) malloc(sizeof(Cell));

  initList(firstList);
  insertValueOnList(firstList, 1);
  insertValueOnList(firstList, 2);
  insertValueOnList(firstList, 3);
  insertValueOnList(firstList, 4);
  insertValueOnList(firstList, 5);
  printf("\nPrimeira lista:\n");
  printList(firstList);

  initList(secondList);
  insertValueOnList(secondList, 45);
  insertValueOnList(secondList, 67);
  insertValueOnList(secondList, 47);
  insertValueOnList(secondList, 54);
  insertValueOnList(secondList, 89);
  printf("\nSegunda lista:\n");
  printList(secondList);

  concatenatedLists = concatLists(firstList, secondList);
  printf("\nListas concatenadas:\n");
  printList(concatenatedLists);

  printf("\nAltura: %d\n", height(p1));
  printf("\nProfundidade: %d\n", depth(concatenatedLists, p2));

  return 0;
}
