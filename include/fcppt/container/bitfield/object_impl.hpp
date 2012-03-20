//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/container/array_impl.hpp>
#include <fcppt/container/bitfield/iterator_impl.hpp>
#include <fcppt/container/bitfield/object_decl.hpp>
#include <fcppt/container/bitfield/proxy_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/bitwise.hpp>
#include <boost/spirit/home/phoenix/operator/comparison.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::object<Enum, Size, InternalType>::boolean_test() const
{
	return
		algorithm::contains_if(
			array_.begin(),
			array_.end(),
			boost::phoenix::arg_names::arg1
			!= static_cast<InternalType>(0)
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType>::object()
{}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType>::object(
	Enum const _index
)
{
	clear();

	set(
		_index,
		true
	);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> &
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator=(
	Enum const _index
)
{
	clear();

	set(
		_index,
		true
	);

	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::begin()
{
	return
		iterator(
			array_,
			0
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::begin() const
{
	return
		const_iterator(
			array_,
			0
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::end()
{
	return
		iterator(
			array_,
			static_cast<
				typename iterator::difference_type
			>(
				size()
			)
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::end() const
{
	return
		const_iterator(
			array_,
			static_cast<
				typename const_iterator::difference_type
			>(
				size()
			)
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::rbegin()
{
	return reverse_iterator(end());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::rbegin() const
{
	return const_reverse_iterator(end());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::rend()
{
	return reverse_iterator(begin());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::rend() const
{
	return const_reverse_iterator(begin());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::cbegin() const
{
	return begin();
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::	const_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::cend() const
{
	return end();
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::	const_reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::crbegin() const
{
	return rbegin();
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::	const_reverse_iterator
fcppt::container::bitfield::object<Enum, Size, InternalType>::crend() const
{
	return rend();
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::size_type
fcppt::container::bitfield::object<
	Enum,
	Size,
	InternalType
>::size() const
{
	return Size;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::const_reference
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator[](
	Enum const _index
) const
{
	return *(begin() + _index);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename fcppt::container::bitfield::object<Enum, Size, InternalType>::reference
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator[](
	Enum const _index
)
{
	return *(begin() + _index);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType>&
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator|=(
	Enum const _index
)
{
	set(
		_index,
		true
	);

	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> &
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator|=(
	object<Enum, Size, InternalType> const &_other
)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		args::arg1 | args::arg2
	);
	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType>&
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator&=(
	object<Enum, Size, InternalType> const &_other
)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		args::arg1 & args::arg2
	);

	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType>&
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator^=(
	object<Enum, Size, InternalType> const &_other
)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array_.begin(),
		array_.end(),
		_other.array_.begin(),
		array_.begin(),
		args::arg1 ^ args::arg2
	);
	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator~() const
{
	object ret;

	namespace args = boost::phoenix::arg_names;

	std::transform(
		array_.begin(),
		array_.end(),
		ret.array_.begin(),
		~args::arg1
	);

	return ret;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator==(
	object const &_other
) const
{
	return
		std::equal(
			array_.begin(),
			array_.end(),
			_other.array_.begin()
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator<(
	object const &_other
) const
{
	return
		std::lexicographical_compare(
			array_.begin(),
			array_.end(),
			_other.array_.begin(),
			_other.array_.end()
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator!() const
{
	return !boolean_test();
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::value_type
fcppt::container::bitfield::object<Enum, Size, InternalType>::operator&(
	Enum const _index
) const
{
	return
		this->get(
			_index
		);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
void
fcppt::container::bitfield::object<Enum, Size, InternalType>::set(
	Enum const _index,
	value_type const _value
)
{
	(*this)[_index] = _value;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::value_type
fcppt::container::bitfield::object<Enum, Size, InternalType>::get(
	Enum const _index
) const
{
	return (*this)[_index];
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
void
fcppt::container::bitfield::object<Enum, Size, InternalType>::clear()
{
	array_.fill(
		0
	);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
void
fcppt::container::bitfield::object<Enum, Size, InternalType>::swap(
	object &_other
)
{
	std::swap(
		array_,
		_other.array_
	);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::object<Enum, Size, InternalType>::null()
{
	object ret;

	ret.clear();

	return ret;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::operator|(
	object<Enum, Size, InternalType> const &_field,
	Enum const _index
)
{
	return
		object<
			Enum,
			Size,
			InternalType
		>(
			_field
		)
		|= _index;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::operator|(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return
		object<
			Enum,
			Size,
			InternalType
		>(
			_left
		)
		|= _right;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::operator&(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return
		object<
			Enum,
			Size,
			InternalType
		>(
			_left
		)
		&= _right;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
fcppt::container::bitfield::object<Enum, Size, InternalType> const
fcppt::container::bitfield::operator^(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return
		object<
			Enum,
			Size,
			InternalType
		>(
			_left
		)
		^= _right;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
void
fcppt::container::bitfield::swap(
	object<Enum, Size, InternalType> &_left,
	object<Enum, Size, InternalType> &_right
)
{
	_left.swap(
		_right
	);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::operator!=(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return !(_left == _right);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::operator<=(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return !(_left > _right);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::operator>(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return _right < _left;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
fcppt::container::bitfield::operator>=(
	object<Enum, Size, InternalType> const &_left,
	object<Enum, Size, InternalType> const &_right
)
{
	return !(_left < _right);
}


#endif