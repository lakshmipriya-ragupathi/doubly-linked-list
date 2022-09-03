//
//  main.cpp
//  week_4
//
//  Created by Ragupathi on 23/08/2022.
//

#include <iostream>
using namespace std;
//insert at front, end k
//delete at front end k
//merge dll

class node {
public:
    int data;
    node *next;
    node *prev;
    node *head = NULL;
    
    void insert(int data){
        node * newNode = new node;
        newNode->prev = newNode->next = NULL;
        newNode->data = data;
        
        if(head == NULL){
            head = newNode;
        }
        
        else{
            node *temp = head;
            
            while((temp->next != NULL) && (temp->data < data)){
                temp = temp->next;
            }
            
            //insert when only one node is present
            if(temp->prev == NULL){
                if(temp->data < data){
                    newNode->prev = temp;
                    temp->next = newNode;
                }
                else {
                    newNode->next = temp;
                    temp->prev = newNode;
                    head = newNode;
                }
            }
            // insert at end
            else if(temp->next == NULL && temp->data < data){
                newNode->prev = temp;
                temp->next = newNode;
               
            }
            // insert at k
            else{
                
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
                                
            }
        }

    }

    void display(){
        node *temp = head;
        while(temp !=NULL){
            cout << temp->data <<endl;
            temp = temp->next;
        }
    }
    
    void del(int pos){
        
        //delete at head
        if(pos == 1){
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            cout << "\ndata to be deleted: " << temp->data <<endl;
            delete temp;
        }
        // at k
        else{
            node *temp = head;
            int i=1;
            while(temp != NULL && i < pos){
                temp = temp->next;
                i++;
            }
            if(temp->next != NULL){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                cout << "\ndata to be deleted: " << temp->data << endl;
                delete temp;
            }
            //if delete at end
            else if (temp->next == NULL){
                temp->prev->next = NULL;
                cout << "\ndata to be deleted: " << temp->data << endl;
                delete temp;
            }
            
            
    }
    }
    
    void merge(node obj1, node obj2){
        node *start1 = obj1.head;
        node *start2 = obj2.head;
        
        while(start1 && start2){
            if(start1->data <= start2->data){
                insert(start1->data);
                start1 = start1->next;
            }
            else{
                insert(start2->data);
                start2 = start2->next;
            }
        }
        //if values still left in list1
        if( start1 != NULL){
            while(start1 != NULL){
                insert(start1->data);
                start1 = start1->next;
            }
        }
        //if values still left in list2
        else if(start2 != NULL){
            while(start2 != NULL){
                insert(start2->data);
                start2 = start2->next;
                
            }
        }
        
    }
    int length(){
        node *temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp= temp->next;
        }
        return count;
    }
    
};


int main() {
    node list, list1, list2;
   
    int option = 6, element, choice = 4;
    
    while(option != 5){
        cout << "\nTo perform:\nInsertion: press 1\nDeletion: press 2\nDisplay: press 3\nMerge: press 4\nExit: press 5\n";
        cin >> option;
        switch(option){
            case 1:
                cout << "\nTo insert:\nEnter the element: ";
                cin >> element;
                list.insert(element);
                break;
                
            case 2:
                int len;
                len = list.length();
                cout << "\nTo delete:\nEnter the positon from 1 to " << len << ":" <<endl;
                cin >> element;
                list.del(element);
                list.display();
                break;
                
            case 3:
                cout <<"\nlist: \n";
                list.display();
                cout << endl;
                break;
                
            case 4:
                
                while (choice !=3){
                    cout << "\nInsert in list 1: press 1\nInsert in list 2: press 2\nTo display merged list: press 3" << endl;
                    cin >> choice;
                   
                    if(choice == 1){
                        cout << "\nEnter the element: ";
                        cin >> element;
                        list1.insert(element);
                    }
                    else if (choice ==2){
                        cout << "\nEnter the element: ";
                        cin >> element;
                        list2.insert(element);
                    }
                    else{
                        int len1, len2;
                        len1 = list1.length();
                        len2 = list2.length();
                        list.merge(list1, list2);
                        cout << "list1: " << endl;
                        list1.display();
                        cout << "\nlength: " << len1 <<endl;
                        cout << endl;
                        cout << "list2: " << endl;
                        list2.display();
                        cout << "\nlength: " << len2 <<endl;
                        cout << endl;
                        cout << "merged list: " << endl;
                        list.display();
                        break;
                    }
                }
                break;
                
            case 5:
                cout << "you've successfully exited the program :)\n";
                //exit();
                break;
                
                }
    }
    return 0;
}

