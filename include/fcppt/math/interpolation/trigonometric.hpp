//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_TRIGONOMETRIC_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_TRIGONOMETRIC_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace interpolation
{
/// Interpolates between a and b (works only with a floating point
/// parameter)
template<typename Float,typename Value>
Value
trigonometric(
	Float const &f,
	Value const &v1,
	Value const &v2)
{
	static_assert(
		std::is_floating_point<Float>::value,
		"trigonometric can only be used on floating point types"
	);

	Float const t =
		fcppt::literal<Float>(0.5) *
			(
			fcppt::literal<Float>(1) -
				std::cos(
					fcppt::math::pi<Float>() *
					f
				)
			);
	return
		(fcppt::literal<Float>(1) - t) * v1 + t * v2;
}
}
}
}

#endif
