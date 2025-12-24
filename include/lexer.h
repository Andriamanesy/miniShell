/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:18 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 01:24:59 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
#include "env.h"
#include "parser.h"

# include "minishell.h"

bool	create_list_token(t_token **begin, char *command);
int		append_token(t_token **list, char *str, int type);
void	free_token(t_token **list);
bool	is_space(char c);
int		is_special(char *str);

#endif
