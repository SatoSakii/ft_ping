/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:53:17 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 12:48:40 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTS_H
# define FT_OPTS_H

typedef enum e_ping_opts_code
{
	PING_OPTS_NONE, // No options provided
	PING_OPTS_HELP, // Help option
	PING_OPTS_USAGE, // Usage option
	PING_OPTS_VERSION, // Version option
	PING_OPTS_MISSING_ARG, // Missing argument
	PING_OPTS_INVALID, // Invalid option (short option)
	PING_OPTS_UNRECOGNIZED, // Unrecognized option (long option)
	PING_OPTS_ERROR, // Generic error
}	t_ping_opts_code;

typedef struct s_ping_opts
{
	t_ping_opts_code	code; // Option code
	const char			*host; // Host to ping
	int					flags; // Bitmask for flags
}	t_ping_opts;

typedef enum e_ping_flags
{
	FLAG_NONE		= 0,
	FLAG_VERBOSE	= 1 << 0, // -v : Verbose output
}	t_ping_flags;

/* ══════════════════════════════════════════════════════════════════════════ */
/*                        ⚙️  OPTIONS DEFINITIONS                           */
/* ══════════════════════════════════════════════════════════════════════════ */

# define SHORT_OPTS		":?Vv"

/* ══════════════════════════════════════════════════════════════════════════ */
/*                        ⚙️  OPTIONS CONFIG PROTOTYPES                      */
/* ══════════════════════════════════════════════════════════════════════════ */

const struct option	*get_long_opts(void);
const char			*get_opt_desc(char opt);

/* ══════════════════════════════════════════════════════════════════════════ */
/*                       🛠️  OPTIONS CORE PROTOTYPES                        */
/* ══════════════════════════════════════════════════════════════════════════ */

void				options_clear(t_ping_opts *opts);

/* ══════════════════════════════════════════════════════════════════════════ */
/*                     🛠️  OPTIONS HANDLER PROTOTYPES                        */
/* ══════════════════════════════════════════════════════════════════════════ */

int					handle_option(int opt, t_ping_opts *opts);

/* ══════════════════════════════════════════════════════════════════════════ */
/*                     🛠️  OPTIONS PARSER PROTOTYPES                         */
/* ══════════════════════════════════════════════════════════════════════════ */

int					parse_options(int argc, char **argv, t_ping_opts *opts);

#endif