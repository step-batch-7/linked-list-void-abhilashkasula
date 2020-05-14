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

Status is_even(Element element)
{
  return *(int *)element % 2 == 0;
}

Element add(Element context, Element value)
{
  *(int *)context = *(int *)context + *(int *)value;
  return context;
}

Status is_int_equal(Element elem1, Element elem2)
{
  return *(int *)elem1 == *(int *)elem2;
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
  List_ptr evens = filter(numbers, &is_even);
  forEach(evens, &display_int);

  int *value = malloc(sizeof(int));
  *value = 0;
  Element sum = reduce(numbers, value, &add);
  printf("Sum: %d\n", *(int *)sum);

  add_unique(numbers, five, &is_int_equal);
  forEach(numbers, &display_int);
  printf("\n");

  remove_from_start(numbers);
  remove_from_end(numbers);

  insert_at(numbers, value, 0);
  remove_at(numbers, 1);

  // remove_first_occurrence(numbers, sum, is_int_equal);
  int *twelve = malloc(sizeof(int));
  *twelve = 12;
  add_to_list(numbers, twelve);
  remove_all_occurrences(numbers, sum, is_int_equal);

  forEach(squares, &display_int);
  forEach(numbers, &display_int);
  forEach(reversed, &display_int);

  destroy_list(numbers);
  return 0;
}
