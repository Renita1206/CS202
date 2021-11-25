## WEEK 0 (23rd Aug)
Classes


## WEEK 1  (30th July)
-  Write a RECURSIVE function to search for a substring in a given string.
    Return true if found, else False.
-  WAP to print all permutaions of a given text
-  WAP to create records for students 
    SRN
    NAME
    ROLL NO:
    MARKS (5 subs)
    for 5 students
    Compute average marks in the given subject
    Sort students based on SRN
    (Dynamic memory allocation)
-  Perform Tower Of Hanoi using Recursion
-  WAP to create a record for IPL Players
    Name, TeamName, MatchesPlayed, RunsScored
    -> To display player details
    -> Maximum runs in particular match
    -> Compute number of matches played by each player


## WEEK 2 (6th-11th Sept)
-   Perform addition of two polynomials stored as a singly linked list
-   Implement following operations on a singly linked list:
    Swap two nodes without swapping the data
    Delete every alternate node starting from first node


## WEEK 3 (13th-17th Sept)
-   Create a telephone directory containing customer details as name, phone number, address, area
    typedef struct node {
        name, ph, address
    }
    typedef struct customer_details
    Create an ordered doubly linked list based on name
-   Create an employee with the following fields
    typedef struct node{
        char* ssn;
        char* Name;
        Department depart;
        char* designation;
        int salary;
        int age;
        int phone;
        Node *prev;
        Node *next;
        } Node;
    typedef struct dept {
        char *name;
        int number;
    }Department;
    typedef struct employee
    {
        Node* head;
    }empl;
    Every employee should work in a department & a department should have a name & number associated with it.
    1) Delete all employees whose age > 58
    2) Display details of all employees who work in a particular department


## WEEK 4 (20th Sept)
-   Design a method for keeping two stacks using one array.
    Stack1 grows left
    Stack2 grows right
    Handle overflow and underflow situations (Two stacks grow towards each other).
    Using an array with its appropriate functions. Handle all boundary conditions.


## WEEK 5 (27th Sept-1st Oct)
-   Implement a Queue. Perform Enqueue and Dequeue
-   Implement a program to maintain doctor's appointment list using a queue.
    The appointment list should have details like patients name, date and time of appointment.
    The request should be served based on appointment slots.
    The appointment will be issued on daily basis.
    Display appropriate messages.


## WEEK - (4th-9th Oct)
ISA Week


## WEEK 6 (11th - 15th Oct)
-   Implement a double-ended queue using arrays
    I) Front Deletion II) Front Insertion  III) Delete from Rear IV) Insert from Rear
    Handle all boundary conditions.
-   Solution for Josephus problem


## WEEK 7 (18th-23rd Oct)
-   Create a binary search tree and traverse using pre-Order traversal.
    Also compute level and height of tree. (15M)
-   Create a binary search tree to store SRN of students where SRNs are strings.
    Implement insert function of binary search tree by comparing the strings.
    Also implement a function to print all sorted SRN in ascending order.
    Implement a Search function to search for an input SRN in tree.

## Week 8 (25th - 30th)
-   Create a binary expression tree and evaluate result
-   Delete a node from Binary Search Tree and reconstruct the tree after deletion

## Week 9
 -  Write a program to insert a mobile number along with name into a hash table. Add functions to delete, search and display.  
    Handle collision using seperate chaining and linear probing.

## Week 10
-   Check connectivity of a graph using DFS and compute components  
-   Traverse graph using BFS, use queue