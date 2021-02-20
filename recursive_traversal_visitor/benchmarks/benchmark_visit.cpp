
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <vector>
#include <string>
#include <sstream>

#include "recursive_traversal_visitor/visitor.h"
#include "recursive_traversal_visitor/tree_types.h"


using namespace recursive_traversal_visitor;
using NodeStr = Node<std::string>;
using ShrPtrNodeStr = ShrPtrNode<std::string>;

using NodeInt = Node<int>;
using ShrPtrNodeInt = ShrPtrNode<int>;

template <typename value_type>
void Benchmark(Node<value_type>& root, typename ShrPtrNode<value_type>::pointer_type& shRoot)
{
    int count = 0;
    root.visit([&count](auto& visit, const Node<value_type>* node) {
        ++count;
    });
    SECTION("iterate counting [N=" + std::to_string(count) + "]")
    {
        BENCHMARK("Node<value_type>::visit")
        {
            int count = 0;
            root.visit([&count](auto& visit, const Node<value_type>* node) {
                ++count;
            });
            return count;
        };
        BENCHMARK("ShrPtrNode<value_type>::visit")
        {
            int count = 0;
            shRoot->visit([&count](auto& visit, const ShrPtrNode<value_type>::pointer_type node) {
                ++count;
            });
            return count;
        };
    }
    SECTION("iterate recursive counting [N=" + std::to_string(count) + "]")
    {
        BENCHMARK("Node<value_type>::visit")
        {
            int count = 0;
            root.visit([&count](auto& visit, const Node<value_type>* node) {
                ++count;
                visit.children();
            });
            return count;
        };
        BENCHMARK("ShrPtrNode<value_type>::visit")
        {
            int count = 0;
            shRoot->visit([&count](auto& visit, const ShrPtrNode<value_type>::pointer_type node) {
                ++count;
                visit.children();
            });
            return count;
        };
    }
    SECTION("to xml [N=" + std::to_string(count) + "]")
    {
        BENCHMARK("Node<value_type>::visit")
        {
            std::stringstream ss;
            root.visit([&ss](auto& visit, const Node<value_type>* node) {
                ss << "<" << node->value << ">";
                visit.children();
                ss << "</" << node->value << ">";
            });
            return ss.str();
        };
        BENCHMARK("ShrPtrNode<value_type>::visit")
        {
            std::stringstream ss;
            shRoot->visit([&ss](auto& visit, const ShrPtrNode<value_type>::pointer_type node) {
                ss << "<" << node->value << ">";
                visit.children();
                ss << "</" << node->value << ">";
            });
            return ss.str();
        };
    }
}

TEST_CASE("tiny tree string", "[benchmark][recursive_traversal_visitor]")
{
    
    int k = 0;
    NodeStr root = {std::to_string(k++), {
        {std::to_string(k++), {}},
        {std::to_string(k++), {
            {std::to_string(k++), {}},
            {std::to_string(k++), {}}
        }},
        {std::to_string(k++), {}}
    }};
    k = 0;
    auto shRoot = ShrPtrNodeStr::Create(std::to_string(k++), {
        ShrPtrNodeStr::Create(std::to_string(k++), {}),
        ShrPtrNodeStr::Create(std::to_string(k++), {
            ShrPtrNodeStr::Create(std::to_string(k++), {}),
            ShrPtrNodeStr::Create(std::to_string(k++), {})
        }),
        ShrPtrNodeStr::Create(std::to_string(k++), {})
    });

    Benchmark(root, shRoot);
}

TEST_CASE("tiny tree int", "[benchmark][recursive_traversal_visitor]")
{
    int k = 0;
    NodeInt root = { k++, {
        {k++, {}},
        {k++, {
            {k++ , {}},
            {k++ , {}}
        }},
        {k++, {}}
    } };
    k = 0;
    auto shRoot = ShrPtrNodeInt::Create(k++, {
        ShrPtrNodeInt::Create(k++, {}),
        ShrPtrNodeInt::Create(k++, {
            ShrPtrNodeInt::Create(k++, {}),
            ShrPtrNodeInt::Create(k++, {})
        }),
        ShrPtrNodeInt::Create(k++, {})
        });

    Benchmark(root, shRoot);
}

