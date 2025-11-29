/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:02 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:26:16 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"

t_token *tokenize(char *s)
{
    t_token *list = NULL;
    int     i = 0;

    while (s[i])
    {
        if (is_whitespace(s[i]))
        {
            i++;
            continue;
        }
        if (s[i] == '\'' || s[i] == '"')
        {
            char *word = parse_quotes(s, &i);
            token_add_back(&list, new_token(word, WORD));
            free(word);
            continue;
        }
        if (s[i] == '|')
        {
            token_add_back(&list, new_token(ft_strdup("|"), PIPE));
            i++;
            continue;
        }
        if (s[i] == '>')
        {
            if (s[i + 1] == '>')
            {
                token_add_back(&list, new_token(ft_strdup(">>"), REDIR_OUT_APPEND));
                i += 2;
            }
            else
            {
                token_add_back(&list, new_token(ft_strdup(">"), REDIR_OUT));
                i++;
            }
            continue;
        }
        if (s[i] == '<')
        {
            if (s[i + 1] == '<')
            {
                token_add_back(&list, new_token(ft_strdup("<<"), HEREDOC));
                i += 2;
            }
            else
            {
                token_add_back(&list, new_token(ft_strdup("<"), REDIR_IN));
                i++;
            }
            continue;
        }

        /* Normal WORD */
        int start = i;
        while (s[i] && !is_whitespace(s[i]) && !is_operator_char(s[i]))
            i++;

        char *word = ft_substr(s, start, i - start);
        token_add_back(&list, new_token(word, WORD));
        free(word);
    }
    return list;
}

