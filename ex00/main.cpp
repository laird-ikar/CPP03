/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:34:21 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 11:51:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	test;
	ClapTrap	named("Alice");
	ClapTrap	victim("Billy");
	ClapTrap	copied(named);

	test.attack("Billy");
	victim.takeDamage(1);
	victim.beRepaired(2);
	int i = 12;
	while (--i)
		named.attack("Billy");
	victim.takeDamage(20);
	victim.beRepaired(10);
	victim.attack("everybody");
	return 0;
}
