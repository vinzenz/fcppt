MACRO (ADD_FCPPT_TEST name)
	ADD_EXECUTABLE (fcppt${name}test ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcppt${name}test fcppt)
ENDMACRO ()

ADD_FCPPT_TEST(algorithm)
ADD_FCPPT_TEST(array)
ADD_FCPPT_TEST(chrono)
ADD_FCPPT_TEST(codecvt)
ADD_FCPPT_TEST(container)
#ADD_FCPPT_TEST(field)
ADD_FCPPT_TEST(function)
ADD_FCPPT_TEST(io)
ADD_FCPPT_TEST(log)
ADD_FCPPT_TEST(optional)
ADD_FCPPT_TEST(pragmamessage)
ADD_FCPPT_TEST(random)
ADD_FCPPT_TEST(strongtypedef)
ADD_FCPPT_TEST(thread)
ADD_FCPPT_TEST(tree)
ADD_FCPPT_TEST(variant)