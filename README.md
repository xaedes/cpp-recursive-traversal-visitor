# cpp-recursive-traversal-visitor

Allows traversal of arbitrary tree types, like this:

    root.visit([](auto& visit, const NodeStr* node){
        std::string indent = "";
        for (int i=0; i<visit.depth; ++i) indent += "  ";
        std::cout << indent << "<" << node->value << ">" << "\n";
        bool visitChildren = true; // any condition you like
        if (visitChildren)
            visit.children();
        else
            visit.skipChildren();
        std::cout << indent << "</" << node->value << ">" << "\n";
    });
    
or like this for drawing nested ImGui::TreeNode:

    root.visit([](auto& visit, const NodeStr* node){
        if (ImGui::TreeNode(node->value)
        {
            visit.children();
            ImGui::TreePop();
        }
        else
            visit.skipChildren();
    });
    
Example tree types which store children in different ways are defined:

    template <typename value_type>
    struct Node
    {
        using node_type = Node<value_type>;
        value_type value;
        std::vector<node_type> children;
  
        // ...
    }
  
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
        
        // ...
    }
    
To use your own tree types you must provide a ChildIteratorProvider class to tell the visitor how your children nodes are accessed.
You can then instantiate a Visitor object and call it with a callable, most likely a lambda. 
You should define a visit function, which instantiated the visitor and calls it:

    template <typename value_type>
    struct Node
    {
        // ...
        using visitor_type = Visitor<node_type*, ChildrenOwningNodeChildIteratorProvider<node_type>>;
        void visit(const typename visitor_type::CallbackType& cb)
        {
            visitor_type visitor(this, cb);
            visitor.all();
        };
    };
    
The visitor needs a pointer type, but it can be any pointer type (raw pointer, std::shared_ptr, ...).

The ChildIteratorProvider class you provide does not need to derive from ChildIteratorProvider, but it must have the same defined types and static functions.


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
