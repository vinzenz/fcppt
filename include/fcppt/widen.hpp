//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WIDEN_HPP_INCLUDED
#define FCPPT_WIDEN_HPP_INCLUDED

#include <fcppt/default_locale.hpp>
#include <fcppt/symbol.hpp>
#include <string>
#include <locale>

namespace fcppt
{

/// convert an std::string to std::wstring
FCPPT_SYMBOL std::wstring const
widen(
	std::string const &,
	std::locale const & = fcppt::default_locale()
);

}

#endif