NodeStr createTree(int& id, int num_children, int num_levels)
{
    NodeStr tree{ std::to_string(id) };
    if (num_levels > 0)
    for (int i = 0; i < num_children; ++i)
    {
        tree.children.push_back(createTree(++id, num_children, num_levels - 1));
    }
    return tree;
}

ShrPtrNodeStr::pointer_type createShTree(int& id, int num_children, int num_levels)
{
    auto tree = ShrPtrNodeStr::Create(std::to_string(id), {} );
    if (num_levels > 0)
    for (int i = 0; i < num_children; ++i)
    {
        tree->children.push_back(createShTree(++id, num_children, num_levels - 1));
    }
    return tree;
}


NodeInt createTreeInt(int& id, int num_children, int num_levels)
{
    NodeInt tree{ id };
    if (num_levels > 0)
    for (int i = 0; i < num_children; ++i)
    {
        tree.children.push_back(createTreeInt(++id, num_children, num_levels - 1));
    }
    return tree;
}

ShrPtrNodeInt::pointer_type createShTreeInt(int& id, int num_children, int num_levels)
{
    auto tree = ShrPtrNodeInt::Create( id, {} );
    if (num_levels > 0)
    for (int i = 0; i < num_children; ++i)
    {
        tree->children.push_back(createShTreeInt(++id, num_children, num_levels - 1));
    }
    return tree;
}

TEST_CASE("small tree string", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 2;
    int num_children = 10;
    int k = 0, i = 0;

    NodeStr root = createTree(k, num_children, num_levels);
    ShrPtrNodeStr::pointer_type shRoot = createShTree(i, num_children, num_levels);


    Benchmark(root, shRoot);
}

TEST_CASE("small tree int", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 2;
    int num_children = 10;
    int k = 0, i = 0;
    auto root = createTreeInt(k, num_children, num_levels);
    auto shRoot = createShTreeInt(i, num_children, num_levels);

    Benchmark(root, shRoot);
}

TEST_CASE("medium tree string", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 3;
    int num_children = 10;
    int k = 0, i = 0;

    NodeStr root = createTree(k, num_children, num_levels);
    ShrPtrNodeStr::pointer_type shRoot = createShTree(i, num_children, num_levels);


    Benchmark(root, shRoot);
}

TEST_CASE("medium tree int", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 3;
    int num_children = 10;
    int k = 0, i = 0;
    auto root = createTreeInt(k, num_children, num_levels);
    auto shRoot = createShTreeInt(i, num_children, num_levels);

    Benchmark(root, shRoot);
}

TEST_CASE("big tree string", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 6;
    int num_children = 5;
    int k = 0, i = 0;

    NodeStr root = createTree(k, num_children, num_levels);
    ShrPtrNodeStr::pointer_type shRoot = createShTree(i, num_children, num_levels);


    Benchmark(root, shRoot);
}

TEST_CASE("big tree int", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 6;
    int num_children = 5;
    int k = 0, i = 0;
    auto root = createTreeInt(k, num_children, num_levels);
    auto shRoot = createShTreeInt(i, num_children, num_levels);

    Benchmark(root, shRoot);
}

TEST_CASE("huge tree string", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 8;
    int num_children = 5;
    int k = 0, i = 0;

    NodeStr root = createTree(k, num_children, num_levels);
    ShrPtrNodeStr::pointer_type shRoot = createShTree(i, num_children, num_levels);


    Benchmark(root, shRoot);
}

TEST_CASE("huge tree int", "[benchmark][recursive_traversal_visitor]")
{
    int num_levels = 8;
    int num_children = 5;
    int k = 0, i = 0;
    auto root = createTreeInt(k, num_children, num_levels);
    auto shRoot = createShTreeInt(i, num_children, num_levels);

    Benchmark(root, shRoot);
}
