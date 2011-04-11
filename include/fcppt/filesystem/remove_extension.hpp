//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_REMOVE_EXTENSION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_REMOVE_EXTENSION_HPP_INCLUDED

#include <fcppt/filesystem/path.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace filesystem
{

/// Removes the complete extension including the dot, if the path has any
FCPPT_SYMBOL
filesystem::path const
remove_extension(
	filesystem::path const &
);

}
}

#endif