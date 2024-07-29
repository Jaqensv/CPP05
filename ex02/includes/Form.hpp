#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
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
	void formGradeChecker(int gts, int gte);
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	bool form_err;

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

	const std::string 	_name;
	bool				_signed;
	const int			_gts; // grade to sign
	const int			_gte; // grade to execute
	std::string			_reason;

};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
