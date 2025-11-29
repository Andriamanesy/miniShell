/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:41:24 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:27:24 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"

t_token *new_token(char *value, t_toktype type)
{
    t_token *tok = malloc(sizeof(t_token));
    if (!tok)
        return NULL;
    tok->value = ft_strdup(value);
    tok->type = type;
    tok->next = NULL;
    return tok;
}

void token_add_back(t_token **lst, t_token *new)
{
    t_token *tmp;

    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void free_tokens(t_token *lst)
{
    t_token *tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst->value);
        free(lst);
        lst = tmp;
    }
}
