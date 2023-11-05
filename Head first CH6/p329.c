#include <stdio.h>
#include <stdlib.h>

island *start = NULL;
island *i = NULL;
island *next = NULL;
char name[80];
for (; fget(name, 80, stdin) != NULL; i=next)
{
    next =creat(name);
    if(start == NULL)
        start = next;
    if (i != NULL)
        i->next=next;
}
display(start);
