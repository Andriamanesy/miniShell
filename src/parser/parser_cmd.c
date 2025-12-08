/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:20 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:49:32 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_ast	*build_command_node(t_token **tokens)
{
	t_token	*cur;
	int		count;
	int		i;
	t_ast	*cmd;
	char	**argv;

	if (!tokens || !*tokens || (*tokens)->type != WORD)
		return (NULL);
	cur = *tokens;
	count = 0;
	while (cur && cur->type == WORD)
	{
		count++;
		cur = cur->next;
	}
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	cur = *tokens;
	i = 0;
	while (i < count && cur)
	{
		argv[i] = ft_strdup(cur->value ? cur->value : "");
		if (!argv[i])
		{
			while (--i >= 0)
				free(argv[i]);
			free(argv);
			return (NULL);
		}
		cur = cur->next;
		i++;
	}
	argv[i] = NULL;
	cmd = new_ast_node(NODE_COMMAND, argv[0]);
	if (!cmd)
	{
		free_argv(argv);
		return (NULL);
	}
	cmd->argv = argv;
	*tokens = cur;
	return (cmd);
}
