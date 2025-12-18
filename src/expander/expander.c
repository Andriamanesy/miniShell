/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:47:23 by briandri          #+#    #+#             */
/*   Updated: 2025/11/19 07:47:25 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expander.h"
#include "../../include/lexer.h"
#include "../../include/env.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>
#include <string.h>

void expand_variables(t_token *tokens, t_env *env)
{
    t_token *cur = tokens;
    while (cur)
    {
        if (cur->type == WORD)
        {
            char *new_value = expand_word(cur->value, env);
            free(cur->value);
            cur->value = new_value;
        }
        cur = cur->next;
    }
}

// Retourne la valeur de la variable d'env ou chaîne vide si non trouvée
#include "../../include/env.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>

char *expand_word(const char *word, t_env *env)
{
    char *result;
    char *tmp;
    int i;
    int start;

    result = ft_strdup("");
    i = 0;

    while (word[i])
    {
        if (word[i] == '$')
        {
            i++;

            // $?
            if (word[i] == '?')
            {
                tmp = ft_itoa(g_last_exit_code); // malloc
                i++;
            }
            else
            {
                start = i;
                while (word[i] && (ft_isalnum(word[i]) || word[i] == '_'))
                    i++;

                char *var = ft_substr(word, start, i - start); // malloc
                char *env_val = env_get(env, var);             // ❌ PAS malloc
                free(var);

                if (env_val)
                    tmp = ft_strdup(env_val); // malloc
                else
                    tmp = ft_strdup("");      // malloc
            }

            char *new_result = ft_strjoin(result, tmp); // malloc
            free(result);
            free(tmp);
            result = new_result;
        }
        else
        {
            start = i;
            while (word[i] && word[i] != '$')
                i++;

            tmp = ft_substr(word, start, i - start); // malloc
            char *new_result = ft_strjoin(result, tmp);
            free(result);
            free(tmp);
            result = new_result;
        }
    }
    return result;
}


