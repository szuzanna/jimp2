//
// Created by Zuzanna on 16.03.2018.
//

#include "SmartTree.h"
#include <sstream>

namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto p = std::make_unique<SmartTree>();
        p->value = value;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if (tree->left == nullptr) tree->left = move(left_subtree);
        else {
            while (tree->left != nullptr) tree = move(tree->left);
            tree->left = move(left_subtree);
        }

        return move(tree);
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if (tree->right == nullptr) tree->right = move(right_subtree);
        else {
            while (tree->right != nullptr) tree = move(tree->right);
            tree->right = move(right_subtree);
        }

        return move(tree);
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr != nullptr) {
            PrintTreeInOrder(unique_ptr->left, out);
            *out << (unique_ptr->value) << ", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::stringstream out;
        if (tree != nullptr) {
            out << "[" ;
            out << tree->value << " ";
            if (tree->left != nullptr)
                out << DumpTree(tree->left);
            else out << "[none]";

            out << " ";

            if (tree->right != nullptr)
                out << DumpTree(tree->right);
            else out << "[none]";

            out << "]";
        }
        return out.str();
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {

    }
}