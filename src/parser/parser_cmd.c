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

#include "../../include/parser.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>

t_ast *build_command_node(t_token **tokens)
{
    t_token *cur;
    int count = 0, i;
    t_ast *cmd;
    char **argv;

    if (!tokens || !*tokens || (*tokens)->type != WORD)
        return NULL;

    cur = *tokens;
    while (cur && cur->type == WORD)
        count++, cur = cur->next;

    argv = malloc(sizeof(char *) * (count + 1));
    if (!argv)
        return NULL;

    cur = *tokens;
    for (i = 0; i < count; i++, cur = cur->next)
    {
        argv[i] = ft_strdup(cur->value ? cur->value : "");
        if (!argv[i])
        {
            while (--i >= 0) free(argv[i]);
            free(argv);
            return NULL;
        }
    }
    argv[i] = NULL;

    cmd = new_ast_node(NODE_COMMAND, argv[0]);
    if (!cmd)
    {
        free_argv(argv);
        return NULL;
    }
    cmd->argv = argv;
    cmd->redir = NULL; // champ ajouté pour redirections
    *tokens = cur;
    return cmd;
}
