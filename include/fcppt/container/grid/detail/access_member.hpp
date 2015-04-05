//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_ACCESS_MEMBER_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_ACCESS_MEMBER_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Container,
	typename Dim,
	typename Pos
>
fcppt::container::to_reference_type<
	Container
>
access_member(
	Container &_container,
	Dim const &_dim,
	Pos const &_pos
)
{
	typedef typename Container::size_type size_type;

	size_type index = _pos[0];

	size_type mul = 1;

	for(
		typename Dim::size_type i = 1;
		i < Dim::dim_wrapper::value;
		++i
	)
	{
		mul *= _dim[i - 1];

		index += mul * _pos[i];
	}

	return _container[index];
}

}
}
}
}

#endif
