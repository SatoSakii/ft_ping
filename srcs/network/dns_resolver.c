/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns_resolver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:09:48 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 16:34:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/**
 * @brief Resolve a hostname to its IPv4 address.
 * @param hostname The hostname to resolve.
 * @param resolved_ip Buffer to store the resolved IP address
 * (must be at least INET_ADDRSTRLEN bytes).
 * @return 0 on success, -1 on failure.
 */
int	resolve_hostname(const char *hostname, char *resolved_ip)
{
	struct addrinfo		hints;
	struct addrinfo		*result;
	struct sockaddr_in	*addr_in;

	if (!hostname || !resolved_ip)
		return (-1);
	if (is_valid_ipv4(hostname))
	{
		strcpy(resolved_ip, hostname);
		return (0);
	}
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(hostname, NULL, &hints, &result) != 0)
		return (-1);
	addr_in = (struct sockaddr_in *)result->ai_addr;
	if (!inet_ntop(AF_INET, &addr_in->sin_addr, resolved_ip, INET_ADDRSTRLEN))
	{
		freeaddrinfo(result);
		return (-1);
	}
	freeaddrinfo(result);
	return (0);
}
