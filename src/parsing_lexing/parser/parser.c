/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:08:37 by kingstephan       #+#    #+#             */
/*   Updated: 2025/09/13 16:58:04 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_command	*parse_single_command(t_token **token)
{
	t_command	*new_cmd;
	int			i;

	i = 0;
	new_cmd = init_cmd(nb_args(token));
	if (!new_cmd)
		return (NULL);
	while ((*token) && (*token)->type != TOKEN_PIPE)
	{
		if ((*token)->type == TOKEN_WORD)
		{
			if (!parse_word(token, new_cmd, &i))
			{
				free_cmd_list(new_cmd);
				return (NULL);
			}
		}
		else if ((*token)->type == TOKEN_REDIR_IN)
		{
			if (!parse_redir_in(token, new_cmd))
			{
				free_cmd_list(new_cmd);
				return (NULL);
			}
		}
		else if ((*token)->type == TOKEN_HEREDOC)
		{
			if (!parse_heredoc(token, new_cmd))
			{
				free_cmd_list(new_cmd);
				return (NULL);
			}
		}
		else if ((*token)->type == TOKEN_REDIR_OUT)
		{
			if (!parse_redir_out(token, new_cmd))
			{
				free_cmd_list(new_cmd);
				return (NULL);
			}
		}
		else if ((*token)->type == TOKEN_REDIR_APPEND)
		{
			if (!parse_redir_append(token, new_cmd))
			{
				free_cmd_list(new_cmd);
				return (NULL);
			}
		}
	}
	new_cmd->argv[i] = NULL;
	return (new_cmd);
}

t_command	*tokens_to_cmd(t_token **token)
{
	if (!token || !(*token))
		return (NULL);
	return (parse_single_command(token));
}

t_command	*parsing_cmds(t_token **token)
{
	t_command	*cmd_lst;
	t_command	*new_cmd;
	t_command	*last;

	cmd_lst = NULL;
	last = NULL;
	if (!token || !*token)
		return (NULL);
	while (*token)
	{
		new_cmd = tokens_to_cmd(token);
		if (!new_cmd)
		{
			free_cmd_list(cmd_lst);
			return (NULL);
		}
		if (cmd_lst == NULL)
			cmd_lst = new_cmd;
		else
			last->next = new_cmd;
		last = new_cmd;
		while (*token && (*token)->type != TOKEN_PIPE)
			*token = (*token)->next;
		if (*token && (*token)->type == TOKEN_PIPE)
			*token = (*token)->next;
	}
	return (cmd_lst);
}
