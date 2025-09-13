/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:28:21 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 19:41:47 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Handle parsing errors based on the options code.
 * @param opts Pointer to the options structure.
 * @param argv The original argv array for unrecognized options.
 */
void	handle_parsing_errors(t_ping_opts *opts, char **argv)
{
	if (opts->code == PING_OPTS_INVALID)
		print_invalid(optopt);
	else if (opts->code == PING_OPTS_MISSING_ARG)
		print_missing_arg(optopt);
	else if (opts->code == PING_OPTS_UNRECOGNIZED)
		print_unrecognized(argv[optind - 1]);
}

/**
 * @brief Handle information options like help, version, and usage.
 * @param opts Pointer to the options structure.
 */
void	handle_information_options(t_ping_opts *opts)
{
	if (opts->code == PING_OPTS_VERSION)
		print_version();
	else if (opts->code == PING_OPTS_HELP)
		print_help();
	else if (opts->code == PING_OPTS_USAGE)
		print_usage();
}

/**
 * @brief Handle parsed options and perform necessary actions.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
int	handle_parsed_options(t_ping_opts *opts)
{
	if (opts->code == PING_OPTS_NONE)
	{
		if (!opts->host)
		{
			print_missing_host();
			return (-1);
		}
		if (resolve_hostname(opts->host, opts->resolved_ip) == -1)
		{
			print_unknown_host();
			return (-1);
		}
		printf("Debug: Resolved IP: %s\n", opts->resolved_ip);
		printf("Debug: Hostname: %s\n", opts->host);
		printf("Debug: Verbose mode: %s\n", opts->flags & FLAG_VERBOSE ? "ON" : "OFF");
	}
	return (0);
}
