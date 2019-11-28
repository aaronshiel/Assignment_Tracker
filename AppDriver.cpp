using namespace std;
#include "NodeLinkedHeader.h"
#include <iostream>

int main() {
   AssignmentNode *tail_ptr(NULL), *head_ptr = new AssignmentNode(NULL, tail_ptr); //start off linked list with head and tail pointers
   Linked_List newList = Linked_List(head_ptr);
   
   cout << "Welcome to your Assignment Planner!" << endl << "What would you like to do?" << endl;
   int action = -1;

   while (action != 0) {
      cout << "1. Add new assignment." << endl;
      cout << "2. Remove assignment." << endl;
      cout << "3. Check current assignments." << endl;
      cout << "4. When is my next assignment due?" << endl;
      cout << "0. Exit program." << endl;

      cout << "Enter: ";
      cin >> action;
      cout << endl;
      if (action == 1) {
         int due = 0;
         cout << "How many days till this assignment is due? " << endl;
         cin >> due;
         newList.list_head_insert(due);
      }
      if (action == 2) {
         int done = 0;
         cout << "What # assignment did you finish? ";
         cin >> done;
         newList.list_remove(newList.list_locate_previous(done-1));
      }
      if (action == 3) {
         newList.list_output();
      }
      if (action == 4) {
         newList.find_earliest_due_date();
      }
   }

   cout << "Thank you for using your planner!" << endl;

   system("pause");
   return 0;
}