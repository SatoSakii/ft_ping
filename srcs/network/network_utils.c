/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:05:22 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 16:09:27 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Validate if the given string is a valid IPv4 address.
 * @param ip The string to validate.
 * @return 1 if valid, 0 otherwise.
 */
int	is_valid_ipv4(const char *ip)
{
	struct sockaddr_in	sa;

	return (inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1);
}
