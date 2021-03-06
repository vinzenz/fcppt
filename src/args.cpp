//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::args_vector
fcppt::args(
	int const _argc,
	char **_argv
)
{
	return
		fcppt::algorithm::map<
			fcppt::args_vector
		>(
			boost::make_iterator_range(
				_argv,
				_argv + _argc
			),
			[](
				char *const _arg
			)
			{
				return
					std::string(
						_arg
					);
			}
		);
}
