#include "gtest.h"
#include "TStack.h"

TEST(TStack, can_create_Stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, can_push_elem)
{
	TStack<int> st;
	st.Push(4);
	st.Look();

	EXPECT_EQ(4, st.Look());
}

TEST(TStack, can_pop_the_element)
{
	TStack <int> st;
	st.Push(5);
	st.Push(7);
	st.Pop();

	EXPECT_EQ(5, st.Look());
}

TEST(TStack, can_put_elem)
{
	TStack<int> st;

	ASSERT_NO_THROW(st.Push(3));
}

TEST(TStack, can_clear)
{
	TStack<int> st;

	st.Push(3);

	ASSERT_NO_THROW(st.Clr());
}

TEST(TStack, clear_stack_is_empty)
{
	TStack<int> st;

	st.Push(3);
	st.Clr();

	EXPECT_EQ(false, st.IsEmpty());
}

TEST(TStack, can_look_elem)
{
	TStack<int> st;

	st.Push(3);

	EXPECT_EQ(3, st.Look());
}