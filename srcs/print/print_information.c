/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:27:12 by albernar          #+#    #+#             */
/*   Updated: 2025/09/14 11:30:30 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Print the program version information.
 */
void	print_version(void)
{
	fprintf(stdout, PROG_NAME " version " PROG_VERSION "\n");
	fprintf(stdout, "This is a 42 school project.\n");
	fprintf(stdout, "It is a simple ping utility.\n");
	fprintf(stdout, "\nWritten by albernar.\n");
}

/**
 * @brief Print the usage message for the program.
 */
void	print_usage(void)
{
	fprintf(stdout, "Usage: %s ", PROG_NAME);
	fprintf(stdout, "[-?V] [--help] [--usage] [--version]\n");
	fprintf(stdout, "%*sHOST ...\n", (int)strlen("Usage: " PROG_NAME " "), "");
}

/**
 * @brief Print the help message with available options.
 */
void	print_help(void)
{
	fprintf(stdout, "Usage: %s ", PROG_NAME);
	fprintf(stdout, "[OPTION...] HOST ...\n");
	fprintf(stdout, "Send ICMP ECHO_REQUEST packets to network hosts.\n\n");
	fprintf(stdout, " Options:\n");
	fprintf(stdout, "  -s, --size=NUMBER  %s\n", get_opt_desc('s'));
	fprintf(stdout, "  -q, --quiet    %s\n", get_opt_desc('q'));
	fprintf(stdout, "  -?, --help     %s\n", get_opt_desc('?'));
	fprintf(stdout, "      --usage    %s\n", get_opt_desc(1));
	fprintf(stdout, "  -V, --version  %s\n", get_opt_desc('V'));
	fprintf(stdout, "  -v, --verbose  %s\n", get_opt_desc('v'));
}
