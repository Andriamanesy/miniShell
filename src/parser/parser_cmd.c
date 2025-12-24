/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:20 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:28:58 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include "../../include/lexer.h"
#include "../../include/utils.h"

static int	count_args(t_data *data, t_token *token)
{
	int		count;
	t_token	*tmp;

	count = 0;
	tmp = token;
	if (tmp->type == CMD || (tmp->type == ARG && \
		tmp->prev != data->token->prev && tmp->prev->type > 5))
		count ++;
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if (tmp->type == CMD || (tmp->type == ARG && \
		tmp->prev != data->token->prev && tmp->prev->type > 5))
			count ++;
		tmp = tmp->next;
	}
	return (count);
}

static int	add_to_cmd_param(char **cmd_param, int *i, char *str)
{
	cmd_param[*i] = ft_strdup(str);
	if (!cmd_param[*i])
		return (0);
	(*i)++;
	return (1);
}

static void	*free_cmd_param(char **cmd, int i)
{
	while (--i != -1)
		free(cmd[i]);
	free(cmd);
	return (NULL);
}

char	**get_param(t_data *data, t_token *token)
{
	char	**cmd_param;
	int		i;
	t_token	*tmp;

	i = 0;
	cmd_param = malloc(sizeof(char *) * (count_args(data, token) + 1));
	if (cmd_param == NULL)
		return (NULL);
	tmp = token;
	if (tmp->type != PIPE && (tmp->type == CMD || (tmp->type == ARG && \
		tmp->prev != data->token->prev && tmp->prev->type > 5)) && \
		!add_to_cmd_param(cmd_param, &i, tmp->str))
		return (free_cmd_param(cmd_param, i));
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if ((tmp->type == CMD || (tmp->type == ARG && \
			tmp->prev != data->token->prev && tmp->prev->type > 5)) && \
			!add_to_cmd_param(cmd_param, &i, tmp->str))
			return (free_cmd_param(cmd_param, i));
		tmp = tmp->next;
	}
	cmd_param[i] = NULL;
	return (cmd_param);
}

static int	cmd_new_elem(t_cmd **new, int infile, int outfile, char **cmd_param)
{
	(*new) = malloc(sizeof(t_cmd));
	if (*new == NULL)
		return (0);
	(*new)->skip_cmd = false;
	(*new)->infile = infile;
	(*new)->outfile = outfile;
	(*new)->cmd_param = cmd_param;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

int	append_cmd(t_cmd **list, int infile, int outfile, char **cmd_param)
{
	t_cmd	*new;

	if (!cmd_new_elem(&new, infile, outfile, cmd_param))
		return (0);
	if (!(*list))
	{
		(*list) = new;
		(*list)->prev = *list;
		(*list)->next = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}

static void	free_all_cmd(t_cmd *tmp)
{
	if (tmp->infile > 0)
		close(tmp->infile);
	tmp->infile = -2;
	if (tmp->outfile > 0)
		close(tmp->outfile);
	tmp->outfile = -2;
	free_array(tmp->cmd_param);
}

void	free_cmd(t_cmd **list)
{
	t_cmd	*tmp;
	t_cmd	*current;

	if (!(*list))
		return ;
	current = *list;
	while (current->next != *list)
	{
		tmp = current;
		current = current->next;
		free_all_cmd(tmp);
		free(tmp);
	}
	free_all_cmd(current);
	free(current);
	*list = NULL;
}

size_t	len_cmd(t_cmd *list)
{
	t_cmd	*tmp;
	size_t	i;

	if ((list))
	{
		tmp = list;
		i = 1;
		while (tmp->next != list)
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}

