//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_MAP_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_MAP_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Functor,
	typename TargetValue,
	typename SourceArray
>
class array_map_function
{
	FCPPT_NONASSIGNABLE(
		array_map_function
	);
public:
	array_map_function(
		Functor const &_functor,
		SourceArray const &_source
	)
	:
		functor_(
			_functor
		),
		source_(
			_source
		)
	{
	}

	template<
		typename Index
	>
	TargetValue
	operator()(
		Index
	) const
	{
		return
			functor_(
				source_[
					Index::value
				]
			);
	}
private:
	Functor const functor_;

	SourceArray const &source_;
};

}
}
}

#endif
