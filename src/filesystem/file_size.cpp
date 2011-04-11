//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/file_size.hpp>
#include <boost/filesystem/operations.hpp>

boost::uintmax_t
fcppt::filesystem::file_size(
	fcppt::filesystem::path const &_path
)
{
	return
		boost::filesystem::file_size(
			_path
		);
}