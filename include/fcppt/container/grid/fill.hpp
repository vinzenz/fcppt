//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_FILL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_FILL_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/fill.hpp>
#include <fcppt/math/dim/basic_impl.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
/**
 * \brief Fills a grid using a functor
 * \ingroup fcpptcontainergrid
 * \tparam Fn A functor with the signature: <code>grid::value_type(grid::dim)</code>
 */
template
<
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Fn
>
void
fill(
	object<T,N,A> &g,
	Fn const &f)
{
	typename object<T,N,A>::dim position;
	fcppt::container::grid::detail::fill<0>(
		g,
		f,
		position);
}
}
}
}

#endif
