/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:58 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 13:32:24 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"
#include "../../include/expander.h"

char *clear_quotes(char *s)
{
    int i = 0, j = 0;
    char *res = malloc(strlen(s) + 1);
    if (!res)
        return NULL;
    while (s[i])
    {
        if (s[i] != '"' && s[i] != '\'')
            res[j++] = s[i];
        i++;
    }
    res[j] = '\0';
    return res;
}

void clear_quotes_in_tokens(t_token *tokens)
{
    t_token *cur = tokens;
    char *tmp;

    while (cur)
    {
        if (cur->type == WORD)
        {
            tmp = clear_quotes(cur->value);
            free(cur->value);
            cur->value = tmp;
        }
        cur = cur->next;
    }
}

char *ft_strjoin_free(char *s1, char *s2)
{
    char *res = ft_strjoin(s1, s2);
    free(s1);
    return res;
}


