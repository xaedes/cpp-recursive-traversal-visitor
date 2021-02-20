#pragma once

namespace recursive_traversal_visitor
{
    template <typename pointer_t, typename child_iterator_t>
    struct ChildIteratorProvider
    {
        using pointer_type = pointer_t;
        using child_iterator_type = child_iterator_t;

        inline static pointer_type get(const child_iterator_type& it);
        inline static child_iterator_type begin(const pointer_type& ptr);
        inline static bool containsMore(const pointer_type& ptr, const child_iterator_type& it);
        inline static void advance(child_iterator_type& it);
    };
}
