/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:47:29 by kingstephan       #+#    #+#             */
/*   Updated: 2025/09/12 16:39:45 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	append_S_quoted(char *line, int *i, char **final_word)
{
	char	*word;
	
	word = extract_S_quoted(line, i);
	if (!word)
		{
			free(*final_word);
			*final_word = NULL;
			return (0);
		}
	*final_word = ft_strjoin_and_free(*final_word, word);
	free(word);
	if (!*final_word)
		return (0);
	return (1);
}
static int	append_D_quoted(char *line, int *i, char **final_word)
{
	char	*word;
	char	*temp;

	temp = extract_D_quoted(line, i);
	if (!temp)
	{
		free(*final_word);
		*final_word = NULL;
		return (0);
	}
	word = expand_variables(temp);
	free(temp);
	if (!word)
	{
		free(*final_word);
		*final_word = NULL;
		return (0);
	}
	*final_word = ft_strjoin_and_free(*final_word, word);
	free(word);
	if (!*final_word)
		return (0);
	return (1);
}
static int	append_unquoted(char *line, int *i, char **final_word)
{
	char	*word;
	char	*temp;

	temp = extract_unquoted(line, i);
	if (!temp)
	{
		free(*final_word);
		*final_word = NULL;
		return (0);
	}
	word = expand_variables(temp);
	free(temp);
	if (!word)
	{
		free(*final_word);
		*final_word = NULL;
		return (0);
	}
	*final_word = ft_strjoin_and_free(*final_word, word);
	free(word);
	if (!*final_word)
		return (0);
	return (1);
}

/*fonction qui collect tous les mots de la ligne de commande
en double et single quote et aussi en dehors des quotes
elle va ensuite extraire les mots et tous les concatener dans
une variable final*/
char	*collect_word(char *line, int *i)
{
	char	*final_word;

	final_word = NULL;
	if (!line || !line[*i] || is_white_space(line[*i])
		|| is_operator(line[*i]))
		return (NULL);
	while (line[*i])
	{
		if (!line[*i] || is_white_space(line[*i]) || is_operator(line[*i]))
			break;
		if (line[*i] == '\'')
		{
			if (!append_S_quoted(line, i, &final_word))
				return (NULL);
		}
		else if (line[*i] == '"')
		{
			if (!append_D_quoted(line, i, &final_word))
				return (NULL);
		}
		else
		{
			if (!append_unquoted(line, i, &final_word))
				return (NULL);
		}
	}
	if (!final_word)
		return (ft_strdup(""));
	return (final_word);
}
