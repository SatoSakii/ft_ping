/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:46:26 by albernar          #+#    #+#             */
/*   Updated: 2025/09/14 15:12:37 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Handle information options and set the appropriate code.
 * @param opt The option character to handle.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
static int	handle_information_options(int opt, t_ping_opts *opts)
{
	if (opt == 'H')
		opts->code = PING_OPTS_HELP;
	else if (opt == '?' && optopt == '?')
		opts->code = PING_OPTS_HELP;
	else if (opt == 1)
		opts->code = PING_OPTS_USAGE;
	else if (opt == 'V')
		opts->code = PING_OPTS_VERSION;
	else
		return (-1);
	return (0);
}

/**
 * @brief Handle error options and set the appropriate code.
 * @param opt The option character to handle.
 * @param opts Pointer to the options structure.
 * @return Always -1 (error state)
 */
static int	handle_error_options(int opt, t_ping_opts *opts)
{
	if (opt == '?' && optopt != 0)
		opts->code = PING_OPTS_INVALID;
	else if (opt == '?' && optopt == 0)
		opts->code = PING_OPTS_UNRECOGNIZED;
	else if (opt == ':')
		opts->code = PING_OPTS_MISSING_ARG;
	else
	{
		if (opts->code == PING_OPTS_NONE)
			opts->code = PING_OPTS_INVALID;
	}
	return (-1);
}

/**
 * @brief Handle the parsed option and update the options structure.
 * @param opt The option character to handle.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
int	handle_option(int opt, t_ping_opts *opts)
{
	if (handle_information_options(opt, opts) == 0)
		return (0);
	if (handle_flag_options(opt, opts) == 0)
		return (0);
	return (handle_error_options(opt, opts));
}
