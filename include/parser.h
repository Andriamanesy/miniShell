/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:26 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:52:56 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "env.h"

typedef enum e_node_type
{
    NODE_COMMAND,
    NODE_PIPE,
    NODE_REDIR_OUT,
    NODE_REDIR_OUT_APPEND,
    NODE_REDIR_IN,
    NODE_HEREDOC
}   t_node_type;

typedef struct s_ast
{
    t_node_type     type;
    char           *value;
    struct s_ast   *left;
    struct s_ast   *right;
}   t_ast;

t_ast *parse(t_token *tokens);
t_ast *new_ast_node(t_node_type type, char *value);
void   free_ast(t_ast *ast);
t_ast *build_command_node(t_token **tokens);
t_ast *parse_redirection(t_token **tokens);
t_ast *build_ast(t_token *tokens);
void print_ast(t_ast *ast, int level);

#endif
