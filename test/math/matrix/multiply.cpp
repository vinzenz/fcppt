//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiply)
{
	typedef fcppt::math::matrix::static_<
		int,
		3,
		3
	>::type mat3;

	mat3 const
		left(
			1,2,3,
			4,5,6,
			7,8,9
		),
		right(
			10,11,12,
			13,14,15,
			16,17,18
		),
		result(
			left * right
		);

	fcppt::io::cout
		<< result
		<< FCPPT_TEXT('\n');
	
	BOOST_REQUIRE(
		result
		==
		mat3(
			84,90,96,
			201,216,231,
			318,342,366
		)
	);
}