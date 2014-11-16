/**
 * tree.cc
 * Implementation of our pseudo-merkle-tree for FunCoin
 *
 *
 */

#include "tree.hpp"

using namespace tree;

//! make sure payload is null for a new node
template<typename T>
BasicTreeNode<T>::BasicTreeNode() {
  this->payload = NULL;
}

template<typename T>
std::string BasicTreeNode<T>::getHash() {
  
  //! cases:
  // node is a leaf
  if (!left && !right) {
    std::stringstream s;
    s << this->payload;
    return s.str();
  }
  
  // node is not a leaf, but left child exists
  else if (left && !right) {
    return this->left.getHash() + "";
  }
  
  // node is not a leaf, but right child exists
  else if (!left && right) {
    return "" + this->right.getHash();
  }
  
  // node is not a leaf, so hash is concat of left and right children
  else {
    return this->left.getHash() + this->right.getHash();
  }
}

template<typename T>
std::unique_ptr<T> BasicTreeNode<T>::getPayload() {
  return this->payload;
}

template<typename T>
void BasicTreeNode<T>::setPayload(const T& payload) {
  this->payload = payload;
}

template<typename T>
std::unique_ptr<T> BasicTreeNode<T>::getLeftChild() {
  return this->left;
}

template<typename T>
void BasicTreeNode<T>::setLeftChild(const BasicTreeNode& node) {
  this->left = node;
}

template<typename T>
std::unique_ptr<T> BasicTreeNode<T>::getRightChild() {
  return this->right;
}

template<typename T>
void BasicTreeNode<T>::setRightChild(const BasicTreeNode& node) {
  this->right = node;
}