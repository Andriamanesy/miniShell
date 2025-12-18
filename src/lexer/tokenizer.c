/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:02 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 13:34:06 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"
#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../include/expander.h"

/*
static char *expand_variable(char *word, char **envp)
{
    if (!word || word[0] != '$')
        return ft_strdup(word);

    // $?
    if (ft_strcmp(word, "$?") == 0)
        return ft_itoa(g_last_exit_code); // à définir globalement dans minishell

    char *var_name = word + 1; // skip $
    int i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0
            && envp[i][ft_strlen(var_name)] == '=')
        {
            return ft_strdup(envp[i] + ft_strlen(var_name) + 1);
        }
        i++;
    }
    return ft_strdup(""); // variable non trouvée
}*/
#include "../../include/lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// parse_quotes : extrait le contenu d'une quote et applique expand_word si nécessaire
#include "../../include/lexer.h"
#include "../../include/expander.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

char *parse_quotes(char *s, int *i, t_env *env)
{
    char quote = s[*i]; // ' ou "
    char *tmp;
    char *result;

    (*i)++; // sauter la quote ouvrante
    int start = *i;

    // Trouver quote fermante
    while (s[*i] && s[*i] != quote)
        (*i)++;

    if (!s[*i])
    {
        ft_putstr_fd("Error: unclosed quote\n", 2);
        return NULL;
    }

    // Extraire le contenu entre quotes
    tmp = ft_substr(s, start, *i - start);
    if (!tmp)
        return NULL;

    // Expansion seulement pour doubles quotes
    if (quote == '"')
    {
        result = expand_word(tmp, env);
        free(tmp);
        if (!result)
            return NULL;
    }
    else
    {
        // simple quote, pas d'expansion
        result = tmp;
    }

    (*i)++; // passer la quote fermante

    // Gestion de segments adjacents de quotes ou texte non quote
    while (s[*i] && s[*i] != ' ' && s[*i] != '|' && s[*i] != '<' && s[*i] != '>')
    {
        char *next_seg;
        if (s[*i] == '"' || s[*i] == '\'')
        {
            next_seg = parse_quotes(s, i, env);
            if (!next_seg)
            {
                free(result);
                return NULL;
            }
        }
        else
        {
            int seg_start = *i;
            while (s[*i] && s[*i] != '"' && s[*i] != '\'' && s[*i] != ' ' && s[*i] != '|' && s[*i] != '<' && s[*i] != '>')
                (*i)++;
            next_seg = ft_substr(s, seg_start, *i - seg_start);
        }
        char *new_result = ft_strjoin(result, next_seg);
        free(result);
        free(next_seg);
        result = new_result;
    }

    return result;
}


#include "../../include/lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_token *tokenize(char *s, t_env *env)
{
    t_token *list = NULL;
    int i = 0;
    char *word;
    int start;

    while (s[i])
    {
        if (is_whitespace(s[i]))
            i++;
        else if (s[i] == '\'' || s[i] == '"')
        {
            word = parse_quotes(s, &i, env);
            if (!word)
            {
                free_tokens(list);
                return NULL;
            }
            token_add_back(&list, new_token(word, WORD));
            free(word);
        }
        else if (s[i] == '|')
        {
            token_add_back(&list, new_token("|", PIPE));
            i++;
        }
        else if (s[i] == '>')
        {
            if (s[i + 1] == '>')
                token_add_back(&list, new_token(">>", REDIR_OUT_APPEND)), i += 2;
            else
                token_add_back(&list, new_token(">", REDIR_OUT)), i++;
        }
        else if (s[i] == '<')
        {
            if (s[i + 1] == '<')
                token_add_back(&list, new_token("<<", HEREDOC)), i += 2;
            else
                token_add_back(&list, new_token("<", REDIR_IN)), i++;
        }
        else
        {
            start = i;
            while (s[i] && !is_whitespace(s[i]) && !is_operator_char(s[i]) && s[i] != '\'' && s[i] != '"')
                i++;
            word = ft_substr(s, start, i - start);
            if (!word)
            {
                free_tokens(list);
                return NULL;
            }
            token_add_back(&list, new_token(word, WORD));
            free(word);
        }
    }
    return list;
}

