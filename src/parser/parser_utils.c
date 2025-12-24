/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:44:43 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 01:24:02 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include "../../include/lexer.h"

bool	check_pipe(t_data *data)
{
	if (data->token->type == PIPE)
	{
		write(2, "syntax error near unexpected token '|'\n", 39);
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (false);
	}
	return (true);
}

