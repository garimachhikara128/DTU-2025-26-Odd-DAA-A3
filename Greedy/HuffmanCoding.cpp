#include<iostream>
#include<queue>

using namespace std ;

class Node
{
    public :
    char data ;
    int freq ;
    Node *left ;
    Node *right ;

    Node(char data, int freq)
    {
        this->data = data ;
        this->freq = freq ;
        this->left = NULL ;
        this->right = NULL ;
    }
} ;

void printCodes(Node *node, string ans)
{
    if(node->left == NULL && node->right == NULL)
    {
        cout << node->data << " " << ans << endl ;
        return ;
    }

    printCodes(node->left, ans + "0") ;
    printCodes(node->right, ans + "1") ;
}

struct compare
{
    bool operator()(Node* n1, Node* n2)
    {
        return n1->freq > n2->freq ;
    }
} ;

void huffmanCodes(char arr[], int freq[], int n)
{
    priority_queue<Node*, vector<Node*>, compare> pq ;

    for(int i = 0 ; i < n ; i++)
        pq.push(new Node(arr[i], freq[i])) ;

    while(pq.size() != 1)
    {
        // 1. remove 2 nodes with least freq
        Node *fn = pq.top() ;
        pq.pop() ;

        Node *sn = pq.top() ;
        pq.pop() ;

        // 2. create a new node and link fn & sn
        Node *nn = new Node(' ', fn->freq + sn->freq) ;
        nn->left = fn ;
        nn->right = sn ;

        // 3. push the new node
        pq.push(nn) ;
    }

    Node *ln = pq.top() ;
    pq.pop() ;

    printCodes(ln, "") ;
}

int main()
{
    char arr[] = {'a','b','c','d','e'} ;
    int freq[] = {4,2,1,5,60} ;
    int n = sizeof(arr) / sizeof(char) ;

    huffmanCodes(arr, freq, n) ;

    return 0 ;
}