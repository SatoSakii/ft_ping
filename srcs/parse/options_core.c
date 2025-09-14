/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:44:56 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 21:02:14 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Clear the options structure to its default state.
 * @param opts Pointer to the options structure.
 */
void	options_clear(t_ping_opts *opts)
{
	if (!opts)
		return ;
	opts->code = PING_OPTS_NONE;
	opts->host = NULL;
	opts->flags = 0;
	opts->packet_size = DEFAULT_PACKET_SIZE;
}
