//Cass Morgan II
//CSC 375 Data Structures Linked List
//Date 03/26/2016

#include <iostream>
#include "linkedList.h"
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    LinkedList<Profile> p_list;
    Profile temp;
    string line;

    ifstream file("presidents.txt");

    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.name, '\t');
            getline(ss, temp.state, '\t');
            p_list.push(temp);
        }
    }
    // testing peek()
    cout<< "Showing the top of the stack after reading in from file" <<endl;
    p_list.peek();

    // testing push()
    Profile my_name;
    my_name.name = "Cass Lewis Morgan II";
    my_name.state = "MI";
    p_list.push(my_name);
    cout<< "\nShowing the top of the stack after pushing on my profile" <<endl;
    p_list.peek();

    // testing pop()
    p_list.pop(my_name);
    cout<< "\nShowing the top of the stack after popping off my profile" <<endl;
    p_list.peek();

    // testing print()
    cout<< "\nPrinting the entire Linked List..." <<endl;
    p_list.print();

    // testing make_empty()
    cout<< "\nEmptying the entire Linked List..." <<endl;
    p_list.make_empty();

    // testing isEmpty()
    p_list.isEmpty();

    file.close();
    return 0;
}
