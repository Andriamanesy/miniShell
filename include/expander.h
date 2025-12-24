#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

void	quoting_choice(bool *dq, bool *sq, int *index, char c);
int		open_quote(t_data *data, char *line);

char	*get_dollar_word(char *line, int size);
int		add_dollar(char *line, int *index, char **str, t_data *data);
int		add_char(char *c, char **str, t_data *data, int *index);
int		replace_dollar(char **line, t_data *data);
int		here_doc(t_data *data, char *word);

#endif

