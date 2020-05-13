#include "assert.h"
#include "../linkedlist.h"

Status assert_int(Element element_1, Element element_2)
{
  return *(int *)element_1 == *(int *)element_2;
}

Status assert_char(Element element_1, Element element_2)
{
  return *(char *)element_1 == *(char *)element_2;
}

Element create_int(int value)
{
  int *element = malloc(sizeof(int));
  *element = value;
  return (Element)element;
}

Element create_char(char value)
{
  char *element = malloc(sizeof(char));
  *element = value;
  return (Element)element;
}

void test_add_to_list(void)
{
  printf("add_to_list\n");

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
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element letter_3_1 = create_char('a');
  Element expected_3[1];
  expected_3[0] = letter_3_1;
  add_to_list(list_3, letter_3_1);
  char message_3[] = "should add character to the list when the list is empty";
  display_assertion(assert_list(list_3, expected_3, 1, &assert_char), message_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element letter_4_1 = create_char('a');
  Element letter_4_2 = create_char('b');
  Element letter_4_3 = create_char('c');
  Element expected_4[3];
  expected_4[0] = letter_4_1;
  expected_4[1] = letter_4_2;
  expected_4[2] = letter_4_3;
  add_to_list(list_4, letter_4_1);
  char message_4[] = "should add character to the list when the list has elements";
  display_assertion(assert_list(list_4, expected_4, 1, &assert_char), message_4);
  destroy_list(list_4);
}

void test_add_to_start(void)
{
  printf("add_to_start\n");

  List_ptr list_1 = create_list();
  Element number_1_1 = create_int(4);
  Element expected_1[1];
  expected_1[0] = number_1_1;
  add_to_start(list_1, number_1_1);
  char message_1[] = "should add number to start when the list is empty";
  display_assertion(assert_list(list_1, expected_1, 1, &assert_int), message_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(4);
  Element number_2_2 = create_int(5);
  Element expected_2[2];
  expected_2[0] = number_2_2;
  expected_2[1] = number_2_1;
  add_to_start(list_2, number_2_1);
  add_to_start(list_2, number_2_2);
  char message_2[] = "should add number to start when the list has one element";
  display_assertion(assert_list(list_2, expected_2, 2, &assert_int), message_2);
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(4);
  Element number_3_2 = create_int(5);
  Element number_3_3 = create_int(6);
  Element expected_3[3];
  expected_3[0] = number_3_3;
  expected_3[1] = number_3_2;
  expected_3[2] = number_3_1;
  add_to_start(list_3, number_3_1);
  add_to_start(list_3, number_3_2);
  add_to_start(list_3, number_3_3);
  char message_3[] = "should add number to start when the list has more than one element";
  display_assertion(assert_list(list_3, expected_3, 3, &assert_int), message_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element letter_4_1 = create_char('a');
  Element expected_4[1];
  expected_4[0] = letter_4_1;
  add_to_start(list_4, letter_4_1);
  char message_4[] = "should add a character to start when the list is empty";
  display_assertion(assert_list(list_4, expected_4, 1, &assert_char), message_4);
  destroy_list(list_4);

  List_ptr list_5 = create_list();
  Element letter_5_1 = create_char('a');
  Element letter_5_2 = create_char('b');
  Element letter_5_3 = create_char('c');
  Element expected_5[3];
  expected_5[0] = letter_5_3;
  expected_5[1] = letter_5_2;
  expected_5[2] = letter_5_1;
  add_to_start(list_5, letter_5_1);
  add_to_start(list_5, letter_5_2);
  add_to_start(list_5, letter_5_3);
  char message_5[] = "should add character to start when the list has more than one element";
  display_assertion(assert_list(list_5, expected_5, 3, &assert_char), message_5);
  destroy_list(list_5);
}

void test_reverse(void)
{
  printf("reverse\n");

  List_ptr numbers_1 = create_list();
  List_ptr actual_1 = reverse(numbers_1);
  Element expected_1[0];
  char message_1[] = "should give empty list for empty list given";
  display_assertion(assert_list(actual_1, expected_1, 0, &assert_int), message_1);
  destroy_list(numbers_1);

  List_ptr numbers_2 = create_list();
  Element number_2_1 = create_int(5);
  Element expected_2[1];
  expected_2[0] = number_2_1;
  add_to_list(numbers_2, number_2_1);
  List_ptr actual_2 = reverse(numbers_2);
  char message_2[] = "should give the same list for given list contains only one element";
  display_assertion(assert_list(actual_2, expected_2, 1, &assert_int), message_2);
  destroy_list(numbers_2);

  List_ptr numbers_3 = create_list();
  Element number_3_1 = create_int(5);
  Element number_3_2 = create_int(6);
  Element number_3_3 = create_int(7);
  Element expected_3[3];
  expected_3[0] = number_3_3;
  expected_3[1] = number_3_2;
  expected_3[2] = number_3_1;
  add_to_list(numbers_3, number_3_1);
  add_to_list(numbers_3, number_3_2);
  add_to_list(numbers_3, number_3_3);
  List_ptr actual_3 = reverse(numbers_3);
  char message_3[] = "should reverse the numbers for more than one element given";
  display_assertion(assert_list(actual_3, expected_3, 3, &assert_int), message_3);
  destroy_list(numbers_3);
}

int main(void)
{
  test_add_to_list();
  test_add_to_start();
  test_reverse();
  display_passing_count();
  return 0;
}