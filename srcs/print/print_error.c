/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:27:36 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 11:29:29 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Print an error message for an invalid option.
 * @param opt The invalid option character.
 */
void	print_invalid(char opt)
{
	fprintf(stderr, "%s: invalid option -- '%c'\n", PROG_NAME, opt);
	fprintf(stderr, "Try '%s --help' or '%s --usage' for more information.\n",
		PROG_NAME, PROG_NAME);
}

/**
 * @brief Print an error message for an unrecognized option.
 * @param opt The unrecognized option string.
 */
void	print_unrecognized(const char *opt)
{
	fprintf(stderr, "%s: unrecognized option '%s'\n", PROG_NAME, opt);
	fprintf(stderr, "Try '%s --help' or '%s --usage' for more information.\n",
		PROG_NAME, PROG_NAME);
}

/**
 * @brief Print an error message for a missing argument for an option.
 * @param opt The option character that is missing an argument.
 */
void	print_missing_arg(char opt)
{
	fprintf(stderr, "%s: option requires an argument -- '%c'\n",
		PROG_NAME, opt);
	fprintf(stderr, "Try '%s --help' or '%s --usage' for more information.\n",
		PROG_NAME, PROG_NAME);
}

/**
 * @brief Print a generic error message for missing host operand.
 */
void	print_error(void)
{
	fprintf(stderr, "%s: missing host operand\n", PROG_NAME);
	fprintf(stderr, "Try '%s --help' or '%s --usage' for more information.\n",
		PROG_NAME, PROG_NAME);
}
