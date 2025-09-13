/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:54:20 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 12:14:03 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Initialize the parser state.
 * @param opts Pointer to the options structure.
 */
static void	init_parser_state(t_ping_opts *opts)
{
	options_clear(opts);
	optind = 1;
	opterr = 0;
}

/**
 * @brief Extract the host from the command line arguments.
 * @param argc Argument count.
 * @param argv Argument list.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
static int	extract_host(int argc, char **argv, t_ping_opts *opts)
{
	if (optind < argc)
	{
		opts->host = argv[optind];
		return (0);
	}
	return (0);
}

/**
 * @brief Parse command line options and validate the options structure.
 * @param argc Argument count.
 * @param argv Argument list.
 * @param opts Pointer to the options structure.
 * @return 0 on success, -1 on failure.
 */
int	parse_options(int argc, char **argv, t_ping_opts *opts)
{
	int					opt;
	int					opt_index;
	int					result;
	const struct option	*long_opts;

	if (!opts)
		return (-1);
	init_parser_state(opts);
	long_opts = get_long_opts();
	opt_index = 0;
	result = 0;
	while (1)
	{
		opt = getopt_long(argc, argv, SHORT_OPTS, long_opts, &opt_index);
		if (opt == -1)
			break ;
		result = handle_option(opt, opts);
		if (result == -1)
			break ;
	}
	if (result == 0)
		result = extract_host(argc, argv, opts);
	return (result);
}
