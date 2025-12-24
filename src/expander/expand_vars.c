/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:47:53 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:21:12 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/expander.h"
#include "../../include/env.h"

static int	in_env(t_data *data, char *line, int size, char **str)
{
	char	*tmp;
	char	*key;
	char	*value;

	key = get_dollar_word(line, size);
	value = get_elem_env(data->env, key);
	if (key)
		free(key);
	tmp = ft_strjoin(*str, value);
	if (value)
		free(value);
	free(*str);
	if (!tmp)
		return (0);
	*str = tmp;
	return (1);
}

static int	dollar_point_interrogation(t_data *data, char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(data->exit_code);
	if (!tmp)
		return (0);
	tmp2 = ft_strjoin(*str, tmp);
	free(tmp);
	free(*str);
	if (!tmp2)
		return (0);
	*str = tmp2;
	return (1);
}

int	add_dollar(char *line, int *index, char **str, t_data *data)
{
	int		ctrl;
	int		n;

	n = *index;
	ctrl = exist_in_env(line, index, data);
	if (ctrl == 1)
		return (in_env(data, &line[n], *index - n, str));
	else if (ctrl == 2)
	{
		(*index) += 2;
		return (dollar_point_interrogation(data, str));
	}
	else
	{
		++(*index);
		while (line[*index] && \
			(ft_isalnum(line[*index]) || line[*index] == '_'))
			++(*index);
		return (1);
	}
}

char	*get_dollar_word(char *line, int size)
{
	char	*dollar;
	int		i;

	dollar = malloc(sizeof(char) * size);
	if (!dollar)
		return (NULL);
	i = 0;
	while (line[++i] && i < size)
		dollar[i - 1] = line[i];
	dollar[i - 1] = '\0';
	return (dollar);
}

