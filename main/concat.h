#ifndef concat_h
#define concat_h

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

void initList( List * list );
void printList( List * list );
void insertValueOnList( List * list, int data );
List* concatLists( List *l1, List *l2 );
int height( Cell *p );
int depth( List *l, Cell *p );

#endif
