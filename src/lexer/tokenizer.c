/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:02 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 13:34:06 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"
t_token	*tokenize(char *s)
{
	t_token	*list;
	int		i;
	int		start;
	char	*word;

	list = NULL;
	i = 0;
	while (s[i])
	{
		if (is_whitespace(s[i]))
			i++;
		else if (s[i] == '\'' || s[i] == '"')
		{
			word = parse_quotes(s, &i);
			if (!word)
				return (free_tokens(list), NULL);
			token_add_back(&list, new_token(word, WORD));
			free(word);
		}
		else if (s[i] == '|')
		{
			token_add_back(&list, new_token("|", PIPE));
			i++;
		}
		else if (s[i] == '>')
		{
			if (s[i + 1] && s[i + 1] == '>')
				token_add_back(&list, new_token(">>", REDIR_OUT_APPEND)), i += 2;
			else
				token_add_back(&list, new_token(">", REDIR_OUT)), i++;
		}
		else if (s[i] == '<')
		{
			if (s[i + 1] && s[i + 1] == '<')
				token_add_back(&list, new_token("<<", HEREDOC)), i += 2;
			else
				token_add_back(&list, new_token("<", REDIR_IN)), i++;
		}
		else
		{
			start = i;
			while (s[i] && !is_whitespace(s[i]) && !is_operator_char(s[i]))
				i++;
			word = ft_substr(s, start, i - start);
			if (!word)
				return (free_tokens(list), NULL);
			token_add_back(&list, new_token(word, WORD));
			free(word);
		}
	}
	return (list);
}