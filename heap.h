#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   *  what is ary-ness - ask prof
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void trickleDown(int id);
  void trickleUp(int id);
  std::vector<T> items_;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  items_.push_back(item);
  trickleUp(items_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::out_of_range());
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_[1];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::out_of_range());
  }
  items_[1] = items_.back();
  items_.pop_back();
  trickleDown(1);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items_.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return items_.empty();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int id){
  if (((2 * id) + 1) >= items_.size()) {
    return;
  }

  int smallestC = 2 * id + 1;
  if (2 * id + 2 < items_.size()){
    int rightC = 2 * id + 2;
    if (items_[rightC] < items_[smallestC]){
      smallestC = rightC;
    }
  }

  if(items_[id] > items_[smallestC]){
    swap(items_[id], items_[smallestC]);
    trickleDown(smallestC);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int id){
  if (((id - 1)/2) < 1) {
    return;
  }

  int parent = (id - 1)/2;
  if(items_[id] < items_[parent]){
    swap(items_[parent], items_[id]);
    trickleDown(parent);
  }
}

#endif

