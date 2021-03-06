//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/std_hash.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_dim_hash
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::dim::static_<
		int,
		3
	>
	int3_dim;

	typedef
	std::unordered_set<
		int3_dim
	>
	dim_set;

	dim_set set;

	set.insert(
		int3_dim(
			1,
			2,
			3
		)
	);

	BOOST_CHECK_EQUAL(
		set.count(
			int3_dim(
				1,
				2,
				3
			)
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		set.count(
			int3_dim(
				4,
				2,
				3
			)
		),
		0u
	);
}
