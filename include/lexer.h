/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:18 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:21:40 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_toktype
{
	WORD,
	PIPE,
	REDIR_OUT,
	REDIR_OUT_APPEND,
	REDIR_IN,
	HEREDOC
}					t_toktype;

typedef struct s_token
{
	char			*value;
	t_toktype		type;
	struct s_token	*next;
}					t_token;

t_token				*lexer(char *input);
t_token				*tokenize(char *input);
t_token				*new_token(char *value, t_toktype type);
void				token_add_back(t_token **lst, t_token *new_tok);
void				free_tokens(t_token *lst);
int					is_operator_char(char c);
int					is_whitespace(char c);
char				*parse_quotes(char *s, int *i);

#endif
