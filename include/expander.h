#ifndef EXPANDER_H
# define EXPANDER_H

# include "env.h"      // pour t_env
# include "lexer.h"  // pour t_token

char *expand_word(const char *word, t_env *env);
void expand_variables(t_token *tokens, t_env *env);

#endif

