//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	std::size_t Index,
	typename Tuple,
	typename Body
>
inline
typename
std::enable_if<
	Index
	==
	std::tuple_size<
		typename
		std::decay<
			Tuple
		>::type
	>::value
>::type
tuple_loop_break(
	Tuple &&,
	Body const &
)
{
}

template<
	std::size_t Index,
	typename Tuple,
	typename Body
>
inline
typename
std::enable_if<
	Index
	<
	std::tuple_size<
		typename
		std::decay<
			Tuple
		>::type
	>::value
>::type
tuple_loop_break(
	Tuple &&_tuple,
	Body const &_body
)
{
	switch(
		_body(
			std::get<
				Index
			>(
				_tuple
			)
		)
	)
	{
	case fcppt::loop::continue_:
		fcppt::algorithm::detail::tuple_loop_break<
			Index
			+
			1u
		>(
			std::forward<
				Tuple
			>(
				_tuple
			),
			_body
		);
		break;
	case fcppt::loop::break_:
		break;
	}
}

}
}
}

#endif
