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

List_ptr create_list_from(Element *elements, int length)
{
  List_ptr new_list = create_list();
  for (int i = 0; i < length; i++)
  {
    add_to_list(new_list, elements[i]);
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

Prev_curr_pair *get_prev_curr(List_ptr list, int position)
{
  Prev_curr_pair *prev_curr = malloc(sizeof(Prev_curr_pair));
  prev_curr->prev = NULL;
  prev_curr->curr = list->first;

  for (int i = 0; i < position; i++)
  {
    prev_curr->prev = prev_curr->curr;
    prev_curr->curr = prev_curr->curr->next;
  }

  return prev_curr;
}

Element remove_from_end(List_ptr list)
{
  if (list->first == NULL)
  {
    return list->first;
  }

  Prev_curr_pair *prev_curr = get_prev_curr(list, list->length - 1);
  if (prev_curr->prev == NULL)
  {
    list->first = NULL;
  }
  else
  {
    prev_curr->prev->next = NULL;
  }

  list->last = prev_curr->prev;
  Element removed = prev_curr->curr->element;
  free(prev_curr->curr);
  free(prev_curr);
  list->length--;
  return removed;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    add_to_list(new_list, (*mapper)(p_walk->element));
    p_walk = p_walk->next;
  }

  return new_list;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  Element filtered_elements[list->length];
  int length = 0;
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    if ((*predicate)(p_walk->element))
    {
      filtered_elements[length] = p_walk->element;
      length++;
    }
    p_walk = p_walk->next;
  }

  return create_list_from(filtered_elements, length);
}

Element reduce(List_ptr list, Element context, Reducer reducer)
{
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    context = (*reducer)(context, p_walk->element);
    p_walk = p_walk->next;
  }

  return context;
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

Status is_exists(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr p_walk = list->first;
  Status exist_status = Failure;

  while (p_walk != NULL)
  {
    if ((*matcher)(element, p_walk->element))
    {
      exist_status = Success;
    }
    p_walk = p_walk->next;
  }

  return exist_status;
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
  return !is_exists(list, element, matcher) && add_to_list(list, element);
}

Status insert_at(List_ptr list, Element element, int position)
{
  if (position < 0 || position > list->length)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }
  if (position == list->length)
  {
    return add_to_list(list, element);
  }

  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
  {
    return Failure;
  }

  Prev_curr_pair *prev_curr = get_prev_curr(list, position);
  new_node->next = prev_curr->curr;
  prev_curr->prev->next = new_node;
  list->length++;

  return Success;
}
