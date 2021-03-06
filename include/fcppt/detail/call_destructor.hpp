//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CALL_DESTRUCTOR_HPP_INCLUDED
#define FCPPT_DETAIL_CALL_DESTRUCTOR_HPP_INCLUDED

#include <fcppt/use.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
inline
void
call_destructor(
	Type const &_value
)
{
	FCPPT_USE(
		_value
	);

	_value.~Type();
}

}
}

#endif
