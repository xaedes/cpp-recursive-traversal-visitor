# cpp-recursive-traversal-visitor

Allows traversal of arbitrary tree types, like this:

    root.visit([](auto& visit, const Node<std::string>* node){
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

    root.visit([](auto& visit, const Node<std::string>* node){
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


Benchmark results:

    N=6      string Node<value_type> 233.329 ns 6.30101 ns ShrPtrNode<value_type> 431.725 ns 54.4652 ns
    N=6      int    Node<value_type> 224.196 ns 2.73739 ns ShrPtrNode<value_type> 448.852 ns 82.2795 ns
    N=111    string Node<value_type> 3.24 us 79.2245 ns    ShrPtrNode<value_type> 7.277 us 150.112 ns
    N=111    int    Node<value_type> 3.13467 us 62.6105 ns ShrPtrNode<value_type> 7.2582 us 146.249 ns
    N=1111   string Node<value_type> 33.372 us 5.26756 us  ShrPtrNode<value_type> 72.24 us 6.3245 us
    N=1111   int    Node<value_type> 31.148 us 956.16 ns   ShrPtrNode<value_type> 73.108 us 7.56967 us
    N=19531  string Node<value_type> 618.082 us 15.5189 us ShrPtrNode<value_type> 1.30117 ms 72.2565 us
    N=19531  int    Node<value_type> 586.303 us 10.5162 us ShrPtrNode<value_type> 1.28023 ms 39.1281 us
    N=488281 string Node<value_type> 18.1962 ms 228.283 us ShrPtrNode<value_type> 43.3153 ms 488.359 us
    N=488281 int    Node<value_type> 16.9122 ms 324.481 us ShrPtrNode<value_type> 40.7258 ms 530.199 us
