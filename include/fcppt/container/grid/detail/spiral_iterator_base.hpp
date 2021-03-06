//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_SPIRAL_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_SPIRAL_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/grid/spiral_iterator_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Pos
>
using spiral_iterator_base
=
boost::iterator_facade<
	fcppt::container::grid::spiral_iterator<
		Pos
	>,
	Pos,
	std::forward_iterator_tag,
	Pos,
	typename
	Pos::value_type
>;

}
}
}
}

#endif
