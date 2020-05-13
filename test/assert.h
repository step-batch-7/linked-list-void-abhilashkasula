#include "../linkedlist.h"

#ifndef __ASSERT_H
#define __ASSERT_H

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PASS GREEN " \u2714 " RESET
#define FAIL RED " \u2718 " RESET

typedef Status (*Assert_element)(Element, Element);

Status assert_list(List_ptr, Element *, int, Assert_element);
void display_assertion(Status, char *);
void display_passing_count(void);

#endif
