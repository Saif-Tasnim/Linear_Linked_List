#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct Store
{

    int a[1000];

};
int selectOption();
Node* createNode();
void insertHead(Node* &head, Node* &nn); // 1
void insertTail(Node*&head, Node* &nn); // 2
void insert_certain_position(Node*&head, Node* &nn,int pos); // 3
void delete_head(Node*&head); // 4
void delete_tail(Node*&head); // 5
void delete_certain_position(Node* &head, int pos); // 6
int sizeOfList(Node* head); // 7
void printList(Node* head); // 8
int search_value_unique(Node*&head, int value); // 9
Store search_value_non_unique(Node*&head,int val); // 10
void insert_after_spec_value_unique(Node*&head); // 11
void insert_after_spec_value_non_unique(Node*&head); // 12
void deletion_value_unique(Node*& head); // 13
void deletion_value_non_unique(Node*& head); // 14
void reverse_list_three_pointers(Node*&head); // 15
Node* reverse_list_recursion_function(Node* head); // 16
void find_mid_value_using_slow_fast_method (Node*& head); // 17

/// make option list
int selectOption()
{
    cout<< "Press 1 To Insert In Head"<<endl;
    cout<< "Press 2 To Insert In Tail"<<endl;
    cout<< "Press 3 To Insert In Certain Position"<<endl;
    cout<< "Press 4 To Delete In Head"<<endl;
    cout<< "Press 5 To Delete In Tail"<<endl;
    cout<< "Press 6 To Delete In Certain Position"<<endl;
    cout<< "Press 7 Total Size Of List"<<endl;
    cout<< "Press 8 Print The List"<<endl;
    cout<< "Press 9 Search Value In Unique List"<<endl;
    cout<< "Press 10 Search Value In Multiple Value Non Unique List"<<endl;
    cout<< "Press 11 Insertion after a specific value (Unique List)"<<endl;
    cout<< "Press 12 Insertion after a specific value (Duplication enabled List)"<<endl;
    cout<< "Press 13 Deletion by Value (Unique List)."<<endl;
    cout<< "Press 14 Deletion by Value(Duplication enabled List)."<<endl;
    cout<< "Press 15 Reverse a Linked List (Using 3 pointers)"<<endl;
    cout<< "Press 16 Reverse a Linked List (Recursive Function)."<<endl;
    cout<< "Press 17 Find Mid Value Using (slow-fast pointer) method."<<endl;
    cout<< "Press 18 Make a cycle at K-th position."<<endl;
    cout<< "Press 19 Detect a cycle."<<endl;
    cout<< "Press 20 Remove a cycle."<<endl;
    cout<< "Press 0 To Exit."<<endl;
    int n;
    cout<< "\nEnter Your Choice From (1-14)"<<endl;
    cin>>n;
    return n;

}

/// create node for all
Node* createNode()
{
    int value;

    cout<< "Enter a value : ";

    cin>> value;
    /// value = rand()%100+1;
    Node *nn = new Node(value);
    return nn;
}

