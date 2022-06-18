/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:43:47 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 00:34:10 by hloki            ###   ########.fr       */
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
	Form		form("MyForm", 70, 35);
	cout << BLACKBG_C "\t Wrong param for construct Form:" END_C << endl;
	Form		wrongForm("wrong", 0, 1);
	Form		wrongForm2("wrong", 45, 151);

	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	cout << c.getName() << " burec have grade " << c.getGrade() << endl;
	a.signForm(form);
	cout << BLACKBG_C "\tNow own little burec cant sign form. But he will grow up" END_C << endl;
	for (int i = 0; i < 74; i++)
		a.addGrade();
	cout << BLACKBG_C "\t And then burec " << a.getName() << " have permitions for sign the form)) " END_C "\n"<< endl;
	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	a.signForm(form);
	cout << form << endl;
	
}
