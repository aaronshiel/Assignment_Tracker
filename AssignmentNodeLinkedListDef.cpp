#include "NodeLinkedHeader.h"
#include <iostream>
using namespace std;

void Linked_List::list_output() { //outputs all assignments and their due dates, announces no assignments if none exist
   AssignmentNode* cursor;
   int howMany = 1;
   bool output = false;
   for (cursor = head_ptr; cursor != NULL && (cursor->GetDueDate() != 0); cursor = cursor->getLink()) {
      output = true;
      cout << "Assignment " << howMany << ". " <<
         "Due in " << cursor->GetDueDate() << " days!" << endl;
      howMany++;
   }
   if (output == false)
      cout << "Currently no assigments!" << endl;
}

void Linked_List::find_earliest_due_date() { //returns the assignment that is next due
   AssignmentNode *cursor, *temp = head_ptr;
   int earliest = head_ptr->GetDueDate();
   int location = 1;
   for (cursor = head_ptr; (cursor != NULL); cursor = cursor->getLink()) {
      if (cursor->GetDueDate() < earliest && cursor->GetDueDate() != 0) {
         temp = cursor;
         earliest = cursor->GetDueDate();
      }
   }
   if (temp->GetDueDate() != 0)
      cout << "Your next assignment is due in " << temp->GetDueDate() << " days!" << endl;
   else
      cout << "You currently have no Assignments!" << endl;
}

int Linked_List::GetListSize() { //returns number of entries to linked list
   AssignmentNode* cursor;
   int howMany = 0;
   for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
      howMany++;
   }
   return howMany;
}

void Linked_List::list_remove_head() { //removes the head_ptr node
   AssignmentNode* temp;
   temp = head_ptr->getLink();
   delete head_ptr;
   head_ptr = temp;
}

AssignmentNode* Linked_List::list_locate_previous(int position) { //returns a pointer that points to node at position passed in
   if (position == 0) {
      return head_ptr;
   }
   AssignmentNode* cursor;
   cursor = head_ptr;
   for (int i = 0; (cursor != NULL) && (i < position - 1); i++) {
      cursor = cursor->getLink();
   }
   if (position == 1) {
      removingTwo = true;
   }
   cout << "cursor returned for removal is " << cursor->GetDueDate() << endl;
   return cursor;
}

void Linked_List::list_head_insert(const AssignmentNode::value_type&entry) { //creates a new head_ptr with data value of entry
   if (GetListSize() == 0) {
      head_ptr->SetData(entry);
   }
   else
      head_ptr = new AssignmentNode(entry, head_ptr);
}

void Linked_List::list_remove(AssignmentNode* previous_ptr) { // removes node that comes after the node passed in
if (previous_ptr == head_ptr && removingTwo == false) {
      cout << "List size: " << GetListSize() << endl;
      list_remove_head();
   }
   else {
      AssignmentNode *remove_ptr;
      remove_ptr = previous_ptr;
      remove_ptr = remove_ptr->getLink();
      previous_ptr->SetLink(remove_ptr->getLink());
      delete remove_ptr;
      removingTwo = false;
   }
}
