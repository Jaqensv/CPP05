#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <cstring>
# include <stdlib.h>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:

	AForm();
	virtual ~AForm();
	AForm(const std::string name, const int gts, const int gte);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	const std::string getName() const;
	bool getSigned() const;
	int getGts() const;
	int getGte() const;
	std::string getReason() const;
	void formGradeChecker(const int gts, const int gte, std::string name);
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const;
	virtual void execution(Bureaucrat const &executor) const = 0;
	virtual bool signProcess(bool iss); // iss = is_signed
	virtual std::string reasonModifier(std::string reason);
	bool form_err; // mettre en private

	class WrongGradeException : public std::exception {
	public:
		virtual ~WrongGradeException() throw();
		WrongGradeException(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

protected:

	std::string 		_target;

private:

	const std::string 	_name;
	bool				_signed;
	bool				_signable;
	const int			_gts; // grade to sign
	const int			_gte; // grade to execute
	std::string			_reason;


};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
