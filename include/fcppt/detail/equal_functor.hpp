//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_EQUAL_FUNCTOR_HPP_INCLUDED
#define FCPPT_DETAIL_EQUAL_FUNCTOR_HPP_INCLUDED


namespace fcppt
{
namespace detail
{

struct equal_functor
{
	template<
		typename T
	>
	inline
	bool
	operator()(
		T const &_t1,
		T const &_t2
	) const
	{
		return
			_t1 == _t2;
	}
};

}
}

#endif
