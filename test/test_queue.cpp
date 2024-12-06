#include "queue.h"

#include <gtest.h>

TEST(QueueTest, can_create_queue) {
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(QueueTest, empty_after_creation) {
    Queue<int> q;
    ASSERT_TRUE(q.empty());
}

TEST(QueueTest, not_empty_after_push) {
    Queue<int> q;
    q.push(10);
    ASSERT_FALSE(q.empty());
}

TEST(QueueTest, push_works) {
    Queue<int> q;
    q.push(10);
    ASSERT_EQ(q.front(), 10);
}

TEST(QueueTest, size_is_correct_after_push) {
    Queue<int> q;
    q.push(1);
    ASSERT_EQ(q.size(), 1);
    q.push(2);
    ASSERT_EQ(q.size(), 2);
}

TEST(QueueTest, front_returns_correct_element) {
    Queue<int> q;
    q.push(10);
    ASSERT_EQ(q.front(), 10);
    q.push(20);
    ASSERT_EQ(q.front(), 10);  
}

TEST(QueueTest, pop_removes_front_element) {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();
    ASSERT_EQ(q.front(), 20);
    ASSERT_EQ(q.size(), 1);
}


TEST(QueueTest, pop_empty_throws) {
    Queue<int> q;
    ASSERT_ANY_THROW(q.pop()); 
}


TEST(QueueTest, front_empty_throws) {
    Queue<int> q;
    ASSERT_ANY_THROW(q.front()); 
}

TEST(QueueTest, circular_wrap_around) {
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }
    for (int i = 1; i <= 5; ++i) {  
        q.pop();
    }
    ASSERT_EQ(q.front(), 6);
    ASSERT_EQ(q.size(), 5);
}