//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given \p value is inside a range.

\ingroup fcpptalgorithm

\tparam T Must be equality comparable to the range's value type.
*/
template<
	typename Range,
	typename T
>
inline
bool
contains(
	Range const &_range,
	T const &_value
)
{
	return
		::std::find(
			_range.begin(),
			_range.end(),
			_value
		)
		!=
		_range.end();
}

}
}

#endif
