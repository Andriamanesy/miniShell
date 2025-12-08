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

char	*parse_quotes(char *s, int *i)
{
	char	quote;
	int		start;
	char	*word;

	quote = s[*i];
	start = ++(*i);

	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (s[*i] != quote)
		return (NULL);
	word = ft_substr(s, start, *i - start);
	(*i)++;
	return (word);
}
