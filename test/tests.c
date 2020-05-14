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

void modify_to_zero(Element elem)
{
  *(int *)elem = 0;
}

Element square(Element element)
{
  int *result = malloc(sizeof(int));
  *result = *(int *)element * *(int *)element;
  return result;
}

Element convert_to_lowercase(Element element)
{
  char *result = malloc(sizeof(int));
  *result = *(int *)element + 32;
  return result;
}

Status is_int_equal(Element a, Element b)
{
  return *(int *)a == *(int *)b;
}

void test_add_to_list(void)
{
  printf("add_to_list\n");

  List_ptr list_1 = create_list();
  Element number_1_1 = create_int(5);
  Element expected_1[1];
  expected_1[0] = number_1_1;
  Status status_1 = add_to_list(list_1, number_1_1);
  char message_1[] = "should add number to the list when the list is empty";
  Status assertion_status = assert_status(status_1, Success) && assert_list(list_1, expected_1, 1, &assert_int);
  display_assertion(assertion_status, message_1);
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
  Status status_2 = add_to_list(list_2, number_2_3);
  char message_2[] = "should add number to the list when the list has elements";
  assertion_status = assert_status(status_2, Success) && assert_list(list_2, expected_2, 3, &assert_int);
  display_assertion(assertion_status, message_2);
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element letter_3_1 = create_char('a');
  Element expected_3[1];
  expected_3[0] = letter_3_1;
  Status status_3 = add_to_list(list_3, letter_3_1);
  char message_3[] = "should add character to the list when the list is empty";
  assertion_status = assert_status(status_3, Success) && assert_list(list_3, expected_3, 1, &assert_char);
  display_assertion(assertion_status, message_3);
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
  add_to_list(list_4, letter_4_2);
  Status status_4 = add_to_list(list_4, letter_4_3);
  char message_4[] = "should add character to the list when the list has elements";
  assertion_status = assert_status(status_4, Success) && assert_list(list_4, expected_4, 3, &assert_char);
  display_assertion(assertion_status, message_4);
  destroy_list(list_4);
}

