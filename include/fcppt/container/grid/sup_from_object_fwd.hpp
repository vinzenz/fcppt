//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SUP_FROM_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SUP_FROM_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/container/grid/sup_fwd.hpp>
#include <fcppt/container/grid/object_decl.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
using
sup_from_object
=
fcppt::container::grid::sup<
	typename
	Grid::size_type,
	Grid::static_size::value
>;

}
}
}

#endif