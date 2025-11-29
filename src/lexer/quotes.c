/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:58 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:27:40 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"

char *parse_quotes(char *s, int *i)
{
    char quote = s[*i];
    int start = ++(*i);

    while (s[*i] && s[*i] != quote)
        (*i)++;

    char *word = ft_substr(s, start, *i - start);

    if (s[*i] == quote)
        (*i)++;

    return word;
}

