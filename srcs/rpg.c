/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rpg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hucanon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/15 04:21:02 by hucanon      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 04:04:50 by hucanon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rpg.h"

t_perso	*ft_map(t_perso *list_perso, int map)
{
	(void)map;
//	if (map == 0)
		return (ft_map00(list_perso, map));
//	else if (map == 1)
//		return (ft_map01(list_perso));
//	return (ft_map02(list_perso));
}

void	ft_rpg(int sauvegarde)
{
	t_perso	*list_perso;
	int		a;
	int		map;
	char	menu_launch[50][500] = {"Next Map", "See your Team", "Save game", "Exit game"};
	char	menu_team[50][500] = {"Chrom", "Rizel", "Uldur", "All", "Go back"};
	char	menu_quit[50][500] = {"Go back"};

	a = 1;
	map = 0;
	if (sauvegarde == 0)
		list_perso = init_tab(1);
	else
		list_perso = init_tab(0);
	while (a != 0 || map != 3)
	{
		ft_putstr("\e[1;1H\e[2J");
		a = menu_std(menu_launch, 4);
		if (a == 0)
		{
			list_perso = ft_map(list_perso, map);
			map++;
		}
		if (a == 1)
		{
			while (a != 4)
			{
				ft_putstr("\e[1;1H\e[2J");
				a = menu_std(menu_team, 5);
				if (a < 4)
				{
					ft_putstr("\e[1;1H\e[2J");
					print_stats(list_perso, a);
					menu_std(menu_quit, 1);
				}
			}
		}
		if (a == 2)
		{
			ft_putstr("\nYour progression has been saved.\n");
			return ;;
		}
		if (a == 3)
		{
			ft_putstr("Game successfully quitted.\n");
			return ;
		}
	}
	ft_putstr("Bravo c'est fini :)\n");
}
