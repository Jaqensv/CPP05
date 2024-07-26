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
	Form &operator=(Form const &src);
	std::string getName() const;
	bool getSigned() const;
	int getGts() const;
	int getGte() const;
	std::string getReason() const;
	void formGradeChecker(int gts, int gte);
	void beSigned(Bureaucrat bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(const char *error);
		virtual const char* what() const throw() {
			return this->_error;
		}
	private:
		const char* _error;
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(const char *error);
		virtual const char* what() const throw() {
			return this->_error;
		}
	private:
		const char* _error;
	};

private:

	std::string _name;
	bool		_signed;
	int			_gts; // grade to sign
	int			_gte; // grade to execute
	std::string	_reason;

};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
