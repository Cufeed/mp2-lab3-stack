#include "../build/stack/MyStack.h"

#include <gtest.h>

//TEST(Vector, throws_when_create_vector_with_negative_size)
//{
//}
TEST(Stack, can_create_stack_with_positive_length) {
	ASSERT_NO_THROW(TStack<int> m(5));
}


TEST(Stack, can_get_size)
{
	TStack<int> m(5);
	ASSERT_TRUE(m.GetSize() == 5);
}


TEST(Stack, cant_push_with_full_elements)
{
	TStack<int> m(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	ASSERT_ANY_THROW(m.Push(5));
}
TEST(Stack, is_full) {
	TStack<int> m(5);
	ASSERT_NO_THROW(m.IsFull());
}

TEST(Stack, is_empty)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m.IsEmpty());
}

TEST(Stack, is_empty_check)
{
	TStack<int> m(5);
	ASSERT_EQ(m.IsEmpty(),true);
}


TEST(Stack, cant_create_stack_with_negative_length) {
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(Stack, cant_get_stack_with_empty_elements) {
	TStack<int> m(5);
	ASSERT_ANY_THROW(m.Get());
}


//TEST(Vector, thorws_when_index_argument_is_negative) {
//}
//

TEST(Queue, can_create_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> m(5));
}

TEST(Queue, cant_create_queue_with_pnegative_length) {
	ASSERT_ANY_THROW(TQueue<int> m(-5));
}

TEST(Queue, is_empty)
{
	TQueue<int> m(5);
	ASSERT_NO_THROW(m.IsEmpty());
}

TEST(Queue, is_full) {
	TQueue<int> m(5);
	ASSERT_NO_THROW(m.IsFull());
}

TEST(Queue, is_empty_check)
{
	TQueue<int> m(5);
	ASSERT_EQ(m.IsEmpty(),true);
}

TEST(Queue, is_full_check)
{
	TQueue<int> m(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	ASSERT_EQ(m.IsFull(), true);
}



TEST(Queue, cant_push_with_full_elements)
{
	TQueue<int> m(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	m.Push(5);
	ASSERT_ANY_THROW(m.Push(5));
}

TEST(Queue, cant_get_stack_with_empty_elements) {
	TQueue<int> m(5);
	ASSERT_ANY_THROW(m.Get());
}

//TEST(Vector, thorws_when_index_argument_more_or_eq_size) {
//}
//
//TEST(Vector, can_use_index_operator) {
//}
//
//TEST(Vector, can_compare_vectors_true) {
//}
//
//TEST(Vector, can_compare_vectors_false_with_one_size) {
//}
//
//TEST(Vector, can_compare_vectors_false_with_diff_size) {
//}
//
//TEST(Vector, can_assign_vector) {
//}
//
//TEST(Vector, can_prefix_increment) {
//}
//
//TEST(Vector, can_postfix_increment)
//{
//}
//
//TEST(Vector, can_prefix_decrement)
//{
//}
//
//TEST(Vector, can_postfix_decrement)
//{
//}
//
//TEST(Vector, can_unary_addition)
//{
//}
//
//TEST(Vector, can_unary_subtraction)
//{
//}
//
//TEST(Vector, can_addition_vectors)
//{
//}
//
//TEST(Vector, thorws_when_addition_vectors_with_diff_size) 
//{
//}
//
//TEST(Vector, can_subtraction_vectors)
//{
//}
//
//TEST(Vector, thorws_when_subtraction_vectors_with_diff_size)
//{
//}
//
//TEST(Vector, can_multiplication_vectors) 
//{
//}
//
//TEST(Vector, throws_when_multiplication_vectors_with_diff_size)
//{
//}
//
//TEST(Vector, can_multiplication_vector_by_number) 
//{
//}
//
//TEST(Vector, can_multiplication_number_by_vector)
//{
//}