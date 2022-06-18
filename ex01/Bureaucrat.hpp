/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:43:43 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 00:12:28 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define MAXGRADE 1
#define MINGRADE 150
#include <iostream>
#include <exception>
#include "Colors.hpp"
#include "Form.hpp"
using std::string;
using std::cout;
using std::endl;

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(string const name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &obj);
	string			getName() const;
	int				getGrade() const;
	void			addGrade();
	void			removeGrade();
	void			signForm(Form &form);
	struct GradeTooHighException : std::exception
	{
		virtual const char * what() const throw()
		{ return (RED_C "[Bureaucrat] EXEPTION: GradeTooHighException" END_C); };
	};
	struct GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw()
		{ return (RED_C "[Bureaucrat] EXEPTION: GradeTooLowException" END_C); };
	};
private:
	const string	_name;
	int				_grade;
};

std::iostream&	operator<<(std::iostream &out, Bureaucrat &src);

#endif
