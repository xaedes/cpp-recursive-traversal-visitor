#pragma once

#include <functional>
#include <vector>

namespace recursive_traversal_visitor
{

    template <typename pointer_t, typename child_iterator_provider_t>
    struct Visitor
    {
        using pointer_type = pointer_t;
        using child_iterator_provider_type = child_iterator_provider_t;
        using child_iterator_type = typename child_iterator_provider_type::child_iterator_type;
        using visitor_type = Visitor<pointer_t, child_iterator_provider_type>;

        struct Visit
        {
            Visit(Visitor& visitor, const pointer_type& item, int depth, int indexInParent)
                : visitor(visitor)
                , item(item)
                , depth(depth)
                , indexInParent(indexInParent)
            {}

        protected:
            Visitor& visitor;

        public:
            const pointer_type& item;

            const int depth;
            const int indexInParent;

            void all()
            {
                visitor.all();
            };
            void skipChildren()
            {
                visitor.skipChildren();
            };
            void children()
            {
                visitor.children();
            };
        };

        using CallbackType = std::function<void(Visitor::Visit& visit, const pointer_type ptr)>;

        static const int UNLIMITED_RECURSION = -1;

        Visitor(const pointer_type& root, const CallbackType& cb, int maxRecursionDepth = UNLIMITED_RECURSION, int startRecursionDepth = 0, bool includeNull = false, int initialStackCapacity = 10)
            : root(root)
            , cb(cb)
            , maxRecursionDepth(maxRecursionDepth)
            , startRecursionDepth(startRecursionDepth)
            , includeNull(includeNull)
        {
            stack.reserve(initialStackCapacity);
        }

        struct Phase
        {
            bool stopBefore = false;
            bool started = false;
            bool ended = false;
            bool stopAfter = false;

            bool finished() const { return (!stopBefore && started && ended && !stopAfter); }
        };
        struct Item
        {
            // current item info
            pointer_type ptr = nullptr;
            int depth = 0;
            int indexInParent = 0;

            child_iterator_type childIterator;
            int childIndex = 0;

            Phase visitPhase;
            Phase childrenPhase;

            bool finished() const { return (visitPhase.finished() && childrenPhase.finished()); }
        };

        const pointer_type& root;
        const CallbackType& cb;

        int startRecursionDepth;
        int maxRecursionDepth;
        bool includeNull;
        std::vector<Item> stack;

        bool unlimitedRecursion() const { return maxRecursionDepth == UNLIMITED_RECURSION; }


        void invoke(Item& item)
        {
            Visit visit(*this, item.ptr, item.depth, item.indexInParent);
            if (item.ptr) cb(visit, item.ptr);
        }

        bool finished()
        {
            return (stack.size() == 0);
        }

        void reset()
        {
            stack.clear();
            Item start;
            start.ptr = root;
            start.childIterator = child_iterator_provider_type::begin(start.ptr);
            stack.push_back(start);
        }

        int all()
        {
            reset();
            int count = 0;
            while (stack.size() > 0)
            {
                count += next();
            };
            return count;
        }

