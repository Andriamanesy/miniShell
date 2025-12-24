/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:38:49 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 03:00:05 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include "../include/env.h"
#include "../include/utils.h"
#include "../include/parser.h"
#include "../include/lexer.h"
#include "../include/executor.h"

pid_t	g_signal_pid = 0;

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*line;

	init_data(&data, argc, argv);
	if (!make_env(&data, env))
		free_all(&data, ERR_MALLOC, EXT_MALLOC);
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			free_all(&data, "exit\n", data.exit_code);
		if (empty_line(line))
			continue ;
		add_history(line);
		if (!parseline(&data, line))
			continue ;
		if (!exec(&data))
			free_all(&data, ERR_PIPE, EXT_PIPE);
		free_cmd(&data.cmd);
		free_token(&data.token);
		g_signal_pid = 0;
	}
	rl_clear_history();
	free_all(&data, NULL, -1);
	return (0);
}


