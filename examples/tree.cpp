//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object.hpp>
#include <fcppt/container/tree/in_order.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/make_auto_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <ostream>
#include <cstdlib>

int main()
try
{
	typedef fcppt::container::tree::object<
		fcppt::string
	> string_tree;

	string_tree tree(
		FCPPT_TEXT("hello")
	);

	{
		string_tree::auto_ptr child1(
			fcppt::make_auto_ptr<
				string_tree
			>(
				FCPPT_TEXT("blubb")
			)
		);

		tree.push_back(
			child1
		);
	}

	{
		string_tree::auto_ptr child2(
			fcppt::make_auto_ptr<
				string_tree
			>(
				FCPPT_TEXT("blah")
			)
		);

		tree.push_back(
			child2
		);
	}

	tree.push_back(
		FCPPT_TEXT("foobar")
	);

	typedef
	fcppt::container::tree::in_order<
		string_tree const
	> traversal_type;

	traversal_type const trav(
		tree
	);

	for(
		traversal_type::iterator it = trav.begin();
		it != trav.end();
		++it
	)
		fcppt::io::cout
			<< (*it).value()
			<< std::endl;
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}