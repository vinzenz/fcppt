//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_loop_mpl
)
{
FCPPT_PP_POP_WARNING

	int value{
		0
	};

	fcppt::algorithm::loop(
		boost::mpl::range_c<
			int,
			0,
			5
		>{},
		[
			&value
		](
			auto const _index
		)
		{
			FCPPT_USE(
				_index
			);

			typedef
			fcppt::tag_type<
				decltype(
					_index
				)
			>
			index;

			static_assert(
				index::value
				<
				5,
				""
			);

			value +=
				index::value;
		}
	);

	BOOST_CHECK_EQUAL(
		value,
		10
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_loop_range
)
{
FCPPT_PP_POP_WARNING

	int value{
		0
	};

	fcppt::algorithm::loop(
		fcppt::make_int_range_count(
			5
		),
		[
			&value
		](
			int const _value
		)
		{
			value +=
				_value;
		}
	);

	BOOST_CHECK_EQUAL(
		value,
		10
	);
}
