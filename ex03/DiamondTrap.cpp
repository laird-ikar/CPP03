/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:23 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 16:36:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/***********************
*	Constructors & Destructor
***********************/

DiamondTrap::DiamondTrap(void)
{
	ClapTrap::name = "_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->atk = FragTrap::atk;
	std::cout << "A new DiamondTrap was build." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	*this = src;
	std::cout << "A new DiamondTrap was build, on the model of " << src << "."
		<< std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->atk = FragTrap::atk;
	this->name = name;
	std::cout << "A new DiamondTrap was build." << std::endl;
	std::cout << "It was named " << name << "." << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << *this << " got destroyed..." << std::endl;
	return ;
}

/***********************
*	Assignation Operators
***********************/

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const &src)
{
	this->ClapTrap::name = src.ClapTrap::name;
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->atk = src.atk;
	return (*this);
}

/***********************
*	Boolean Operators
***********************/

/***********************
*	Arithmetic Operators
***********************/

/***********************
*	Stream Operators
***********************/

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &ct)
{
	return (o << "DiamondTrap named " << ct.get_name());
}

/***********************
*	Getter & Setters
***********************/

std::string	DiamondTrap::get_name(void) const
{
	return (this->name);
}

/***********************
*	Methods
***********************/

void		DiamondTrap::highFivesGuys()
{
	std::cout << *this << " asked for a high five ! But nobody came..."
	<< std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI()
{
	std::cout << "I am " << *this << " also named " << ClapTrap::name
		<< std::endl;
}
