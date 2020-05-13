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
  List_ptr list_1 = create_list();
  Element number_1_1 = create_int(5);
  Element expected_1[1];
  expected_1[0] = number_1_1;
  add_to_list(list_1, number_1_1);
  char message_1[] = "should add number to the list when the list is empty";
  display_assertion(assert_list(list_1, expected_1, 1, &assert_int), message_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(4);
  Element number_2_2 = create_int(5);
  Element number_2_3 = create_int(6);
  Element expected_2[3];
  expected_2[0] = number_2_1;
  expected_2[1] = number_2_2;
  expected_2[2] = number_2_3;
  add_to_list(list_2, number_2_1);
  add_to_list(list_2, number_2_2);
  add_to_list(list_2, number_2_3);
  char message_2[] = "should add number to the list when the list has elements";
  display_assertion(assert_list(list_2, expected_2, 3, &assert_int), message_2);
}

int main(void)
{
  test_add_to_list();
  display_passing_count();
  return 0;
}