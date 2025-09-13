/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:48:53 by albernar          #+#    #+#             */
/*   Updated: 2025/09/12 14:30:16 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int	handle_parsed_options(t_ping_opts *opts)
{
	if (opts->code == PING_OPTS_VERSION)
		print_version();
	else if (opts->code == PING_OPTS_HELP)
		print_help();
	else if (opts->code == PING_OPTS_USAGE)
		print_usage();
	else if (opts->code == PING_OPTS_NONE)
	{
		if (opts->host == NULL)
		{
			print_error();
			return (-1);
		}
		printf("Pinging host: %s\n", opts->host);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ping_opts	opts;

	options_clear(&opts);
	if (parse_options(argc, argv, &opts) < 0)
	{
		if (opts.code == PING_OPTS_INVALID)
			print_invalid(optopt);
		else if (opts.code == PING_OPTS_MISSING_ARG)
			print_missing_arg(optopt);
		else if (opts.code == PING_OPTS_ERROR)
			print_error();
		else if (opts.code == PING_OPTS_UNRECOGNIZED)
			print_unrecognized(argv[optind - 1]);
		return (EXIT_FAILURE);
	}
	if (handle_parsed_options(&opts) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
