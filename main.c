#include "linkedlist.h"

void display_int(void *data)
{
  printf("%d\n", *(int *)data);
}

int main()
{
  List_ptr numbers = create_list();
  int *five = malloc(sizeof(int));

  *five = 5;

  int *four = malloc(sizeof(int));
  *four = 4;

  add_to_list(numbers, five);
  add_to_list(numbers, four);

  forEach(numbers, &display_int);

  clear_list(numbers);
  free(numbers);
  return 0;
}
