/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:43:47 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 00:51:13 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	cout << "\033[04;07;38;05;232;48;05;184m"
	<< "\t\t\tWelcome to Bureaucrat routine!" END_C << endl;
	Bureaucrat	a("Oleg", 75);
	cout << BLACKBG_C "\t Wrong param for construct Bur:" END_C << endl;
	Bureaucrat	c("Daddy", 159);


	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	cout << c.getName() << " burec have grade " << c.getGrade() << endl;
	for (int i = 0; i < 74; i++)
		a.addGrade();
	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	
}
