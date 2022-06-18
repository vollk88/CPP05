/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:43:47 by hloki             #+#    #+#             */
/*   Updated: 2022/06/08 23:55:10 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	a;
	Bureaucrat	c("Daddy", 159);

	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	cout << c.getName() << " burec have grade " << c.getGrade() << endl;
	for (int i = 0; i < 74; i++)
		a.addGrade();
	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
}
