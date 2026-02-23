#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
 class list{
 	private:
 		node*head;
 public:
 	list(){
 		head=NULL;
	 }
void insetionfront(node** head,int newvalue){
 
	node* newnode=new node();
	newnode->data=newvalue;
	newnode->next=*head;
	*head=newnode;
}
};
int main(){
	list l;
		node* head=NULL;
l.insetionfront(&head,20);
l.insetionfront(&head,100);
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
		
	}
	return 0;
}
