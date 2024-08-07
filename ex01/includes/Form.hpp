#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form();
	~Form();
	Form(std::string name, int gts, int gte);
	Form(Form const &src);
	Form &operator=(Form const &rhs);
	const std::string getName() const;
	bool getSigned() const;
	bool getSignable() const;
	int getGts() const;
	int getGte() const;
	std::string getReason() const;
	void formGradeChecker(const int gts, const int gte, std::string name);
	void beSigned(Bureaucrat &bureaucrat);
	bool signProcess(bool iss);
	std::string reasonModifier(std::string reason);

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

private:

	const std::string 	_name;
	bool				_signed;
	bool				_signable;
	const int			_gts; // grade to sign
	const int			_gte; // grade to execute
	std::string			_reason;
	bool 				_form_err;

};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
