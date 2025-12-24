/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:25 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 01:22:21 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include "../../include/utils.h"
#include "../../include/expander.h"
#include "../../include/lexer.h"
#include "../../include/debug.h"

static bool	fill_cmd(t_data *data, t_token *tmp)
{
	if (!get_infile(data, tmp, data->cmd->prev) && \
		data->cmd->prev->infile != -1)
		return (false);
	if (data->cmd->prev->infile == -1)
	{
		data->cmd->prev->skip_cmd = true;
		data->cmd->prev->outfile = -1;
		return (true);
	}
	if (!get_outfile(tmp, data->cmd->prev, data) && data->cmd->prev->outfile \
		!= -1)
		return (false);
	if (data->cmd->prev->outfile == -1)
	{
		if (data->cmd->prev->infile >= 0)
			close (data->cmd->prev->infile);
		data->cmd->prev->skip_cmd = true;
		data->cmd->prev->infile = -1;
		return (true);
	}
	data->cmd->prev->cmd_param = get_param(data, tmp);
	if (!data->cmd->prev->cmd_param)
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	return (true);
}

static bool	norm(t_data *data, t_token *tmp)
{
	if (!append_cmd(&data->cmd, -2, -2, NULL))
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	if (!fill_cmd(data, tmp))
	{
		data->exit_code = 2;
		return (false);
	}
	return (true);
}

bool	create_list_cmd(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!norm(data, tmp))
		return (false);
	tmp = tmp->next;
	while (tmp != data->token)
	{
		if (tmp->prev->type == PIPE)
		{
			if (!norm(data, tmp))
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

bool	parseline(t_data *data, char *line)
{
	if (open_quote(data, line))
	{
		free(line);
		return (false);
	}
	if (!replace_dollar(&line, data) || !create_list_token(&data->token, line))
	{
		free(line);
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	}
	free(line);
	print_token(data->token);
	if (data->token && data->token->prev->type == PIPE)
	{
		write(2, "Error: Unclosed pipe\n", 21);
		data->exit_code = 2;
		free_token(&data->token);
		return (false);
	}
	if (!data->token || !create_list_cmd(data))
	{
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (false);
	}
	return (check_pipe(data));
}
