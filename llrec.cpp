#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  
  if(head != NULL){

    // Check if garbage
    if(smaller == NULL && larger == NULL) {
      llpivot(head->next, smaller, larger, pivot);

      if ((head->val) <= pivot) {
        head->next = smaller;
        smaller = head;
      } else {
        head->next = larger;
        larger = head;
      }

      head = NULL;
    }
  }
}

