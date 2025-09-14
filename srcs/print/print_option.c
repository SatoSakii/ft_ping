/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:43:22 by albernar          #+#    #+#             */
/*   Updated: 2025/09/14 12:27:51 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Print an error message for an option value too big.
 * @param opt The option value.
 */
void	print_option_value_big(const char *opt)
{
	fprintf(stderr, "%s: option value too big: %s\n", PROG_NAME, opt);
}

/**
 * @brief Print an error message for an invalid option value.
 * @param opt The option value.
 * @param optind The index of the option to start.
 */
void	print_option_value_invalid(const char *opt, const int optind)
{
	fprintf(stderr, "%s: invalid value (`%s' near `%s')\n",
		PROG_NAME, opt, opt + optind);
}
