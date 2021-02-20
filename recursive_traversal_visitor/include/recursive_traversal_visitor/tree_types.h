#pragma once

#include <memory>
#include <vector>

//#include "recursive_traversal_visitor/child_iterator_provider.h"
#include "recursive_traversal_visitor/visitor.h"

namespace recursive_traversal_visitor
{
    template <typename node_type>
    struct ChildrenOwningNodeChildIteratorProvider //  : public ChildIteratorProvider<node_type*,node_type**>
    {
        using pointer_type = node_type*;
        using child_iterator_type = typename std::vector<node_type>::iterator;

        inline static pointer_type get(const child_iterator_type& it)
        {
            return &*it;
        }
        inline static child_iterator_type begin(const pointer_type& ptr)
        {
            return ptr->children.begin();
        }
        inline static bool containsMore(const pointer_type& ptr, const child_iterator_type& it)
        {
            return it < ptr->children.end();
        }
        inline static void advance(child_iterator_type& it)
        {
            ++it;
        }
    };

    template <typename node_type, typename pointer_type>
    struct PtrChildrenNodeChildIteratorProvider //  : public ChildIteratorProvider<node_type*,node_type**>
    {
        //using pointer_type = node_type*;
        using child_iterator_type = typename std::vector<pointer_type>::iterator;

        inline static pointer_type get(const child_iterator_type& it)
        {
            return *it;
        }
        inline static child_iterator_type begin(const pointer_type& ptr)
        {
            return ptr->children.begin();
        }
        inline static bool containsMore(const pointer_type& ptr, const child_iterator_type& it)
        {
            return it < ptr->children.end();
        }
        inline static void advance(child_iterator_type& it)
        {
            ++it;
        }
    };


    template <typename value_type>
    struct Node
    {
        using node_type = Node<value_type>;
        value_type value;
        std::vector<node_type> children;
        using visitor_type = Visitor<node_type*, ChildrenOwningNodeChildIteratorProvider<node_type>>;
        void visit(const typename visitor_type::CallbackType& cb)
        {
            visitor_type visitor(this, cb);
            visitor.all();
        };
    };

    template <typename value_type>
    struct ShrPtrNode
    {
        using node_type = ShrPtrNode<value_type>;
        using pointer_type = std::shared_ptr<ShrPtrNode<value_type>>;

        static pointer_type Create(const value_type& value, const std::vector<pointer_type>& children)
        {
            auto ptr = std::shared_ptr<node_type>(new ShrPtrNode(value, children));
            ptr->pointer = ptr;
            return ptr;
        }

        pointer_type pointer;
        value_type value;
        std::vector<pointer_type> children;

        using visitor_type = Visitor<pointer_type, PtrChildrenNodeChildIteratorProvider<node_type, pointer_type>>;
        void visit(const typename visitor_type::CallbackType& cb)
        {
            visitor_type visitor(pointer, cb);
            visitor.all();
        };
    protected:
        ShrPtrNode()
        {}
        ShrPtrNode(const value_type& value, const std::vector<pointer_type>& children)
            : value(value), children(children)
        {}
    };

}
