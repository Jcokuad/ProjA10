//tests/test_stack_queue_utils.cpp

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"
//#include "stackqueue/deque.hpp"
#include "stackqueue/array_queue.hpp"
#include "stackqueue/stack_queue_utils.hpp"

#include <string>

TEST_CASE("Test stack for correct operation") {
    dsac::stackqueue::stack<int> st;

    REQUIRE(st.empty()); // should be initially empty 
    
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);

    REQUIRE(st.size() == 4); // correct initial size and top of stack
    REQUIRE(st.top() == 20);

    st.pop(); // check for correct top after popping
    REQUIRE(st.size() == 3);
    REQUIRE(st.top() == 15);
    
    st.pop(); // fully empty the stack and check for empty
    st.pop();
    st.pop();
    REQUIRE(st.size() == 0);
    REQUIRE(st.empty());
}

TEST_CASE("Test queue for correct operation") {
    dsac::stackqueue::queue<int> qu;

    REQUIRE(qu.empty()); // should be initially empty 
    
    qu.push(5);
    qu.push(10);
    qu.push(15);
    qu.push(20);

    REQUIRE(qu.size() == 4); // correct initial size and top of stack
    REQUIRE(qu.front() == 5);

    qu.pop(); // check for correct top after popping
    REQUIRE(qu.size() == 3);
    REQUIRE(qu.front() == 10);
    
    qu.pop(); // fully empty the stack and check for empty
    qu.pop();
    qu.pop();
    REQUIRE(qu.size() == 0);
    REQUIRE(qu.empty());
}

TEST_CASE("Test remove duplicates for correct operation") {
    REQUIRE(remove_duplicates("abbaca") == "ca");
    REQUIRE(remove_duplicates("abccba") == "");
    REQUIRE(remove_duplicates("") == "");
    REQUIRE(remove_duplicates("abcde") == "abcde");
    REQUIRE(remove_duplicates("aaaaa") == "a");
    REQUIRE(remove_duplicates("aaaa") == "");
    REQUIRE(remove_duplicates("1122334455") == "");
    REQUIRE(remove_duplicates("abbaa") == "a");
}

TEST_CASE("Test clean backspace for correct operation") {
    REQUIRE(clean_backspace_string("ab<c") == "ac");
    REQUIRE(clean_backspace_string("ab<<") == "");
    REQUIRE(clean_backspace_string("a<<b<<") == "");
    REQUIRE(clean_backspace_string("<") == "");
    REQUIRE(clean_backspace_string("<<a") == "a");
    REQUIRE(clean_backspace_string("a<bc<d") == "bd");
}

TEST_CASE("Test stack that it finds element and returns to original order") {
    dsac::stackqueue::stack<int> st;
    dsac::stackqueue::queue<int> qu;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    REQUIRE(stack_contains(st, qu, 4) == true);
    REQUIRE(stack_contains(st, qu, 10) == false);
    REQUIRE(stack_contains(st, qu, -1) == false);
    REQUIRE(stack_contains(st, qu, 1) == true);
    REQUIRE(qu.empty());

    //Check that it is returned to original order
    REQUIRE(st.top() == 5);
    st.pop();
    REQUIRE(st.top() == 4);
    st.pop();
    REQUIRE(st.top() == 3);
    st.pop();
    REQUIRE(st.top() == 2);
    st.pop();
    REQUIRE(st.top() == 1);
    st.pop();

    REQUIRE(st.empty());

    // Test empty stack
    REQUIRE(stack_contains(st, qu, 4) == false);
}
