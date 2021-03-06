//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/algorithm/array_init_const.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/generate_binary_vectors.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
/**
\brief Generates vectors consisting of zeros and ones
\ingroup fcpptmath
\tparam T Any type that you can <code>static_cast</code> 0 and 1 to

Generates the binary vectors of type <code>T</code> in dimension
<code>N</code>. Examples:

<pre>
T = int,
N = 2:

(0,0)
(1,0)
(0,1)
(1,1)

T = int,
N = 3:
(0,0,0)
(1,0,0)
(0,1,0)
(1,1,0)
(0,0,1)
(1,0,1)
(0,1,1)
(1,1,1)
</pre>

This is used, for example, in fcppt::math::box::corner_points.

Example:

\code
typedef
fcppt::math::vector::static_<int,3>
vector3;

// In dimension 3, we have 2^3=8 vectors, so typedef an array of this size
// here:

typedef
std::array<vector3,8>
binary_vectors;

binary_vectors vs(
	fcppt::math::generate_binary_vectors<int,3>());

// Outputs 0,0,0
std::cout << vs[0];

// Outputs 0,0,1
std::cout << vs[1];

// ...
\endcode
*/
template<
	typename T,
	fcppt::math::size_type N
>
std::array<
	fcppt::math::vector::static_<T,N>,
	fcppt::literal<std::size_t>(1u) << N
>
generate_binary_vectors()
{
	typedef
	fcppt::math::vector::static_<T,N>
	vector_type;

	typedef
	std::array
	<
		vector_type,
		fcppt::literal<std::size_t>(1u) << N
	>
	result_type;

	result_type result(
		fcppt::algorithm::array_init_const<
			result_type
		>(
			fcppt::math::vector::null<
				vector_type
			>()
		)
	);

	typename result_type::iterator it = result.begin();

	fcppt::math::detail::generate_binary_vectors
	<
		N - fcppt::literal<fcppt::math::size_type>(1),
		typename result_type::iterator,
		vector_type
	>(
		it,
		fcppt::math::vector::null<
			vector_type
		>()
	);

	return result;
}
}
}

#endif
