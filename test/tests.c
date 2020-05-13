#include "assert.h"
#include "../linkedlist.h"

Status assert_int(Element element_1, Element element_2)
{
  return *(int *)element_1 == *(int *)element_2;
}

Element create_int(int value)
{
  int *element = malloc(sizeof(int));
  return (Element)element;
}

void test_add_to_list(void)
{
  List_ptr list = create_list();
  Element number_1_1 = create_int(5);
  Element elements_1[1];
  elements_1[0] = number_1_1;

  add_to_list(list, number_1_1);
  char message_1[] = "should add an element to the list when the list is empty";
  display_assertion(assert_list(list, elements_1, 1, &assert_int), message_1);
}

int main(void)
{
  test_add_to_list();
  display_passing_count();
  return 0;
}