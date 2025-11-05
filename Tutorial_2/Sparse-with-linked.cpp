#include <iostream>
using namespace std;
struct Node{
    int row, col, value;
    Node *next;
    
    Node(int r, int c, int v){
        row = r;
        col = c;
        value = v;
        next = nullptr;
    }
};

class SparseMatrix{
    Node *head;
    
    public:
        SparseMatrix(){
            head = nullptr;
        }
        
        SparseMatrix(int r, int c, int a[3][4]){
            head = nullptr;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if (a[i][j]!=0){
                        insert(i, j, a[i][j]);
                    }
                }
            }
        }
        
        void insert(int r1, int c1, int v1){
            Node *newnode = new Node(r1, c1, v1);
            if (!head){
                head = newnode;
            } else {
                Node *temp = head;
                while(temp->next){
                    temp=temp->next;
                }
                temp->next = newnode;
            }
        }
        
        void display(){
            Node *temp = head;
            cout<<"ROW\tCOL\t VALUE\n";
            while(temp!=nullptr){
                cout<<temp->row<<"\t"<<temp->col<<"\t"<<temp->value<<endl;
                temp = temp->next;
            }
        }
};

int main() {
    int arr[3][4] = 
    {
        {5, 0, 0, 1},
        {0, 2, 0, 0},
        {0, 0, 3, 0}
    }  ;
    SparseMatrix sm(3, 4, arr);
    sm.display();
    
    return 0;
}