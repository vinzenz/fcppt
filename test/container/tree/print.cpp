//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/tree.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

BOOST_AUTO_TEST_CASE(
	container_tree_print
)
{
	typedef fcppt::container::tree::object<
		std::string
	> string_tree;

	string_tree tree("a");

	tree.push_back(
		std::string("b")
	);

	tree.back().push_back(
		std::string("c")
	);

	tree.push_back(
		std::string("d")
	);

	tree.push_back(
		std::string("e")
	);

	std::ostringstream oss;

	fcppt::container::tree::print(
		oss,
		tree
	);

	std::cout
		<< oss.str()
		<< '\n';

	BOOST_REQUIRE(
		oss.str()
		==
		"a\n"
			"\tb\n"
				"\t\tc\n"
			"\td\n"
			"\te\n"
	);
}