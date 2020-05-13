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

Status clear_list(List_ptr list)
{
  Status is_list_cleared = Failure;

  while (list->first != NULL)
  {
    Element elem = remove_from_start(list);
    free(elem);
    is_list_cleared = Success;
  }

  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return is_list_cleared;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
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

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
  {
    return Failure;
  }
  if (list->first == NULL)
  {
    list->last = new_node;
  }

  new_node->next = list->first;
  list->first = new_node;
  list->length++;

  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }

  return reversed_list;
}

Element remove_from_start(List_ptr list)
{
  if (list->first == NULL)
  {
    return list->first;
  }
  if (list->first->next == NULL)
  {
    list->last = NULL;
  }

  Node_ptr ptr_to_free = list->first;
  Element removed = list->first->element;
  list->first = list->first->next;
  free(ptr_to_free);
  list->length--;

  return removed;
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
