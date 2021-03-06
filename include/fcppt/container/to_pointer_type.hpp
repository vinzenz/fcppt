//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TO_POINTER_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_POINTER_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

template<
	typename Container
>
using
to_pointer_type
=
typename
std::conditional<
	std::is_const<
		Container
	>::value,
	typename
	Container::const_pointer,
	typename
	Container::pointer
>::type;

}
}

#endif
