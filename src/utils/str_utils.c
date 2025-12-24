/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:04:25 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 03:49:00 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/lexer.h"

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
	{
		free(line);
		return (true);
	}
	return (false);
}
