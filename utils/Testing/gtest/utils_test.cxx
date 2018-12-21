#include <iostream>
#include "first.h"
#include "log.h"
#include <gtest/gtest.h>

using namespace hsssg;
// IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(IndependentMethod, ResetsToZero) {

	std::cout << "Log Initialize Async" << std::endl;;
	std::string path = "utils_log";
	app::LogInitializeAsync(path);

	BOOST_LOG_TRIVIAL(trace) << "My first trace";

	HSSSG_LOG_TRACE << "My first trase use HSSSG_LOG_TRACE";
	HSSSG_LOG_DEBUG << "My first debug use HSSSG_LOG_DEBUG";
	HSSSG_LOG_FATAL << "My first fatal use HSSSG_LOG_FATAL";
	HSSSG_LOG_ERROR << "My first error use HSSSG_LOG_ERROR";
	HSSSG_LOG_WARNING << "My first warn use HSSSG_LOG_WARNING";
	HSSSG_LOG_INFO << "My first fatal info HSSSG_LOG_INFO";

	std::cout << "Here writing message to log" << std::endl;

	trivialLog();

	int i = 3;
	// independentMethod(i);
	EXPECT_EQ(0, i);

	// i = 12;
	// independentMethod(i);
	EXPECT_EQ(0,i);

	/**
	* Sinks async stop
	*/
	std::cout << "Log Stop Async" << std::endl;;
	app::LogStopAsync();

}

TEST(IndependentMethod, ResetsToZero2) {
	int i = 0;
	// independentMethod(i);
	EXPECT_EQ(0, i);
}
//
//// The fixture for testing class Project1. From google test primer.
//class Project1Test : public ::testing::Test {
//protected:
//	// You can remove any or all of the following functions if its body
//	// is empty.
//
//	Project1Test() {
//		// You can do set-up work for each test here.
//	}
//
//	virtual ~Project1Test() {
//		// You can do clean-up work that doesn't throw exceptions here.
//	}
//
//	// If the constructor and destructor are not enough for setting up
//	// and cleaning up each test, you can define the following methods:
//	virtual void SetUp() {
//		// Code here will be called immediately after the constructor (right
//		// before each test).
//	}
//
//	virtual void TearDown() {
//		// Code here will be called immediately after each test (right
//		// before the destructor).
//	}
//
//	// Objects declared here can be used by all tests in the test case for Project1.
//	// Project1 p;
//};
//
//// Test case must be called the class above
//// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
//TEST_F(Project1Test, MethodBarDoesAbc) {
//	int i = 0;
//	// p.foo(i); // we have access to p, declared in the fixture
//	EXPECT_EQ(1, i);
//}
