/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:39 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:24:40 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_handler(char *message)
{
	get_next_line(-1);
	ft_printf("%s\n", message);
}

void	end_game_text(t_game *game)
{
	ft_printf("\n");
	ft_printf("   ███████╗ ██████╗  ██╗      ██████╗ ███╗   ██╗ ██████╗ \n");
	ft_printf("   ██╔════╝██╔═══██╗ ██║     ██╔═══██╗████╗  ██║██╔════╝ \n");
	ft_printf("   ███████╗██║   ██║ ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n");
	ft_printf("   ╚════██║██║   ██║ ██║     ██║   ██║██║╚██╗██║██║   ██║\n");
	ft_printf("   ███████║╚██████╔╝ ███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n");
	ft_printf("   ╚══════╝ ╚═════╝  ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n");
	ft_printf("\n");
	ft_printf("    **********************************************     \n");
	ft_printf("    * Congrats! You beat the game in %u moves!   *     \n",
		game->moves);
	ft_printf("    *  So long, and thanks for all the fish!     *     \n");
	ft_printf("    *                 by ehabes                  *     \n");
	ft_printf("    **********************************************     \n");
	ft_printf("\n");
}
