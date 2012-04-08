//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_PARSE_TIME_HPP_INCLUDED
#define FCPPT_TIME_PARSE_TIME_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/io/istream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

/**
\brief Tries to parse a date from a stream

\ingroup fcppttime

Tries to parse time from \a stream, storing the result in \a result, using the
<code>std::time_get</code> locale face obtained from the locale of \a stream.
If the parsing is successful, the following members of \a result might be
modified: <code>tm_sec</code>, <code>tm_min</code> and <code>tm_hour</code>.
Otherwise the failbit of \a stream will be set and \a result will be left
untouched.

\param stream The stream to parse from

\param result The result

\return \a stream
*/
FCPPT_SYMBOL
fcppt::io::istream &
parse_time(
	fcppt::io::istream &stream,
	std::tm &result
);

}
}

#endif
