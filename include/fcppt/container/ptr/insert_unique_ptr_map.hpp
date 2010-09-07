//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MAP_HPP_INCLUDED

#include <fcppt/type_traits/is_unique_ptr.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace container
{
namespace ptr
{

template<
	typename PtrContainer,
	typename UniquePtr
>
typename boost::enable_if<
	fcppt::type_traits::is_unique_ptr<
		UniquePtr
	>,
	std::pair<
		typename PtrContainer::iterator,
		bool
	>
>::type
insert_unique_ptr_map(
	PtrContainer &_container,
	typename PtrContainer::key_type const &_key,
	UniquePtr _ptr
)
{
	typename PtrContainer::key_type key(
		_key
	);

	return
		_container.insert(
			key,
			_ptr.release()
		);
}

}
}
}

#endif