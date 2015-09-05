//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED

#include <fcppt/tag_value.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/if_not_last_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename Type
>
std::basic_ostream<
	Ch,
	Traits
> &
one_dimensional_output(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	Type const &_value
)
{
	_stream <<
		_stream.widen('(');

	fcppt::algorithm::loop(
		fcppt::math::int_range_count<
			Type::static_size::value
		>{},
		[
			&_stream,
			&_value
		](
			auto const _index
		)
		{
			_stream
				<<
				fcppt::math::at_c<
					fcppt::tag_value(
						_index
					)
				>(
					_value
				);

			fcppt::math::detail::if_not_last_index(
				fcppt::tag_value(
					_index
				),
				typename
				Type::static_size{},
				[
					&_stream
				]{
					_stream
						<< _stream.widen(',');
				}
			);
		}
	);

	return
		_stream
		<<
		_stream.widen(')');
}

}
}
}

#endif
