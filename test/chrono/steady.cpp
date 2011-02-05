//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/chrono.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(chrono_steady)
{
	typedef fcppt::chrono::steady_clock::time_point time_point;

	time_point old_time(
		fcppt::chrono::steady_clock::now()
	);

	for(
		unsigned i = 0;
		i < 3;
		++i
	)
	{
		time_point const new_time(
			fcppt::chrono::steady_clock::now()
		);

		BOOST_REQUIRE(
			old_time < new_time
		);

		old_time = new_time;

		fcppt::time::sleep_any(
			fcppt::chrono::seconds(
				1
			)
		);
	}
}