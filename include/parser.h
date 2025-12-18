/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:26 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:48:06 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "env.h"
# include "../../libft/includes/libft.h"
# include "lexer.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_token t_token;
typedef enum e_toktype t_toktype;

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIR_OUT,
	NODE_REDIR_OUT_APPEND,
	NODE_REDIR_IN,
	NODE_HEREDOC
}	t_node_type;

typedef struct s_ast
{
	t_node_type	type;
	char		*value;
	char		**argv;
	struct s_ast	*left;
	struct s_ast	*right;
	struct s_ast	*redir;
}	t_ast;

t_ast				*parse(t_token *tokens);
t_ast				*new_ast_node(t_node_type type, const char *value);
void				free_ast(t_ast *ast);
t_ast				*build_command_node(t_token **tokens);
t_ast				*parse_redirection(t_token **tokens);
t_ast				*build_ast(t_token *tokens);
void				print_ast(t_ast *ast, int level);
int				is_redir_token(t_toktype type);
void				free_argv(char **argv);

#endif
