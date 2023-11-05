void release(island *start)
{
    island *i =start;
    island *next = NULL;
    for (; i != NULL; i = next){
        next = i->next;
        free(i->name);
        free(i);
    }
}