        int next()
        {
            if (finished()) return 0;

            // visit next item. we may skip some, so we need to iterate. maybe there are no items to visit left after all.
            while (stack.size() > 0)
            {
                auto item = &stack.back();

                if (item->visitPhase.stopBefore && !item->visitPhase.started)
                {
                    item->visitPhase.stopBefore = false;
                    return 0;
                }
                if (item->visitPhase.stopAfter && item->visitPhase.started && item->visitPhase.ended)
                {
                    // perform pre visit (pre children)
                    item->visitPhase.stopAfter = false;
                    return 0;
                }
                if (item->childrenPhase.stopBefore && !item->childrenPhase.started)
                {
                    item->childrenPhase.stopBefore = false;
                    return 0;
                }
                if (item->childrenPhase.stopAfter && item->childrenPhase.started && item->childrenPhase.ended)
                {
                    item->childrenPhase.stopAfter = false;
                    return 0;
                }

                const bool recursion_limit_exceeded = (
                    !unlimitedRecursion() && (startRecursionDepth + item->depth > maxRecursionDepth)
                    );
                const bool excluded_because_nullptr = (!includeNull && item->ptr == nullptr);
                const bool item_finished = item->finished();
                if (item_finished || recursion_limit_exceeded || excluded_because_nullptr)
                {
                    stack.pop_back();
                    continue;
                }




                if (!item->visitPhase.stopBefore && !item->visitPhase.started && !item->visitPhase.ended)
                {
                    item->visitPhase.started = true;
                    int idx = stack.size() - 1;
                    invoke(*item);
                    // invoke may reallocate the stack 
                    // the item at the current idx should refer to the same node, because it will only get dropped when visitPhase.ended == true)
                    item = &stack[idx];
                    item->visitPhase.ended = true;
                    return 1;
                }

                // if loop over children not completed
                if (!item->childrenPhase.stopBefore && !item->childrenPhase.started && !item->childrenPhase.ended)
                {
                    item->childrenPhase.started = true;
                }
                if (!item->childrenPhase.stopBefore && item->childrenPhase.started && !item->childrenPhase.ended)
                {
                    bool stay_in_recursion_limit = (
                        unlimitedRecursion() || (startRecursionDepth + item->depth + 1 <= maxRecursionDepth)
                        );
                    if (!stay_in_recursion_limit)
                    {
                        item->childrenPhase.ended = true;
                        // don't recurse below current item (pre visit is ok!)
                        continue;
                    }

                    // originally we iterate over this for loop.
                    //
                    // for( item->state.childIndex=0;
                    // item->state.childIndex<m_children.size(); ++item->state.childIndex
                    // ).
                    //
                    // here we broke up the indiviual loop iterations.
                    // item->state.childIndex is initialized to zero, so after pre visit
                    // the for loop already started, and we dont need to initialize
                    // again.

                    if (child_iterator_provider_type::containsMore(item->ptr, item->childIterator)) // loop condition
                    {
                        pointer_t child = child_iterator_provider_type::get(item->childIterator);
                        bool child_excluded_because_nullptr = (
                            !includeNull && (child == nullptr)
                            );
                        if (!child_excluded_because_nullptr)
                        {
                            Item nextItem;
                            nextItem.ptr = child;
                            nextItem.depth = item->depth + 1; // item->state.depth + 1 should be m_stack.size() 
                            nextItem.indexInParent = item->childIndex;
                            nextItem.childIterator = child_iterator_provider_type::begin(nextItem.ptr);
                            nextItem.childIndex = 0;
                            nextItem.visitPhase = Phase{};
                            nextItem.childrenPhase = Phase{};
                            stack.push_back(nextItem);
                            // reference `item` is now invalid, as push_back may reallocate the stack, and needs to be refreshed
                            item = &stack[stack.size() - 2];
                        }
                        // loop counter increase
                        ++item->childIndex;
                        child_iterator_provider_type::advance(item->childIterator);
                    }
                    else
                    {
                        // loop exit
                        item->childrenPhase.ended = true;
                    }
                }
            }

            // we found no further items
            return 0;
        }


        void skipChildren()
        {
            if (finished()) return;
            auto& item = stack.back();
            //if (item.childrenPhase.stopBefore) return;
            item.childrenPhase.stopBefore = false;
            item.childrenPhase.started = true;
            item.childrenPhase.ended = true;
            item.childrenPhase.stopAfter = false;
            cleanupFinished();
        }

        void children()
        {
            if (finished()) return;
            auto& item = stack.back();
            item.childrenPhase.stopAfter = true;
            while (next());
        }

    protected:
        void cleanupFinished()
        {
            while (stack.size() > 0 && stack.back().finished())
                stack.pop_back();
        }
    };

} // namespace recursive_traversal_visitor
