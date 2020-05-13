#include "linkedlist.h"

void display_int(void *data)
{
  printf("%d\n", *(int *)data);
}

Element square(Element element)
{
  int *value = malloc(sizeof(int));
  *value = *(int *)element * *(int *)element;
  return (Element)value;
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

  List_ptr reversed = reverse(numbers);
  List_ptr squares = map(numbers, &square);

  remove_from_start(numbers);
  remove_from_end(numbers);

  forEach(squares, &display_int);
  forEach(numbers, &display_int);
  forEach(reversed, &display_int);

  destroy_list(numbers);
  return 0;
}
