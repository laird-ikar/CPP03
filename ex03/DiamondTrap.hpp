/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:13 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 16:27:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &src);

		std::string	get_name(void) const;

		void		highFivesGuys();
		void		attack(const std::string &target);
		void		whoAmI();
};

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &ct);

#endif
