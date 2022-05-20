/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:34:21 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 15:15:13 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	test;
	ScavTrap	victim("Billy");
	ScavTrap	copied(victim);

	test.attack("Billy");
	victim.takeDamage(1);
	copied.beRepaired(2);
	test.attack("everybody");
	victim.guardGate();
	return 0;
}
