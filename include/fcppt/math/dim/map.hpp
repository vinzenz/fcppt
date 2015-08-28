//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_MAP_HPP_INCLUDED
#define FCPPT_MATH_DIM_MAP_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Maps over the elements of a dim

\ingroup fcpptmathdim
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S,
	typename Function
>
inline
fcppt::math::dim::static_<
	typename
	std::result_of<
		Function(
			T
		)
	>::type,
	N
>
map(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_value,
	Function const &_function
)
{
	return
		fcppt::math::map<
			fcppt::math::dim::static_<
				typename
				std::result_of<
					Function(
						T
					)
				>::type,
				N
			>
		>(
			_value,
			_function
		);
}

}
}
}

#endif
