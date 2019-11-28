#pragma once
#include <iostream>
/*
FILE: NodeLinkedHeader.h
CLASS PROVIDED: AssignmentNode

Member Variables for AssignmentNode class
   typedef int value_type;
      defines what data type will be held by the AssignmentNode class

   value_type data;
      using type value_type, we store in variable data how many days till assignment is due

   AssignmentNode* link;
      this variable holds whatever other node that the current node is linked to.

Member Functions for AssignmentNode class
   AssignmentNode(const value_type& init_data = value_type(), AssignmentNode* init_link = NULL)
      Post-Condition: Stores init_data in data member variable, and stores init_link in link member variable

   int GetDueDate()
      Post-Condition: returns data member variable

   const int GetDueDate() const
      Pre-Condition: AssignmentNode accessing methods is a constant pointer
      Post-Condition: returns data member variable as a constant

   AssignmentNode* getLink()
      Post-Condition: returns link member variable

   const AssignmentNode* getLink() const
      Pre-Condition: AssignmentNode accessing methods is a constant pointer
      Post-Condition: returns link member variable as a constant

   void SetData(const value_type& entry)
      Pre-Condition: value passed in is of the same type as value_type
      Post-Condition: sets data member variable to entry

   void SetLink(AssignmentNode* newLink)
      Pre-Condition: value passed in is an AssignmentNode pointer
      Post-Condition: sets link member variable to newLink

CLASS PROVIDED: Linked_list

Private Member Variables
   
   AssignmentNode* head_ptr;
      this variable will change throughout runtime, but will always be pointing
      to the head pointer of a linked list

Public Member Functions

   Linked_List(AssignmentNode* headptr) { SetHeadPtr(headptr); }
      Pre-Condition: parameter passed in is the head pointer to a linked list
      Post-Condition: head_ptr member variable set to heaptr

   void SetHeadPtr(AssignmentNode* headptr) { head_ptr = headptr; }
      Pre-Condition: parameter passed in is the head pointer to a linked list
      Post-Condition: head_ptr member variable set to heaptr

   void list_head_insert(const AssignmentNode::value_type&entry);
      Pre-Condition: paremeter passed in is of the same type as value_type
      Post-Condition: head_ptr now points to a newly added node with data value of entry
   
   void list_remove(AssignmentNode* previous_ptr);
      Pre-Condition: pointer passed in is a pointer that points to a node which comes
                     right before a node we want to remove
      Post-Condition: node that comes after previous_ptr is now removed

   void list_remove_head();
      Post-Condition: head_ptr is set its link, and previous node is deleted

   AssignmentNode* list_locate_previous(int position);
      Pre-Condition: integer passed in is within range of linked list size
      Post-Condition: returns a pointer that points to the node at requested position

   int GetListSize();
      Post-Condition: returns amount of entries in linked list 

   void list_output();
      Pre-Condition: there is atleast one entry in the linked list of AssignmentNode's
      Post-Condition: outputs all entries and their due dates

   void find_earliest_due_date();
      Pre-Condition: there is atleast one entry in the linked list of AssignmentNode's
      Post-Condition: outputs which assignment is due the soonest
*/
class AssignmentNode {
public:
   typedef int value_type;
   value_type data;
   AssignmentNode* link;

   AssignmentNode(const value_type& init_data = value_type(), AssignmentNode* init_link = NULL) {
      data = init_data;
      link = init_link;
   }
   int GetDueDate() {
      return data;
   }
   const int GetDueDate() const {
      return data;
   }
   AssignmentNode* getLink() {
      return link;
   }
   const AssignmentNode* getLink() const {
      return link;
   }
   void SetData(const value_type& entry) {
      data = entry;
   }
   void SetLink(AssignmentNode* newLink) {
      link = newLink;
   }
};

class Linked_List {
private:
   AssignmentNode* head_ptr;
   bool removingTwo = false;
public:

   Linked_List(AssignmentNode* headptr) { SetHeadPtr(headptr); }

   void SetHeadPtr(AssignmentNode* headptr) { head_ptr = headptr; }

   void list_head_insert(const AssignmentNode::value_type&entry);

   void list_remove(AssignmentNode* previous_ptr);

   void list_remove_head();

   AssignmentNode* list_locate_previous(int position);

   int list_find_position(AssignmentNode* node);

   int GetListSize();

   void list_output();

   void find_earliest_due_date();

};
