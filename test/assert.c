#include "assert.h"

int tests_passing = 0;
int tests_failing = 0;

Status assert_list(List_ptr list, Element *list_2, int length, Status (*assert)(Element, Element))
{
  if (length != list->length)
  {
    return Failure;
  }

  Node_ptr p_walk = list->first;
  Status assertion_status = Success;

  for (int i = 0; i < list->length; i++)
  {
    assertion_status &= assert(p_walk->element, list_2[i]);
    p_walk = p_walk->next;
  }

  return assertion_status;
}

void display_assertion(Status assertion_status, char *message)
{
  if (assertion_status)
  {
    printf(PASS);
    tests_passing++;
  }
  else
  {
    printf(FAIL);
    tests_failing++;
  }

  printf("%s\n", message);
}

void display_passing_count(void)
{
  printf(GREEN "\n%d passing" RESET, tests_passing);
  printf(RED "\n%d failing" RESET, tests_failing);
}
