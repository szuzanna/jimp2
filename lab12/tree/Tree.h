//
// Created by Zuzanna on 29.05.2018.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <stddef.h>
#include <memory>

namespace tree {
    template<class T>
    class Tree {
    public:
        Tree() = default;

        Tree(const T &value);

        void Insert(const T &e);

        std::unique_ptr<Tree<T>> MakeNode(const T &value);

        bool Find(const T &e);

        T Value() { return value_; };

        size_t Depth();

        size_t Size() { return size_; };

        T value_;
        size_t size_;
        size_t depth_;
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
    };

    template<typename T>
    Tree<T>::Tree(const T &value) {
        value_ = value;
        size_ = 1;
        depth_ = 1;
        left_ = nullptr;
        right_ = nullptr;
    }

    template<typename T>
    void Tree<T>::Insert(const T &e) {
        if (e < value_) {
            if (left_ != nullptr) {
                left_->Insert(e);
            } else {
                left_ = std::move(MakeNode(e));

            }
        }
        if (e > value_) {
            if (right_ != nullptr) {
                right_->Insert(e);
            } else {
                right_ = std::move(MakeNode(e));
            }
        }
        ++size_;
    }

    template<class T>
    size_t Tree<T>::Depth(){
        if(this){ return 1 + std::max(this->left_->Depth(), this->right_->Depth()); }
        return 0;
    }

    template<typename T>
    std::unique_ptr<Tree<T>> Tree<T>::MakeNode(const T &value) {
        std::unique_ptr<Tree<T>> newNode = std::make_unique<Tree<T>>();
        newNode->value_ = value;
        return newNode;
    }

    template<typename T>
    bool Tree<T>::Find(const T &e) {

    }

}


#endif //JIMP_EXERCISES_TREE_H
