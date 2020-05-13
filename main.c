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

  int *three = malloc(sizeof(int));
  *three = 3;

  add_to_list(numbers, five);
  add_to_list(numbers, four);
  add_to_start(numbers, three);

  forEach(numbers, &display_int);

  destroy_list(numbers);
  return 0;
}
