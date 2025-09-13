/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:26 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 11:25:49 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

/* ══════════════════════════════════════════════════════════════════════════ */
/*                          📚  STANDARD LIBRARIES                           */
/* ══════════════════════════════════════════════════════════════════════════ */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <getopt.h>
# include <string.h>
# include "ft_opts.h"

/* ══════════════════════════════════════════════════════════════════════════ */
/*                          🏷️  PROGRAM DEFINITIONS                          */
/* ═════════════════════════════════════════════════════════════════════════ */

# define PROG_NAME		"ft_ping"
# define PROG_VERSION	"1.0.0"

/* ══════════════════════════════════════════════════════════════════════════ */
/*                        🖨️  PRINT FUNCTION PROTOTYPES                      */
/* ══════════════════════════════════════════════════════════════════════════ */

/* Information print functions */
void	print_version(void);
void	print_usage(void);
void	print_help(void);

/* Error print functions */
void	print_invalid(char opt);
void	print_missing_arg(char opt);
void	print_error(void);
void	print_unrecognized(const char *opt);

#endif