/// option-1
void insertHead(Node *&head, Node *&nn)
{
    if(head==NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
}
/// option-2
void insertTail(Node* &head, Node* &nn)
{
    if(head==NULL)
    {
        head = nn;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}

/// option-3
void insert_certain_position(Node* &head, Node* &nn,int pos)
{
    int i=0;
    Node* temp = head;
    if(pos==0)
    {
        insertHead(head,nn);
        cout<< "\t\tInserting in head"<< endl;
    }
    else if(pos == sizeOfList(head)||pos == sizeOfList(head)+1)
    {
        insertTail(head,nn);
        cout<< "\t\tInserting in Tail"<< endl;
    }
    else
    {
        while(i<pos-2)
        {
            i++;
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }

}

/// option-4
void delete_head(Node*&head)
{
    if(head==NULL)
    {
        cout<< "Nothing to delete. The List is already empty..\n\n";
        return;
    }

    Node* delNode = head;
    head = delNode->next;
    cout<< delNode->data << " is deleted\n";
    delete(delNode);
}

/// option-7
int sizeOfList(Node* head)
{
    int i=0;
    Node *temp = head;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }

    //cout<< "Total length of linked list = " <<i <<endl<<endl;
    return i;
}

///option-8
void printList(Node *head)
{
    Node* temp = head;
    if(temp==NULL)
    {
        cout<< "Nothing to print\n"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        cout<< temp->data;
        if(temp->next!=NULL)
        {
            cout<< " -> ";
        }
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = NULL, *nn;
    int option = selectOption();
    while(option!=0)
    {
        if(option==1)
        {
            nn = createNode();
            insertHead(head,nn);
        }
        else if(option==2)
        {
            nn = createNode();
            insertTail(head,nn);
        }
        else if(option==3)
        {
            int n;
            cout<< "Enter position : ";
            cin>> n;
            if(n>=0 && n <= sizeOfList(head)+1)
            {
                nn = createNode();
                insert_certain_position(head,nn,n);
            }

            else
            {
                cout<< "\tInvalid Position.\n"<<endl;
            }
        }
        else if(option==4)
        {
            delete_head(head);
        }
        else if(option==5)
        {
            delete_tail(head);
        }
        else if(option==6)
        {
            int n;
            cout<< "Enter position : ";
            cin>> n;
            if(n>=0 && n <= sizeOfList(head))
            {
                delete_certain_position(head,n);
            }

            else
            {
                cout<< "\tInvalid Position.\n"<<endl;
            }

        }
        else if(option==7)
        {
            int s = sizeOfList(head);
            cout<< "Total length of linked list = " <<s <<endl<<endl;
        }
        else if(option==8)
        {
            printList(head);
        }
        else if(option==9)
        {
            int value;
            cout<< "Enter the value you wanna search ? : ";
            cin>> value;
            int val = search_value_unique(head,value);
            if(val == -1)
            {
                cout<<"\t "<< value << " has not found in list\n\n";
            }
            else
            {
                cout<< "\t Your searched value find at = " << val << " position\n\n";
            }
        }

        else if(option==10)
        {

            int value;
            cout<< "Enter the value you wanna search ? : ";
            cin>> value;
            Store T;
            T = search_value_non_unique(head,value);
            cout<< "Size of this struct array : " <<T.a[0] << endl;
            if(T.a[0]==1)
            {
                cout<< value << " has not found in that list\n";
            }
            else
            {
                cout<< value<< " has found at : ";
                for(int i=1; i<T.a[0]; i++)
                {
                    cout<< T.a[i] << " , ";
                }
            }
            cout<< endl<<endl;
        }

        else if(option==11)
        {
            insert_after_spec_value_unique(head);
        }

        else if(option==12)
        {
            insert_after_spec_value_non_unique(head);
        }

        else if(option==13){
            deletion_value_unique(head);
        }

        else if(option==14){
            deletion_value_non_unique(head);
        }
        else if(option==15){
          reverse_list_three_pointers(head);
        }
         else if(option==16){
          head = reverse_list_recursion_function(head);
        }
         else if(option==17){
          find_mid_value_using_slow_fast_method(head);
        }
         else if(option==18){

        }
         else if(option==19){

        }
         else if(option==20){

        }


        option = selectOption();
    }
    cout<< "\n\n\t\t\tYou have exited the code !!!!"<<endl;
    return 0;
}
/// option 5
void delete_tail(Node*&head)
{
    if(head == NULL)
    {
        cout<< "\tNothing to delete. ALready Empty\n\n.";
        return;
    }
    if(sizeOfList(head) == 1)
    {
        delete_head(head);
        return;
    }
    Node* temp = head;

    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = NULL;
    cout<< delNode->data << " is deleted\n";
    delete(delNode);

}
/// option 6

void delete_certain_position(Node* &head, int pos)
{
    if(pos==0)
    {
        delete_head(head);
    }
    else if(pos == sizeOfList(head) )
    {
        delete_tail(head);
    }
    else
    {
        int i=0;
        Node* temp = head;
        while(i<pos-2)
        {
            i++;
            temp=temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        cout<< delNode->data << " is already deleted\n";
        delete(delNode);
    }
}

/// option 9

int search_value_unique(Node*&head, int value)
{

    if(head == NULL)
    {
        return -1;
    }
    Node* temp = head;
    int c=0;

    while(temp!=NULL)
    {
        c++;
        if(temp->data== value)
        {
            return c;
        }
        temp=temp->next;
    }
    return -1;
}

///option 10

Store search_value_non_unique(Node*&head, int val)
{
    if(head== NULL)
    {
        ///  cout<< "\tNothing to search\n\n";
        Store T;
        T.a[0] = 1;
        return T;
    }


    /**
              print in method

       int c = 0,f=0;
       cout<< val << " has found at position : ";
       while(temp!=NULL){
       c++;
       if(temp->data == val){
          cout<<c << " , ";
          f=1;
        }
        temp = temp->next;
     }
       if(f==0){
           cout<< val << " has not found\n";
       }
        cout<< endl;

    */
    Node* temp = head;
    Store T ;
    int c = 0,k=1;
    while(temp!=NULL)
    {
        c++;
        if(temp->data == val)
        {
            T.a[k] = c;
            k++;
        }
        temp = temp->next;
    }
    T.a[0] = k;

    return T;
}

/// option 11

void insert_after_spec_value_unique(Node*&head)
{
    if(head == NULL)
    {
        cout<< "Nothing is found\n";
        return;
    }
// Node* temp = head;
    int n;
    cout<< "Enter the value from list : ";
    cin>> n;

    Node * nn = createNode();
    int pos = search_value_unique(head,n);
    insert_certain_position(head,nn,pos+1);
}

/// option 12

void insert_after_spec_value_non_unique(Node*&head)
{
    if(head==NULL)
    {
        cout<< "Nothing is found\n";
        return;
    }
    Node* temp = head;
    Store t;
    cout<< "Enter the value from list to search & counter :  ";
    int n,p;
    cin>> n>>p;
    Node* nn = createNode();
    t = search_value_non_unique(head,n);
    for(int i=1; i<t.a[0]; i++)
    {
        if(i==p)
        {
            insert_certain_position(head,nn,t.a[i]+1);

        }
    }
}

/// option 13

void deletion_value_unique(Node*& head){

 if(head==NULL){
    cout<< "\tAlready empty list\n";
    return ;
 }
 Node* temp = head;
 int val;
 cout<< "Enter the value you wanna delete ? : ";
 cin>> val;
 int f = search_value_unique(head,val);
 delete_certain_position(head,f);

}

/// option 14

void deletion_value_non_unique(Node*& head){
 if(head==NULL)
    {
        cout<< "Nothing is found\n";
        return;
    }
    Node* temp = head;
    Store t;
    cout<< "Enter the value from list to delete & counter :  ";
    int n,p;
    cin>> n>>p;
    t = search_value_non_unique(head,n);
    for(int i=1; i<t.a[0]; i++)
    {
        if(i==p)
        {
            delete_certain_position(head,t.a[i]);

        }
    }
}

/// option 15

void reverse_list_three_pointers(Node*&head){
if(head==NULL){
    cout<< "Nothing to reverse\n";
    return ;
}
Node* temp=head;
Node* prev = NULL;
Node* current = temp;
Node* nxt = temp->next;

while(true){
    current->next = prev;   ///NULL   1    2    3    4     5
    prev = current;         /// pre   curr nxt
    current = nxt;
    if(current==NULL)break;
    nxt = nxt->next;
}
head = prev;
cout<< "\tSuccessfully reversed\n";
}

/// option 16

Node* reverse_list_recursion_function(Node* head){
if(head==NULL){
    cout<< "List is empty\n"<<endl;
    return head;
}

if(head->next == NULL){
    cout<< "\tSuccessfully reversed\n";
    return head;
}
Node* nn = reverse_list_recursion_function(head->next);   /// 1  2  3  4  5
head->next->next = head;                    ///
head->next = NULL;
//cout<< temp->data<< ", ";

return nn;

}

/// option 17
void find_mid_value_using_slow_fast_method (Node*& head){
if(head==NULL){
    cout<< "No data found\n\n";
    return;
}
Node* slow = head;
Node* fast = head;
while(fast!=NULL && fast->next!=NULL ){
    slow = slow->next;
    fast = fast->next->next;
}
cout<< "Mid Value is = " << slow->data << endl;


}


