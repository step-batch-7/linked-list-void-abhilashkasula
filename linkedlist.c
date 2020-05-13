#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr new_list = malloc(sizeof(LinkedList));

  if (new_list != NULL)
  {
    new_list->first = NULL;
    new_list->last = NULL;
    new_list->length = 0;
  }

  return new_list;
}

Node_ptr create_node(Element element)
{
  Node_ptr new_node = malloc(sizeof(Node));

  if (new_node != NULL)
  {
    new_node->next = NULL;
    new_node->element = element;
  }

  return new_node;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);

  if (new_node == NULL)
  {
    return Failure;
  }

  Node_ptr *ptr_to_set = &list->first;

  if (list->first != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  *ptr_to_set = new_node;
  list->last = new_node;
  list->length++;

  return Success;
}

void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}
