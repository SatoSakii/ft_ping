/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:01:04 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 20:23:11 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Get the long options array for getopt_long.
 * @return Pointer to the static array of struct option.
 */
const struct option	*get_long_opts(void)
{
	static struct option	long_opts[] = {
	{"help", no_argument, 0, 'H'},
	{"usage", no_argument, 0, 1},
	{"version", no_argument, 0, 'V'},
	{"verbose", no_argument, 0, 'v'},
	{"quiet", no_argument, 0, 'q'},
	{"size", required_argument, 0, 's'},
	{0, 0, 0, 0}
	};

	return (long_opts);
}

/**
 * @brief Get the description for a given option.
 * @param opt The option character.
 * @return Description string for the option.
 */
const char	*get_opt_desc(char opt)
{
	if (opt == '?' || opt == 'H')
		return ("give this help list");
	else if (opt == 1)
		return ("give a short usage message");
	else if (opt == 'V')
		return ("print program version");
	else if (opt == 'v')
		return ("verbose output");
	else if (opt == 'q')
		return ("quiet output");
	else if (opt == 's')
		return ("send NUMBER data octets");
	return (NULL);
}
