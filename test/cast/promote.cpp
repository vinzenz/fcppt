//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/promote.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	cast_promote
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::cast::promote(
			'c'
		),
		'c'
	);

	static_assert(
		std::is_same<
			decltype(
				fcppt::cast::promote(
					'c'
				)
			),
			decltype(
				+'c'
			)
		>::value,
		""
	);
}
