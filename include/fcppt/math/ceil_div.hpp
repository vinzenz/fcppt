//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CEIL_DIV_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates dividend / divisor rounded towards infinity
\tparam T An unsigned type
\ingroup fcpptmath
\param _dividend The dividend
\param _divisor The divisor
*/
template<
	typename T
>
T
ceil_div(
	T const &_dividend,
	T const &_divisor
)
{
	static_assert(
		std::is_unsigned<
			T
		>::value,
		"ceil_div can only be used on unsigned types"
	);

	return
		_dividend
		/
		_divisor
		+
		(
			_dividend
			%
			_divisor
			?
				fcppt::literal<
					T
				>(
					1
				)
			:
				fcppt::literal<
					T
				>(
					0
				)
		);
}

}
}

#endif
