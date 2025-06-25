#include<iostream>
#include<vector>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(){
        data = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    Node(int data):data(data){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    Node(int data, Node* parent){
        this->data = data;
        this->parent = parent;
    }

};

class MaxHeap{
    
public:
    vector<Node*> heapArray;
    //값만 교환하는 트리 힙 구조에서의 스왑
    void swap(Node& i, Node& j){
        int data = i.data;
        i.data = j.data;
        j.data = data;
    }

    void heapifyUp(Node& i){
        if(i.parent == nullptr) return;
        if(i.data > i.parent->data){
            swap(i,*(i.parent));
            heapifyUp(*(i.parent));
        }
    }

    void heapifyDown(Node& i){
        if(!i.left && !i.right) return;

        int maxData = i.data;
        bool flag = 0;//0 -> left, 1 -> right
        if(i.left && i.left->data > maxData) maxData = i.left->data;
        if(i.right &&i.right->data > maxData){
            maxData = i.right->data;
            flag = 1;
        } 
        if(maxData != i.data){
            //left or right로 스왑
            Node* n = flag ? (i.right) : (i.left);
            swap(i,*n);
            heapifyDown(*n);
        }
    }

    int top(){
        if(heapArray.empty()) return -1;
        return heapArray[0]->data;
    }

    int pop(){
        int result = top();
        if(result != -1){
            swap((*heapArray.back()),*(heapArray.front()));
            delete heapArray.back();
            heapArray.pop_back();

            if(!heapArray.empty())
                heapifyDown(*heapArray.front());
        }
        return result;
    }

    // 1 2 3
    // 0 1 2 
    void push(int data){
        Node* node = new Node(data);
        heapArray.push_back(node);
        int idx = heapArray.size()-1; 
        if(idx > 0){
            int parent = (idx - 1) / 2;
            node->parent = heapArray[parent];
        }   
        heapifyUp(*heapArray[idx]);
    }
    ~MaxHeap() {
        for (auto node : heapArray)
            delete node;
    }
};

class MinHeap{
    
public:
    vector<Node*> heapArray;
    //값만 교환하는 트리 힙 구조에서의 스왑
    void swap(Node& i, Node& j){
        int data = i.data;
        i.data = j.data;
        j.data = data;
    }

    void heapifyUp(Node& i){
        if(i.parent == nullptr) return;
        if(i.data < i.parent->data){
            swap(i,*(i.parent));
            heapifyUp(*(i.parent));
        }
    }

    void heapifyDown(Node& i){
        if(!i.left && !i.right) return;

        int minData = i.data;
        bool flag = 0;//0 -> left, 1 -> right
        if(i.left && i.left->data < minData) minData = i.left->data;
        if(i.right &&i.right->data < minData){
            maxData = i.right->data;
            flag = 1;
        } 
        if(minData != i.data){
            //left or right로 스왑
            Node* n = flag ? (i.right) : (i.left);
            swap(i,*n);
            heapifyDown(*n);
        }
    }

    int top(){
        if(heapArray.empty()) return -1;
        return heapArray[0]->data;
    }

    int pop(){
        int result = top();
        if(result != -1){
            swap((*heapArray.back()),*(heapArray.front()));
            delete heapArray.back();
            heapArray.pop_back();

            if(!heapArray.empty())
                heapifyDown(*heapArray.front());
        }
        return result;
    }

    // 1 2 3
    // 0 1 2 
    void push(int data){
        Node* node = new Node(data);
        heapArray.push_back(node);
        int idx = heapArray.size()-1; 
        if(idx > 0){
            int parent = (idx - 1) / 2;
            node->parent = heapArray[parent];
        }   
        heapifyUp(*heapArray[idx]);
    }
    ~MinHeap() {
        for (auto node : heapArray)
            delete node;
    }
};  
