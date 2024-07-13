
#include<iostream>
#include<conio.h>

using namespace std; 

class node
{
    public:
     int roll_no;
     string name;
     float marks;
     double per;
     node * next;
};
class linked_list
{
    public:
       node* head=NULL; 

       
       void insert()
       {
         int r;
         string n;
         float m;
         cout<<"\n                   ENTER THE ROLL NO. OF THE STUDENT         :  ";
         cin>>r;
         cout<<"\n                   ENTER THE NAME OF THE STUDENT             : ";
         cin>>n;
         cout<<"\n                   ENTER THE MARKS OF THE SYUDENT OUT OF 5OO : ";
         cin>>m;
         node * new_n=new node;
         new_n->roll_no=r;
         new_n->name=n;
         new_n->marks=m;
         new_n->per=(m/500)*100;
         new_n->next=NULL;
         
         if(head==NULL)
         {
            head=new_n;

         }
         else{
            node *temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=new_n;
         }
         

        
       }

      
       void search()
       {
        if(head==NULL)
          cout<<"\n NO RECORD TO DISPLAY!!!.";
          else{
            int r,count=0;
            cout<<"\n ENTER ROLL NO OF THE STUDENT TO BE SEARCHED: ";
            cin>> r;
            node*temp=head;
            while(temp!=NULL)
            {
                if(temp->roll_no==r)
                {
                    cout<<"\n                      Roll no    : "<<temp->roll_no;
                    cout<<"\n                      NAME       : "<<temp->name;
                    cout<<"\n                      Marks      : "<<temp->marks;
                    cout<<"\n                      PERCENTAGE : "<<temp->per<<"%";
                    count++;
                    break;
                }
                temp=temp->next;
            }
            if(count==0)
            cout<<"\n NO SUCH RECORD FOUND! ENTER CORRECT ROLL NO.";

          }
       }
       
        
        void update()
        {
            int r;
            cout<<"\nENTER THE ROLL NO. OF THE RECORD TO BE UPDATED:: ";
            cin>>r;
            if(head==NULL)
            {
                cout<<"\n NO RECORDS AVAILABLE TO UPDATE.";
                return;
            }
            node * temp= head;
            int count=0;
            while(temp!=NULL)
            {
                if(temp->roll_no==r)
                {
                    cout<<"\n               CURRENT ENTRIES ARE: ";
                    cout<<"\n               ROLL NO.   : "<< temp->roll_no;
                    cout<<"\n               NAME       : "<<temp->name;
                    cout<<"\n               MAEKS      : "<<temp->marks;
                    cout<<"\n               PERCENTAGE : "<<temp->per<<"%";
                    count++;
                    break;
                }
                temp=temp->next;
            }
            if(count==0)
            cout<<"\n NO SUCH RECORD FOUND! ENTER CORRECT ROLL NO.";
            else{
                cout<<"\n\n ENTER CHANGES YOU WANT TO MAKE";
                cout<<"\n\n ROLL NO: ";
                cin>>temp->roll_no;
                cout<<"\n NAME: ";
                cin>>temp->name;
                cout<<"\n MARKS: ";
                cin>>temp->marks;
                temp->per= (temp->marks/500)*100;
                cout<<"\n\n RECORD HAS BEEN UPDATED .";
            }


        }
        
        void del()
        {
            if(head==NULL)
            {
                cout<<"\n\n NO RECORDS FOUND. ";
                return;
            }
            else{
            
            int count=0;
            int r;
            cout<<"\n\n ENTER ROLL NO OF THE STUDENT WHOSE RECORD YOU WANT TO DELETE: ";
            cin>>r;
            if(r==head->roll_no)
            {
                node *ptr=head;
                head=head->next;
                cout<<"\n\n RECORD DELETED SUCCEESSFULLY";
                delete(ptr);
                count++;
            }
            else{
                node* temp=head->next, *q=head;
             while(temp!=NULL)
             {
                if(temp->roll_no==r)
                {
                    cout<<"\n                 STUDENT RECORD TO BE DELETED: ";
                    cout<<"\n                 Roll no    : "<< temp->roll_no;
                    cout<<"\n                 NAME       : "<<temp->name;
                    cout<<"\n                 MARKS      : "<<temp->marks;
                    cout<<"\n                 PERCENTAGE : "<<temp->per<<"%";
                    cout<<"\n\n\n RECORD DELETED SUCCESSFULLY. ";
                    count++;
                     q->next=temp->next;
                     delete(temp);
                    break;
                }
                q=temp;
                temp=temp->next;
             }
            }
            if(count==0)
              cout<<"\n\n RECORD NOT FOUND.";
            }

        }
        
        void display()
        {
            if(head==NULL)
            cout<<"\n\n LINKED KIST IS EMPTY.";
            else{
                node* temp=head;
                while(temp!=NULL)
                {
                    cout<<"\n\n                  RECORD: ";
                    cout<<"\n                    ROLL NO.   : "<< temp->roll_no;
                    cout<<"\n                    NAME       : "<<temp->name;
                    cout<<"\n                    MARKS      : "<<temp->marks;
                    cout<<"\n                    PERCENTAGE : "<<temp->per<<"%";
                    temp=temp->next;
                }
            }
        }
       

};
int main()
{
    linked_list obj; 
    int choice;
    p:
      system("cls");
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~                                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"    \n                                 STUDENT RECORD SYSTEM                     ";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~                                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    cout<<"\n\n 1. INSERT RECORD";
    cout<<"\n\n 2. SEARCH RECORD";
    cout<<"\n\n 3. UPDATE RECORD";
    cout<<"\n\n 4. DELETE RECORD";
    cout<<"\n\n 5. SHOW ALL RECORD";
    
    cout<<"\n\n\n\n------------------------------------ ENTER YOUR CHOICE------------------------------------------\n ";
    cin>>choice;
    switch(choice)
    {
        case 1:
           system("cls");
           obj.insert();
           break;
        case 2:
           system("cls");
           obj.search();
           break;
       
        case 3:
           system("cls");
           obj.update();
           break;
        case 4:
           system("cls");
           obj.del();
           break;
        case 5:
           system("cls");
           obj.display();
           break;
       
        default:
           cout<<"\n\n\n\nINVALID CHOICE...... try again";
           
    }
    getch();
    goto p;//label

    
}
