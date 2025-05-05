/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, four_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( true, object.match("aabb") );
}

TEST(GuesserTest, correct_of1_correct_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( true, object.match("aabb") );
}

TEST(GuesserTest, correct_off2_correct_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( false, object.match("bbbb") );
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( true, object.match("aabb") );
}

TEST(GuesserTest, correct_off3_correct_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( false, object.match("bbab") );
  ASSERT_EQ( false, object.match("aabb") );
  ASSERT_EQ( false, object.match("aabb") );
}

TEST(GuesserTest, correct_off4_correct_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( false, object.match("bbab") );
  ASSERT_EQ( false, object.match("aabb") );
  ASSERT_EQ( false, object.match("aabb") );
}

TEST(GuesserTest, off1_off1_off1_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("aabb") );
}

TEST(GuesserTest, off1_off3_correct_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("bbab") );
  ASSERT_EQ( false, object.match("aabb") );
  ASSERT_EQ( false, object.match("aabb") );
}

TEST(GuesserTest, off1_off1_correct_off1_correct)
{
  Guesser object("aabb");
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( true, object.match("aabb") );
  ASSERT_EQ( false, object.match("abbb") );
  ASSERT_EQ( false, object.match("aabb") );
}

TEST(GuesserTest, test_empty_string)
{
  Guesser object("");
  ASSERT_EQ( true, object.match("") );
}


