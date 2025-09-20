/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:36:16 by kingstephan       #+#    #+#             */
/*   Updated: 2025/09/13 17:29:23 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
int g_exit_code = 0;

int	main(void)
{
	char		*line;
	t_token		*tokens;
	t_command	*cmd_list;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break;
		if (*line)
			add_history(line);

		tokens = convert_line_to_tokens(line);
		if (!tokens)
		{
			ft_putendl_fd("Lexing failed: invalid input", 2);
			free(line);
			continue;
		}

		// Nouvelle vérification ici
		else if (!is_valid_line(line, tokens))
		{
			free_token(tokens);
			free(line);
			continue;
		}

		//Parsing uniquement si la ligne est valide
		else
		{
			cmd_list = parsing_cmds(&tokens);
			print_all_cmds(cmd_list);

			print_tokens(tokens); // facultatif
			free_token(tokens);
			free_cmd_list(cmd_list);
			free(line);
		}
	}
	return (0);
}
