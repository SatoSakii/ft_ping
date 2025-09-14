/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:26 by albernar          #+#    #+#             */
/*   Updated: 2025/09/14 11:43:36 by albernar         ###   ########.fr       */
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
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <netdb.h>
# include "ft_opts.h"

/* ══════════════════════════════════════════════════════════════════════════ */
/*                          🏷️  PROGRAM DEFINITIONS                          */
/* ═════════════════════════════════════════════════════════════════════════ */

# define PROG_NAME		"ft_ping"
# define PROG_VERSION	"1.0.0"

/* ══════════════════════════════════════════════════════════════════════════ */
/*                          CORE FUNCTION PROTOTYPES                          */
/* ══════════════════════════════════════════════════════════════════════════ */

void	handle_parsing_errors(t_ping_opts *opts, char **argv);
void	handle_parsing_informations(t_ping_opts *opts);
int		handle_parsed_options(t_ping_opts *opts);

/* ══════════════════════════════════════════════════════════════════════════ */
/*                        🖨️  PRINT FUNCTION PROTOTYPES                      */
/* ══════════════════════════════════════════════════════════════════════════ */

void	print_version(void);
void	print_usage(void);
void	print_help(void);

void	print_invalid(char opt);
void	print_missing_arg(char opt);
void	print_missing_host(void);
void	print_unknown_host(void);
void	print_unrecognized(const char *opt);

void	print_option_value_big(const char *opt);
void	print_option_value_invalid(const char *opt, const int optind);

/* ══════════════════════════════════════════════════════════════════════════ */
/*                       🛠️  NETWORK FUNCTION PROTOTYPES                      */
/* ══════════════════════════════════════════════════════════════════════════ */

int		is_valid_ipv4(const char *ip);
int		resolve_hostname(const char *hostname, char *resolved_ip);

#endif