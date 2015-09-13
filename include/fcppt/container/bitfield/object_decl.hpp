//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/container/bitfield/array.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief A statically sized bitfield

\ingroup fcpptcontainerbitfield

\tparam ElementType An integral or enumeration type

\tparam NumElements An integral constant wrapper specifying the number of bits

\tparam InternalType The internal storage type. Must be unsigned. This is
fcppt::container::bitfield::default_internal_type by default

See the \link fcpptcontainerbitfield module description \endlink for more information.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
class object
{
private:
	static_assert(
		std::is_unsigned<
			InternalType
		>::value,
		"InternalType must be unsigned"
	);
public:
	typedef
	fcppt::container::bitfield::array<
		ElementType,
		NumElements,
		InternalType
	>
	array_type;

	/**
	\brief The size of the underlying array
	*/
	typedef
	typename
	fcppt::container::array_size<
		array_type
	>::type
	array_size;

	/**
	\brief Typedef to <code>ElementType</code>
	*/
	typedef
	ElementType
	element_type;

	/**
	\brief The size type which is taken from <code>NumElements</code>
	*/
	typedef
	typename
	NumElements::value_type
	size_type;

	/**
	\brief The value type, which is bool
	*/
	typedef
	fcppt::container::bitfield::value_type
	value_type;

	/**
	\brief Typedef to <code>NumElements</code>
	*/
	typedef
	NumElements
	static_size;

	/**
	\brief Typedef to the internal storage type (template parameter <code>InternalType</code>
	*/
	typedef
	InternalType
	internal_type;

	/**
	\brief A type denoting a reference to a mask value (a reference to a
	boolean, basically).

	Note that this is <em>not</em> a bool or internal_type, but a proxy class.
	*/
	typedef
	fcppt::container::bitfield::proxy<
		array_type
	>
	reference;

	/**
	\brief The bitfield's value type, when viewed as a container.

	This forwards to fcppt::container::bitfield::value_type.
	*/
	typedef
	fcppt::container::bitfield::proxy<
		array_type const
	>
	const_reference;

	/**
	\brief Initializer list type used to initialize a bitfield
	*/
	typedef
	std::initializer_list<
		ElementType
	>
	initializer_list_type;

	/**
	\brief Constructs an uninitialized bitfield
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Constructs a bitfield using an initializer list, setting every
	bit from the list to true
	*/
	explicit
	object(
		initializer_list_type const &
	);

	/**
	\brief Constructs a bitfield from its internal array type
	*/
	explicit
	object(
		array_type const &
	);

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	const_reference
	operator[](
		ElementType
	) const;

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	reference
	operator[](
		ElementType
	);

	/**
	\brief Set the specified bit to <code>true</code>
	*/
	object &
	operator|=(
		ElementType
	);

	/**
	\brief Do a bit-wise "or" for all bits.
	*/
	object &
	operator|=(
		object const &
	);

	/**
	\brief Do a bit-wise "and" for all bits.
	*/
	object &
	operator&=(
		object const &
	);

	/**
	\brief Do a bit-wise "xor" for all bits.
	*/
	object &
	operator^=(
		object const &
	);

	/**
	\brief Do a bit-wise "not" for all bits (inverts all bits)
	*/
	object const
	operator~() const;

	/**
	\brief Checks if the specified bit is set.

	\note
	For some reason VC++ can't find this operator if it is not a member.
	*/
	value_type
	operator &(
		ElementType
	) const;

	/**
	\brief Compares two bitfields component-wise
	*/
	bool
	operator==(
		object const &
	) const;

	/**
	\brief Compares two bitfields lexicographically bit by bit.
	*/
	bool
	operator<(
		object const &
	) const;

	/**
	\brief Sets the specified bit to true/false
	\param where Which bit to set
	\param value The value to set the bit to
	*/
	void
	set(
		ElementType where,
		value_type value
	);

	/**
	\brief Returns if the specified bit is set
	*/
	value_type
	get(
		ElementType
	) const;

	/**
	\brief Accessor to the internal array
	*/
	array_type &
	array();

	/**
	\brief Const accessor to the internal array
	*/
	array_type const &
	array() const;

	/**
	\brief Returns the bitfield with all bits set to zero.
	*/
	static
	object
	null();
private:
	static
	size_type
	to_index(
		ElementType
	);

	array_type array_;
};

/**
\brief Set the specified bit to true
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	ElementType
);

/**
\brief Do a bit-wise "or" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "and" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator&(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "xor" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator^(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "not" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator~(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	>
);

/**
\brief Compares two bitfields component-wise
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator==(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields component-wise
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator!=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

}
}
}

#endif

