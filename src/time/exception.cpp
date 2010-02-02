//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/exception.hpp>
#include <fcppt/text.hpp>

fcppt::time::exception::exception(
	fcppt::string const &s
)
:
	fcppt::exception(
		FCPPT_TEXT("time: ")
		+ s
	)
{}