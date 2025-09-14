/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:04:55 by albernar          #+#    #+#             */
/*   Updated: 2025/09/14 15:22:06 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Handle simple flag options and update the options structure.
 * @param opt The option character to handle.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 if the option is not a simple flag.
 */
static int	handle_simple_flags(int opt, t_ping_opts *opts)
{
	if (opt == 'v')
	{
		opts->flags |= FLAG_VERBOSE;
		return (0);
	}
	else if (opt == 'q')
	{
		opts->flags |= FLAG_QUIET;
		return (0);
	}
	return (-1);
}

/**
 * @brief Handle the size flag option and update the options structure.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
static int	handle_size_flag(t_ping_opts *opts)
{
	char	*endptr;

	opts->packet_size = strtoul(optarg, &endptr, 10);
	opts->flags |= FLAG_SIZE;
	if (optarg && !*optarg)
		return (0);
	if (endptr == optarg || *endptr != 0)
	{
		opts->code = PING_OPTS_INVALID_VALUE;
		optind = (int)(endptr - optarg);
		return (-1);
	}
	else if (opts->packet_size > MAX_PACKET_SIZE)
	{
		opts->code = PING_OPTS_WRONG_SIZE;
		return (-1);
	}
	return (0);
}

/**
 * @brief Handle flag options and update the options structure.
 * @param opt The option character to handle.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
int	handle_flag_options(int opt, t_ping_opts *opts)
{
	if (handle_simple_flags(opt, opts) == 0)
		return (0);
	else if (opt == 's')
		return (handle_size_flag(opts));
	return (-1);
}
