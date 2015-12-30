//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_EITHER_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/is_optional_reference.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Converts an optional to an either

\ingroup fcppteither

If \a _optional is set to <code>x</code>, then <code>x</code> is returned as
the success value, otherwise <code>_failure_function()</code> is returned the
failure value.

\tparam FailureFunction Must be a function callable as <code>R ()</code> where
<code>R</code> is the failure type
*/
template<
	typename Optional,
	typename FailureFunction
>
auto
from_optional(
	Optional &&_optional,
	FailureFunction const &_failure_function
)
->
fcppt::either::object<
	decltype(
		_failure_function()
	),
	typename
	std::decay<
		Optional
	>::type::value_type
>
{
	static_assert(
		fcppt::is_optional<
			Optional
		>::value,
		"Optional must be an optional"
	);

	static_assert(
		!fcppt::is_optional_reference<
			Optional
		>::value,
		"Optional must not be an optional reference"
	);

	typedef
	fcppt::either::object<
		decltype(
			_failure_function()
		),
		typename
		std::decay<
			Optional
		>::type::value_type
	>
	result_type;

	return
		fcppt::maybe(
			std::forward<
				Optional
			>(
				_optional
			),
			[
				&_failure_function
			]{
				return
					result_type(
						_failure_function()
					);
			},
			[](
				auto &&_value
			)
			{
				return
					result_type(
						fcppt::move_if_rvalue<
							Optional
						>(
							_value
						)
					);
			}
		);
}

}
}

#endif
