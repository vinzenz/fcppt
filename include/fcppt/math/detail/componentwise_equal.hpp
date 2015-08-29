//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Range1,
	typename Range2,
	typename T
>
bool
componentwise_equal(
	Range1 const &_r1,
	Range2 const &_r2,
	T const &_epsilon
)
{
	static_assert(
		std::is_floating_point<
			typename
			Range1::value_type
		>::value
		&&
		std::is_floating_point<
			typename
			Range2::value_type
		>::value,
		"componentwise_equal can only be used on ranges of floating point type"
	);

	return
		fcppt::algorithm::all_of(
			fcppt::make_int_range_count(
				_r1.storage().size()
			),
			[
				&_r1,
				&_r2,
				_epsilon
			](
				auto const _index
			)
			{
				return
					fcppt::math::diff(
						_r1.storage()[
							_index
						],
						_r2.storage()[
							_index
						]
					)
					<
					_epsilon;
			}
		);
}

}
}
}

#endif
