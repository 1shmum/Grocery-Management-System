#include<bits/stdc++.h>
using namespace std;

string check(int);
int display1();
int search(int);

struct node
{
    node *prev;
    int data;
    int x,y,sum;     //x == quantity
    string name,nam;   //y == price
    node *next;
};

struct node *start=NULL;
node* create_node()
{
    node *n = new node;
    cout<<"ENTER PRODUCT ID: "<<endl;
    cin>>n->data;
    cout<<"ENTER PRODUCT NAME: "<<endl;
    cin>>n->name;
    cout<<"ENTER QUANTITY: "<<endl;
    cin>>n->x;
    cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
    cin>>n->y;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insert_node()
{
    node *temp;
    temp = create_node();
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        node *traverse;
        traverse = start;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next=temp;
        temp->prev=traverse;
    }
}

void add_begin()
{
    node *temp;
    temp = create_node();
    temp->next = start;
    start->prev = temp;
    start=temp;
}

void add_after()
{
    node *temp;
    temp= create_node();
    int value;
    cout<<"Enter the product id after which the product has to be inserted :"<<endl;
    cin>>value;
    node *traverse;
    traverse = start;
    while(traverse->data!=value)
    {
        traverse = traverse->next;
    }
    temp->prev = traverse;
    temp->next=traverse->next;
    traverse->next->prev = temp;
    traverse->next = temp;
}

void display()
{
    node *traverse;
    traverse  = start;
    system("cls");
    cout<<"\n\n\t\t\t**********************GROCERY STORE*****************************"<<endl;
    cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
    while(traverse!=NULL)
    {
        cout<<traverse->data<<"\t\t";
        cout<<traverse->name<<"\t\t";
        cout<<traverse->x<<"\t\t";
        cout<<traverse->y<<"\n";
        traverse = traverse->next;

    }
}

void delete_beg()
{
    node *temp;
    temp = start;
    start = start->next;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);
}

void delete_end()
{
    node *traverse;
    traverse = start;
    while(traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->prev->next = NULL;
    cout<<traverse->data<<" has been deleted"<<endl;
    delete(traverse);
}

void delete_after()
{
    int value;
    cout<<"Enter the product after which the node has to be deleted"<<endl;
    cin>>value;
    node *traverse;
    traverse = start;
    while(traverse->data != value)
    {
        traverse = traverse->next;
    }
    node *temp;
    temp = traverse->next;
    traverse->next = temp->next;
    temp->next->prev = traverse;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);

}
void buy()
{
    system("cls");
    string products[20];
    int pay=0,no,c=0,price,id,i=1;
    if(start==NULL)
    {
        cout<<"\n<<<<There is no items to buy>>>>\n\n";
    }
    else
    {
        cout<<"How many items you wanna to buy!\n";
        cin>>no;
        int count= display1();
        while (i<=no)
        {
            struct node *cur=start;
            int quant,cho;
            cout<<"Enter id of item that you want to buy: \n";
            int id,pos=0;
            cin>>id;
            pos=search(id);
            if(pos<=count)
            {
                while(cur->data!=id)
                {
                    cur=cur->next;
                }
                cout<<"How many quantities you want: \n";
                cin>>quant;
                products[c]=cur->name;
                c++;
                pay=pay+(cur->y*quant);
                cur->x=cur->x-quant;
                i++;
            }
            else
            {
                cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        }
        //system("cls");
        cout<<"\n\n\n\t\t\tYou have bought : ";
        for(int i=0; i<no; i++)
        {
            cout<<products[i]<<",";
        }
        price=pay*(0.95);
        cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n";
    }
}
int search(int id)
{
    int count=1;
    struct node *p=start;
    while(p!=NULL)
    {
        if(p->data==id)
        {

            break;
        }
        else
            count++;
        p=p->next;
    }

    return count;
}

int display1()
{
    //	system("cls");
    int c=0;
    struct node *p=start;
    cout<<"Existing products are:\n";
    cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    while(p!=NULL)
    {
        cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<check(p->x)<<"\n";
        p=p->next;
        c=c+1;
    }
    cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
    return c;
}

string check(int quant)
{
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();
    if(quant<=0)
        return "out of stock!";
    else
        return quantity;
}

void OldProducts()
{
    system("cls");
    string line;
    ifstream myfile ("Products Record.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        cout<<"\n\n";
        myfile.close();
    }
    else cout << "Unable to open file\n\n";
}


void srch()
{
    system("cls");
    cout<<"\n\n\t\t\t************************GROCERY STORE*****************************\n\n\n"<<endl;
    string nam;
    cout<<"Enter Product Name "<<endl;
    cin>>nam;
    int f=0;
    struct node *p=start;
    while(p!=NULL)
    {
        if(nam==p->name)
        {
            f=1;
            break;
        }

        p=p->next;
    }

    if(f==1)
    {
        cout<<"Product is available"<<endl;
    }
    else
    {
        cout<<"Out of Stock"<<endl;

    }
}

int main()
{
    system("color 8B");
    int option;
    do
    {
        cout<<"--------BUY MORE PAY LESS--------"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"1 ADD PRODUCT"<<endl;
        cout<<"2 ADD PRODUCT AT FIRST POSITION"<<endl;
        cout<<"3 ADD PRODUCT AFTER A GIVEN POSITION"<<endl;
        cout<<"4 DELETE PRODUCT AT LAST POSITION"<<endl;
        cout<<"5 DELETE PRODUCT AT FIRST POSITION"<<endl;
        cout<<"6 DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
        cout<<"7 DISPLAY"<<endl;
        cout<<"8 BUY"<<endl;
        cout<<"9 SEARCH"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            insert_node();
            break;
        case 2:
            add_begin();
            break;
        case 3:
            add_after();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            delete_beg();
            break;
        case 6:
            delete_after();
            break;
        case 7:
            display();
            break;
        case 8:
            buy();
            break;
        case 9:
            srch();
            break;
        }

    }
    while(option != 0);
    return 0;
}

