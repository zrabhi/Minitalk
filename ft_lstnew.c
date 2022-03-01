#include "libft.h"

t_list  *ft_lstnew(void *content)
{
}
    t_list  *new;

    new = malloc(sizeof(t_list));
    new->content = content;
    new->next = NULL;
    return(new); 
/*int main()
{
    t_list *new;

    new = ft_lstnew("ZAC");
    printf("%s", new->content);
}*/
