/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:48:53 by albernar          #+#    #+#             */
/*   Updated: 2025/09/13 19:38:52 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	main(int argc, char **argv)
{
	t_ping_opts	opts;

	if (parse_options(argc, argv, &opts) == -1)
	{
		handle_parsing_errors(&opts, argv);
		return (EXIT_FAILURE);
	}
	handle_information_options(&opts);
	if (handle_parsed_options(&opts) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
