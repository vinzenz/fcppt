//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/grid/interpolate.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/interpolation/linear_functor.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [grid_simple]
// typedef a three dimensional grid of ints
typedef
fcppt::container::grid::object<
	int,
	3
>
int3d_grid;

void
use_grid()
{
	// Create a 5 by 10 by 20 grid.
	int3d_grid grid(
		int3d_grid::dim(
			5u,
			10u,
			20u
		),
		0
	);

	// Set the value on position (1,2,3) to 42
	grid[
		int3d_grid::pos(
			1u,
			2u,
			3u
		)
	] = 42;

	fcppt::io::cout()
		<< grid[
			int3d_grid::pos(
				1u,
				2u,
				3u
			)
		]
		<< FCPPT_TEXT('\n');
}
//! [grid_simple]

}

namespace
{

void
init()
{
//! [grid_init]
	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2d_grid;

	// Initialize all cells to 42
	int2d_grid const all_42(
		int2d_grid::dim(
			3u,
			2u
		),
		42
	);

	// Initialize using a function
	int2d_grid const init_function(
		int2d_grid::dim(
			3u,
			2u
		),
		[](
			int2d_grid::pos const _pos
		)
		{
			return
				_pos.x()
				==
				_pos.y()
				?
					1
				:
					0
				;
		}
	);

	// Don't initialize the grid
	int2d_grid uninit(
		int2d_grid::dim(
			3u,
			4U
		),
		fcppt::no_init{}
	);

	uninit[
		int2d_grid::pos(
			3u,
			2u
		)
	] =
		10;

//! [grid_init]
}

}

//! [grid_resize]
#include <fcppt/no_init.hpp>
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/resize_preserve_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2d_grid;

void
resize_grid()
{
	int2d_grid grid(
		int2d_grid::dim(
			2u,
			3u
		),
		fcppt::no_init{}
	);

	{
		int count = 0;

		// Initialize the grid with numbers from 0 to 5.
		// Note, that a grid will always be laid out in memory such that
		// the lower dimensions are closer together.
		std::generate(
			grid.begin(),
			grid.end(),
			[
				&count
			]()
			{
				return
					count++;
			}
		);
	}

	fcppt::io::cout()
		<< grid
		<< FCPPT_TEXT('\n');

	// Give the grid one more row and column and initialize those with 42.
	fcppt::container::grid::resize_preserve_init(
		grid,
		int2d_grid::dim(
			3u,
			4u
		),
		42
	);

	fcppt::io::cout()
		<< grid
		<< FCPPT_TEXT('\n');
}

}
//! [grid_resize]

namespace
{
//! [grid_interpolate]
typedef fcppt::container::grid::object<
	float,
	2
> float2d_grid;

typedef fcppt::math::vector::static_<float,2> float2d_vector;

void
interpolate_grid()
{
	float2d_grid grid(
		float2d_grid::dim(
			2u,
			2u
		),
		fcppt::no_init{}
	);

	grid[float2d_grid::pos( 0u, 0u)] = 0.0f;
	grid[float2d_grid::pos( 0u, 1u)] = 1.0f;
	grid[float2d_grid::pos( 1u, 0u)] = 2.0f;
	grid[float2d_grid::pos( 1u, 1u)] = 3.0f;

	float const result =
		fcppt::container::grid::interpolate(
			grid,
			float2d_vector(0.5f,0.5f),
			fcppt::math::interpolation::linear_functor());

	// Will bilinearly interpolate ALL the grid points and return something
	// inbetween (too lazy to calculate)
	std::cout << result << '\n';
}
//! [grid_interpolate]
}

int
main()
{
	init();

	use_grid();

	resize_grid();

	interpolate_grid();
}
