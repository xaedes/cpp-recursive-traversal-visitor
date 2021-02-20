
#include "recursive_traversal_visitor/version.h"
#include "recursive_traversal_visitor/visitor.h"
#include "recursive_traversal_visitor/tree_types.h"
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

using namespace recursive_traversal_visitor;

int main()
{
    std::cout << "recursive_traversal_visitor::Version " << recursive_traversal_visitor::VersionMajor << "." << recursive_traversal_visitor::VersionMinor << "." << recursive_traversal_visitor::VersionPatch << std::endl;
    using NodeStr = Node<std::string>;
    NodeStr root = {"root", {
        {"a", {}},
        {"b", {
            {"ba" , {}},
            {"bb" , {}}
        }},
        {"c", {}}
    }};
    using ShrPtrNodeStr = ShrPtrNode<std::string>;
    auto shRoot = ShrPtrNodeStr::Create("root", {
        ShrPtrNodeStr::Create("a", {}),
        ShrPtrNodeStr::Create("b", {
            ShrPtrNodeStr::Create("ba" , {}),
            ShrPtrNodeStr::Create("bb" , {})
        }),
        ShrPtrNodeStr::Create("c", {})
    });

    std::cout << "start" << std::endl;
    root.visit([](auto& visit, const NodeStr* node){
        std::string indent = "";
        for (int i=0; i<visit.depth; ++i) indent += "  ";
        std::cout << indent << "<" << node->value << ">" << "\n";
        visit.children();
        std::cout << indent << "</" << node->value << ">" << "\n";
    });
    std::cout << "end" << std::endl << std::endl;

    std::cout << "start" << std::endl;
    //shRoot->visit([](auto& visit, const auto node){
    shRoot->visit([](auto& visit, const ShrPtrNodeStr::pointer_type node){
        std::string indent = "";
        for (int i=0; i<visit.depth; ++i) indent += "  ";
        std::cout << indent << "<" << node->value << ">" << "\n";
        if (visit.depth < 1) visit.children();
        else visit.skipChildren();
        std::cout << indent << "</" << node->value << ">" << "\n";
        node->value += " processed";
    });
    std::cout << "end" << std::endl << std::endl;

    std::cout << "start" << std::endl;
    //shRoot->visit([](auto& visit, const auto node){
    shRoot->visit([](auto& visit, const ShrPtrNodeStr::pointer_type node){
        std::string indent = "";
        for (int i=0; i<visit.depth; ++i) indent += "  ";
        std::cout << indent << "<" << node->value << ">" << "\n";
        visit.children();
        std::cout << indent << "</" << node->value << ">" << "\n";
        node->value += " processed";
    });
    std::cout << "end" << std::endl << std::endl;
    return 0;
}

