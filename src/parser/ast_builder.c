/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:42:41 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:48:28 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include "../../include/parser.h"
#include <stdio.h>

t_ast *build_ast(t_token *tokens)
{
    t_ast *root = NULL;
    t_ast *current_cmd = NULL;
    t_ast *node;
    t_ast *redir_node;

    while (tokens)
    {
        if (tokens->type == WORD)
        {
            node = build_command_node(&tokens);
            if (!node)
                return (free_ast(root), NULL);

            if (!root)
                root = current_cmd = node;
            else if (current_cmd->type == NODE_PIPE)
                current_cmd->right = node, current_cmd = node;
            else
            {
                current_cmd->right = node;
                current_cmd = node;
            }
        }
        else if (is_redir_token(tokens->type))
        {
            redir_node = parse_redirection(&tokens);
            if (!redir_node || !current_cmd)
            {
                free_ast(root);
                return NULL;
            }
            // Attache la redirection à la commande courante
            if (!current_cmd->redir)
                current_cmd->redir = redir_node;
            else
            {
                t_ast *tmp = current_cmd->redir;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = redir_node;
            }
        }
        else if (tokens->type == PIPE)
        {
            if (!current_cmd)
            {
                fprintf(stderr, "minishell: syntax error near '|'\n");
                free_ast(root);
                return NULL;
            }
            node = new_ast_node(NODE_PIPE, NULL);
            node->left = root;
            root = node;
            current_cmd = node;
            tokens = tokens->next;
        }
        else
            tokens = tokens->next;
    }
    return root;
}
