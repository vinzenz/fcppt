//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_END_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_END_POSITION_HPP_INCLUDED

#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos<
	SizeType,
	Size
>
end_position(
	fcppt::container::grid::min<
		SizeType,
		Size
	> const _min,
	fcppt::container::grid::sup<
		SizeType,
		Size
	> const _sup
)
{
	return
		fcppt::algorithm::contains_if(
			boost::range::combine(
				_min.get(),
				_sup.get()
			),
			[](
				boost::tuple<
					fcppt::container::grid::size_type,
					fcppt::container::grid::size_type
				> const _val
			)
			{
				return
					boost::get<
						0
					>(
						_val
					)
					>=
					boost::get<
						1
					>(
						_val
					);
			}
		)
		?
			_min.get()
		:
			fcppt::math::vector::init<
				fcppt::container::grid::pos<
					SizeType,
					Size
				>
			>(
				[
					_min,
					_sup
				](
					fcppt::math::size_type const _index
				)
				{
					return
						_index
						<
						Size - 1
						?
							_min.get()[
								_index
							]
						:
							_sup.get()[
								_index
							]
						;
				}
			)
		;
}

}
}
}

#endif