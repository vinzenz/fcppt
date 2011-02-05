//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>

namespace
{

void
empty_function()
{
}

std::vector<
	int
> values;

void
unregister(
	int const _value
)
{
	values.push_back(
		_value
	);
}

}

BOOST_AUTO_TEST_CASE(
	signals_unregister
)
{
	typedef fcppt::signal::object<
		void (),
		fcppt::signal::unregister::base
	> signal;

	signal sig;

	{
		fcppt::signal::scoped_connection const con1(
			sig.connect(
				::empty_function,
				std::tr1::bind(
					::unregister,
					42
				)
			)
		);
	}

	BOOST_REQUIRE(
		values.size() == 1
	);

	BOOST_REQUIRE(
		values.back() == 42
	);

	{
		fcppt::signal::scoped_connection const con2(
			sig.connect(
				::empty_function,
				std::tr1::bind(
					::unregister,
					100
				)
			)
		);
	}

	BOOST_REQUIRE(
		values.size() == 2
	);

	BOOST_REQUIRE(
		values.back() == 100
	);
}