#include <stdio.h>

#include "ktest/ktest.h"

namespace KWorks {
namespace Tests {

void print(const char *msg) {
	printf(msg);
	printf("\n");
}

void print(const char *msg, int a, int b, const char *extra) {
	printf(msg, a, b, extra);
	printf("\n");
}

DEF_TEST(dummy, ;)

DEF_TEST(adding_works,
	ASSERT_TRUE(1 + 1 == 2);
)

DEF_TEST(assign_possible,
	int number = 1;
	ASSERT_TRUE(number == 1);
)

DEF_TEST(multiple_assert_tests,
	int i = 0;
	ASSERT_TRUE(++i == 1);
	ASSERT_TRUE(++i == 2);
	ASSERT_TRUE(++i == 3);
)

DEF_TEST(failing_test,
	ASSERT_TRUE(1 + 1 == 4);
)

DEF_TEST(test_assert_false,
	ASSERT_FALSE(1 == 2);
)

DEF_TEST(test_assert_eq,
	ASSERT_EQUALS((1 + 1), 2);
)

struct PointerTestTarget {
	int a;
	int b;

	PointerTestTarget(int a, int b) : a(a), b(b) {}
	~PointerTestTarget() {}
};

struct BasicMock {
	int i;
	PointerTestTarget *j;
};

DEF_MOCK_SETUP(basic_mock, BasicMock,
	target.i = 2;
	target.j = new PointerTestTarget(0, 3);
)

DEF_MOCK_TEARDOWN(basic_mock, BasicMock,
	delete target.j;
)

DEF_TEST(mock_setup_and_teardown,
	BasicMock basicMock;
	MOCK_SETUP(basic_mock, basicMock);
	ASSERT_TRUE(basicMock.i == 2);
	ASSERT_TRUE(basicMock.j->a == 0);
	ASSERT_TRUE(basicMock.j->b == 3);
	MOCK_TEARDOWN(basic_mock, basicMock);
)

TestCase tests[] = {
	// Framework tests
	TEST_CASE("Dummy", dummy),
	TEST_CASE("One Plus one is two", adding_works),
	TEST_CASE("Test framework allows assignments", assign_possible),
	TEST_CASE("Multiple asserts allowed", multiple_assert_tests),
	TEST_CASE("This is supposed to fail", failing_test),
	TEST_CASE("One is different than two", test_assert_false),
	TEST_CASE("One plus one is still two", test_assert_eq),
	TEST_CASE("We can assign values in mocks", mock_setup_and_teardown),
	TEST_CASE_END_SUITE()
};

} // End of namespace KWorks::Tests
} // End of namespace KWorks
