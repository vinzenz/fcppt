#include <fcppt/assertion_failed.hpp>
#include <fcppt/lexical_cast.hpp>
#include <fcppt/text.hpp>

fcppt::assertion_failed::assertion_failed(
	fcppt::string const &_file,
	int const _line,
	fcppt::string const &_function,
	fcppt::string const &_condition,
	fcppt::string const &_message)
:
	exception(
		_file+
		FCPPT_TEXT(":")+
		lexical_cast<fcppt::string>(
			_line)+
		FCPPT_TEXT(": ")+
		(_function.empty() 
			? 
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT("In function \"")+
					_function+
					FCPPT_TEXT("\": ")))+
		FCPPT_TEXT("Assertion \"")+
		_condition+
		FCPPT_TEXT("\" failed")+
		(_message.empty() 
					? 
						fcppt::string()
					:
						fcppt::string(
							FCPPT_TEXT(": "))+
						_message)),
	file_(
		_file),
	line_(
		_line),
	function_(
		_function),
	condition_(
		_condition),
	message_(
		_message)
{
}

fcppt::string const &
fcppt::assertion_failed::file() const
{
	return file_;
}

int	
fcppt::assertion_failed::line() const
{
	return line_;
}

fcppt::string const &
fcppt::assertion_failed::function() const
{
	return function_;
}

fcppt::string const &
fcppt::assertion_failed::condition() const
{
	return condition_;
}

fcppt::string const &
fcppt::assertion_failed::message() const
{
	return message_;
}

fcppt::assertion_failed::~assertion_failed() throw()
{
}