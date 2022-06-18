/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:01:27 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 11:20:12 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class Form
{	
public:
	Form();
	Form(const Form &obj);
	Form(string name, int gradeToSign, int gradeToExecute);
	~Form();
	virtual const string	getName() const = 0;
	virtual bool			isSigned() const = 0;
	virtual int				getGradeToSign() const = 0;
	virtual int				getGradeToExecute() const = 0;
	virtual Form 			&operator=(const Form &obj) = 0;
	virtual void			beSigned(const Bureaucrat &bur) = 0;
	virtual void			execute(const Bureaucrat &executor) const = 0;

	struct GradeTooHighException : std::exception
	{
		virtual const char * what() const throw()
		{ return (RED_C "[Form] EXEPTION: GradeTooHighException" END_C); };
	};
	struct GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw()
		{ return ( RED_C "[Form] EXEPTION: GradeTooLowException" END_C); };
	};
	
private:
	const string	_name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExecute;
	
};

std::ostream	&operator<<(std::ostream &obj, Form const &f);

#endif