void test_add_to_start(void)
{
  printf("add_to_start\n");
  Status status;
  Status assertion_status;

  List_ptr list_1 = create_list();
  Element number_1_1 = create_int(4);
  Element expected_1[1];
  expected_1[0] = number_1_1;
  status = add_to_start(list_1, number_1_1);
  char message_1[] = "should add number to start when the list is empty";
  assertion_status = assert_status(status, Success) && assert_list(list_1, expected_1, 1, &assert_int);
  display_assertion(assertion_status, message_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(4);
  Element number_2_2 = create_int(5);
  Element expected_2[2];
  expected_2[0] = number_2_2;
  expected_2[1] = number_2_1;
  add_to_start(list_2, number_2_1);
  status = add_to_start(list_2, number_2_2);
  char message_2[] = "should add number to start when the list has one element";
  assertion_status = assert_status(status, Success) && assert_list(list_2, expected_2, 2, &assert_int);
  display_assertion(assertion_status, message_2);
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
  status = add_to_start(list_3, number_3_3);
  char message_3[] = "should add number to start when the list has more than one element";
  assertion_status = assert_status(status, Success) && assert_list(list_3, expected_3, 3, &assert_int);
  display_assertion(assertion_status, message_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element letter_4_1 = create_char('a');
  Element expected_4[1];
  expected_4[0] = letter_4_1;
  status = add_to_start(list_4, letter_4_1);
  char message_4[] = "should add a character to start when the list is empty";
  assertion_status = assert_status(status, Success) && assert_list(list_4, expected_4, 1, &assert_char);
  display_assertion(assertion_status, message_4);
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
  status = add_to_start(list_5, letter_5_3);
  char message_5[] = "should add character to start when the list has more than one element";
  assertion_status = assert_status(status, Success) && assert_list(list_5, expected_5, 3, &assert_char);
  display_assertion(assertion_status, message_5);
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

  List_ptr alphabets = create_list();
  Element letter_1 = create_char('a');
  Element letter_2 = create_char('b');
  Element letter_3 = create_char('c');
  Element expected_4[3];
  expected_4[0] = letter_3;
  expected_4[1] = letter_2;
  expected_4[2] = letter_1;
  add_to_list(alphabets, letter_1);
  add_to_list(alphabets, letter_2);
  add_to_list(alphabets, letter_3);
  List_ptr actual_4 = reverse(alphabets);
  char message_4[] = "should reverse the numbers for more than one element given";
  display_assertion(assert_list(actual_4, expected_4, 3, &assert_char), message_4);
  destroy_list(alphabets);
}

void test_create_list(void)
{
  printf("create_list\n");

  List_ptr list = create_list();
  char msg[] = "should create a list with length 0";
  display_assertion(list->first == NULL && list->last == NULL && list->length == 0, msg);
  destroy_list(list);
}

void test_forEach(void)
{
  printf("forEach\n");

  List_ptr list_1 = create_list();
  Element expected_1[0];
  forEach(list_1, &modify_to_zero);
  char msg_1[] = "should iterate on empty list";
  display_assertion(assert_list(list_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(5);
  Element expected_2[1];
  expected_2[0] = create_int(0);
  add_to_list(list_2, number_2_1);
  forEach(list_2, &modify_to_zero);
  char msg_2[] = "should iterate on single element";
  display_assertion(assert_list(list_2, expected_2, 1, &assert_int), msg_2);
  destroy_list(list_2);
  free(expected_2[0]);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(5);
  Element number_3_2 = create_int(6);
  Element expected_3[2];
  Element zero = create_int(0);
  expected_3[0] = zero;
  expected_3[1] = zero;
  add_to_list(list_3, number_3_1);
  add_to_list(list_3, number_3_2);
  forEach(list_3, &modify_to_zero);
  char msg_3[] = "should iterate on single element";
  display_assertion(assert_list(list_3, expected_3, 2, &assert_int), msg_3);
  destroy_list(list_2);
  free(expected_3[0]);
}

void test_clear_list(void)
{
  printf("clear_list\n");
  Status status;
  Status assertion_status;

  List_ptr list_1 = create_list();
  Element expected_1[0];
  status = clear_list(list_1);
  assertion_status = assert_status(status, Failure);
  char msg_1[] = "should give Failure status for empty list";
  display_assertion(assertion_status && assert_list(list_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_1 = create_int(1);
  Element number_2 = create_int(2);
  Element number_3 = create_int(3);
  add_to_list(list_2, number_1);
  add_to_list(list_2, number_2);
  add_to_list(list_2, number_3);
  Element expected_2[0];
  status = clear_list(list_2);
  assertion_status = assert_status(status, Success);
  char msg_2[] = "should give Success for clearing the elements";
  display_assertion(assertion_status && assert_list(list_2, expected_2, 0, &assert_int), msg_2);
  destroy_list(list_2);
}

void test_remove_from_start(void)
{
  printf("remove_from_start\n");
  Element element;

  List_ptr list_1 = create_list();
  Element expected_1[0];
  element = remove_from_start(list_1);
  char msg_1[] = "should give NULL for empty list";
  display_assertion(element == NULL && assert_list(list_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(5);
  add_to_list(list_2, number_2_1);
  Element expected_2[0];
  element = remove_from_start(list_2);
  char msg_2[] = "should give removed element from start for one element given";
  display_assertion(assert_int(element, number_2_1) && assert_list(list_2, expected_2, 0, &assert_int), msg_2);
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(5);
  Element number_3_2 = create_int(6);
  add_to_list(list_3, number_3_1);
  add_to_list(list_3, number_3_2);
  Element expected_3[1];
  expected_3[0] = number_3_2;
  element = remove_from_start(list_3);
  char msg_3[] = "should give removed element from start for more than one element given";
  display_assertion(assert_int(element, number_3_1) && assert_list(list_3, expected_3, 1, &assert_int), msg_3);
  destroy_list(list_3);
}

void test_remove_from_end(void)
{
  printf("remove_from_end\n");
  Element elem;

  List_ptr list_1 = create_list();
  Element expected_1[0];
  elem = remove_from_end(list_1);
  char msg_1[] = "should give NULL for empty list given";
  display_assertion(elem == NULL && assert_list(list_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(5);
  Element expected_2[0];
  add_to_list(list_2, number_2_1);
  elem = remove_from_end(list_2);
  char msg_2[] = "should give element removed from end for one element given";
  display_assertion(assert_int(elem, number_2_1) && assert_list(list_2, expected_2, 0, &assert_int), msg_2);
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(5);
  Element number_3_2 = create_int(6);
  Element expected_3[1];
  expected_3[0] = number_3_1;
  add_to_list(list_3, number_3_1);
  add_to_list(list_3, number_3_2);
  elem = remove_from_end(list_3);
  char msg_3[] = "should give element removed from end for more than one element given";
  display_assertion(assert_int(elem, number_3_2) && assert_list(list_3, expected_3, 1, &assert_int), msg_3);
  destroy_list(list_3);
}

void test_map(void)
{
  printf("map\n");

  List_ptr list_1 = create_list();
  Element expected_1[0];
  List_ptr actual_1 = map(list_1, &square);
  char msg_1[] = "should give empty list for empty list given";
  display_assertion(assert_list(actual_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);
  destroy_list(actual_1);

  List_ptr list_2 = create_list();
  Element number_1 = create_int(5);
  Element number_2 = create_int(6);
  Element expected_2[2];
  expected_2[0] = create_int(25);
  expected_2[1] = create_int(36);
  add_to_list(list_2, number_1);
  add_to_list(list_2, number_2);
  List_ptr actual_2 = map(list_2, &square);
  char msg_2[] = "should give squares of the numbers given";
  display_assertion(assert_list(actual_2, expected_2, 2, &assert_int), msg_2);
  destroy_list(list_2);
  destroy_list(actual_2);
  free(expected_2[0]);
  free(expected_2[1]);

  List_ptr list_3 = create_list();
  Element letter_1 = create_char('A');
  Element letter_2 = create_char('B');
  Element expected_3[2];
  expected_3[0] = create_char('a');
  expected_3[1] = create_char('b');
  add_to_list(list_3, letter_1);
  add_to_list(list_3, letter_2);
  List_ptr actual_3 = map(list_3, &convert_to_lowercase);
  char msg_3[] = "should give lowercase letters for given uppercase";
  display_assertion(assert_list(actual_3, expected_3, 2, &assert_char), msg_3);
  destroy_list(list_3);
  destroy_list(actual_3);
  free(expected_3[0]);
  free(expected_3[1]);
}

void test_insert_at(void)
{
  printf("insert_at\n");
  Status status;

  List_ptr list_1 = create_list();
  Element number_1_1 = create_int(1);
  Element expected_1[1];
  expected_1[0] = number_1_1;
  status = insert_at(list_1, number_1_1, 0);
  char msg_1[] = "should insert at 0 when the list is empty";
  display_assertion(assert_status(status, Success) && assert_list(list_1, expected_1, 1, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(1);
  Element expected_2[0];
  status = insert_at(list_2, number_2_1, 1);
  char msg_2[] = "should not insert at any other position other than 0 when list is empty";
  display_assertion(assert_status(status, Failure) && assert_list(list_2, expected_2, 0, &assert_int), msg_2);
  destroy_list(list_2);
  free(number_2_1);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(1);
  Element number_3_2 = create_int(2);
  Element number_3_3 = create_int(3);
  Element expected_3[3];
  expected_3[0] = number_3_1;
  expected_3[1] = number_3_2;
  expected_3[2] = number_3_3;
  add_to_list(list_3, number_3_1);
  add_to_list(list_3, number_3_2);
  status = insert_at(list_3, number_3_3, 2);
  char msg_3[] = "should insert at last index in the list";
  display_assertion(assert_status(status, Success) && assert_list(list_3, expected_3, 3, &assert_int), msg_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element number_4_1 = create_int(1);
  Element number_4_2 = create_int(2);
  Element number_4_3 = create_int(3);
  Element expected_4[3];
  expected_4[0] = number_4_1;
  expected_4[1] = number_4_3;
  expected_4[2] = number_4_2;
  add_to_list(list_4, number_4_1);
  add_to_list(list_4, number_4_2);
  status = insert_at(list_4, number_4_3, 1);
  char msg_4[] = "should insert in the middle of the list";
  display_assertion(assert_status(status, Success) && assert_list(list_4, expected_4, 3, &assert_int), msg_4);
  destroy_list(list_4);

  List_ptr list_5 = create_list();
  Element number_5_1 = create_int(1);
  Element number_5_2 = create_int(2);
  Element number_5_3 = create_int(3);
  Element expected_5[3];
  expected_5[0] = number_5_1;
  expected_5[1] = number_5_2;
  add_to_list(list_5, number_5_1);
  add_to_list(list_5, number_5_2);
  status = insert_at(list_5, number_5_3, 3);
  char msg_5[] = "should not insert at invalid position in the list";
  display_assertion(assert_status(status, Failure) && assert_list(list_5, expected_5, 2, &assert_int), msg_5);
  destroy_list(list_5);
  free(number_5_3);

  List_ptr list_6 = create_list();
  Element letter = create_char('a');
  Element expected_6[1];
  expected_6[0] = letter;
  status = insert_at(list_6, letter, 0);
  char msg_6[] = "should insert a character to the list";
  display_assertion(assert_status(status, Success) && assert_list(list_6, expected_6, 1, &assert_char), msg_6);
  destroy_list(list_6);
}

void test_remove_at(void)
{
  printf("remove_at\n");
  Element element;

  List_ptr list_1 = create_list();
  Element expected_1[0];
  element = remove_at(list_1, 0);
  char msg_1[] = "should give element NULL for any position to remove when list is empty";
  display_assertion(element == NULL && assert_list(list_1, expected_1, 0, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2_1 = create_int(1);
  Element expected_2[0];
  add_to_list(list_2, number_2_1);
  element = remove_at(list_2, 0);
  char msg_2[] = "should remove element at position 0;";
  display_assertion(assert_int(element, number_2_1) && assert_list(list_2, expected_2, 0, &assert_int), msg_2);
  destroy_list(list_2);

  List_ptr list_3 = create_list();
  Element number_3_1 = create_int(1);
  Element number_3_2 = create_int(2);
  Element number_3_3 = create_int(3);
  Element expected_3[2];
  expected_3[0] = number_3_1;
  expected_3[1] = number_3_2;
  add_to_list(list_3, number_3_1);
  add_to_list(list_3, number_3_2);
  add_to_list(list_3, number_3_3);
  element = remove_at(list_3, 2);
  char msg_3[] = "should remove last element in the list;";
  display_assertion(assert_int(element, number_3_3) && assert_list(list_3, expected_3, 2, &assert_int), msg_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element number_4_1 = create_int(1);
  Element number_4_2 = create_int(2);
  Element number_4_3 = create_int(3);
  Element expected_4[3];
  expected_4[0] = number_4_1;
  expected_4[1] = number_4_2;
  expected_4[2] = number_4_3;
  add_to_list(list_4, number_4_1);
  add_to_list(list_4, number_4_2);
  add_to_list(list_4, number_4_3);
  element = remove_at(list_4, 5);
  char msg_4[] = "should give NULL for position not in the list";
  display_assertion(element == NULL && assert_list(list_4, expected_4, 3, &assert_int), msg_4);
  destroy_list(list_4);

  List_ptr list_5 = create_list();
  Element number_5_1 = create_int(1);
  Element number_5_2 = create_int(2);
  Element number_5_3 = create_int(3);
  Element expected_5[2];
  expected_5[0] = number_5_1;
  expected_5[1] = number_5_3;
  add_to_list(list_5, number_5_1);
  add_to_list(list_5, number_5_2);
  add_to_list(list_5, number_5_3);
  element = remove_at(list_5, 1);
  char msg_5[] = "should remove element from the middle of the list";
  display_assertion(assert_int(element, number_5_2) && assert_list(list_5, expected_5, 2, &assert_int), msg_5);
  destroy_list(list_5);
}

void test_add_unique(void)
{
  printf("add_unique\n");
  Status status;

  List_ptr list_1 = create_list();
  Element number_1 = create_int(1);
  Element expected_1[1];
  expected_1[0] = number_1;
  status = add_unique(list_1, number_1, &is_int_equal);
  char msg_1[] = "should add any number when list is empty";
  display_assertion(assert_status(status, Success) && assert_list(list_1, expected_1, 1, &assert_int), msg_1);
  destroy_list(list_1);

  List_ptr list_2 = create_list();
  Element number_2 = create_int(1);
  Element number_3 = create_int(1);
  Element expected_2[1];
  expected_2[0] = number_2;
  add_unique(list_2, number_2, &is_int_equal);
  status = add_unique(list_2, number_3, &is_int_equal);
  char msg_2[] = "should not add a number to list when already in the list";
  display_assertion(assert_status(status, Failure) && assert_list(list_2, expected_2, 1, &assert_int), msg_2);
  destroy_list(list_2);
  free(number_3);

  List_ptr list_3 = create_list();
  Element number_4 = create_int(1);
  Element number_5 = create_int(2);
  Element expected_3[2];
  expected_3[0] = number_4;
  expected_3[1] = number_5;
  add_unique(list_3, number_4, &is_int_equal);
  status = add_unique(list_3, number_5, &is_int_equal);
  char msg_3[] = "should add a number to list when it isn't already in the list";
  display_assertion(assert_status(status, Success) && assert_list(list_3, expected_3, 2, &assert_int), msg_3);
  destroy_list(list_3);

  List_ptr list_4 = create_list();
  Element letter_1 = create_char('a');
  Element letter_2 = create_char('b');
  Element expected_4[2];
  expected_4[0] = letter_1;
  expected_4[1] = letter_2;
  add_unique(list_4, letter_1, &is_int_equal);
  status = add_unique(list_4, letter_2, &is_int_equal);
  char msg_4[] = "should add a char to list when it isn't already in the list";
  display_assertion(assert_status(status, Success) && assert_list(list_4, expected_4, 2, &assert_int), msg_4);
  destroy_list(list_4);

  List_ptr list_5 = create_list();
  Element letter_3 = create_char('a');
  Element letter_4 = create_char('a');
  Element expected_5[1];
  expected_5[0] = letter_3;
  add_unique(list_5, letter_3, &is_int_equal);
  status = add_unique(list_5, letter_4, &is_int_equal);
  char msg_5[] = "shouldn't add a char to list when it already in the list";
  display_assertion(assert_status(status, Failure) && assert_list(list_5, expected_5, 1, &assert_int), msg_5);
  destroy_list(list_5);
}

int main(void)
{
  test_create_list();
  test_add_to_list();
  test_add_to_start();
  test_reverse();
  test_forEach();
  test_clear_list();
  test_remove_from_start();
  test_remove_from_end();
  test_insert_at();
  test_map();
  test_remove_at();
  test_add_unique();
  display_passing_count();
  return 0;
}