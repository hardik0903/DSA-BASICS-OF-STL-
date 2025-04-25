#include <iostream>
#include <vector>         // std::vector
#include <array>          // std::array (fixed-size array)
#include <deque>          // std::deque
#include <list>           // std::list (doubly linked list)
#include <forward_list>   // std::forward_list (singly linked list)
#include <stack>          // std::stack
#include <queue>          // std::queue, std::priority_queue
#include <set>            // std::set, std::multiset
#include <unordered_set>  // std::unordered_set, std::unordered_multiset
#include <map>            // std::map, std::multimap
#include <unordered_map>  // std::unordered_map, std::unordered_multimap

using namespace std;

// 1. Pairs
void explainPair(){
    pair<int, int> p={1,3};
    cout<<p.first<<" "<<p.second;
    pair<int, pair<int,int>> p2={1,{1,3}};
    cout<<p2.first<<"  "<<p2.second.first<<" "<<p2.second.second;
    pair<int, int> arr[]={{1,2},{2,5},{5,1}};
    cout<<arr[1].second;
}

// 2. Vector
void explainVector(){
    vector<int> v; // v={}

    v.push_back(1); // v={1}
    v.emplace_back(2); // v={1,2}

    vector<pair<int, int>> v2; // v2={{}}
    v2.push_back({1,2}); // v2={{1,2}}
    v2.emplace_back(1,2); // v2={{1,2},{1,2}} emplace_back consider (1,2) as pair 

    vector<int> v3(5,100); // v3={100,100,100,100,100}
    vector<int> v4(5); // v4={0,0,0,0,0}
    vector<int> v5(5,20); // v5={20,20,20,20,20}
    vector<int> v6(v5); // a copy of v5

    // -- using iterator to access elements in vector

    v={20,1,15,6,7};
    vector<int>::iterator it=v.begin();
    it++;
    cout<<*(it)<<" "; // v.begin() - it rather points to the memory address so suing * gives value that memory adress belong to.

        //-- other options than v.begin()

    vector<int>:: iterator it=v.end(); // points to memory address just after the last element
    it--;
    cout<<*(it)<<" ";

    vector<int>:: reverse_iterator it=v.rend(); // reverse end - meaning points to memory address just before start
    cout<<*(it)<<" ";

    vector<int>:: reverse_iterator it=v.rbegin(); // reverse begin - meaning points to last element
    cout<<*(it)<<" ";


    // -- Indexing

    cout<<v[0]<<" "<<v.at(0); // same work for both the function;
    cout<<v.back()<<" "; // last element

    // -- Iterating

    for(vector<int>:: iterator it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }

    // auto assignination of datatype
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }

    //Shortcut
    for(auto it:v){
        cout<<it<<" ";
    }

    // -- Deleting
    v.erase(v.begin()+1); // deleted 1st index element
    v.erase(v.begin()+1, v.begin()+3); // deleted 1st to 3rd index element

    // -- Inserting
    vector<int> v7(2,100); // v7={100,100}
    v.insert(v.begin(), 300); // v7={300,100,100}
    v.insert(v.begin()+1,2,10); // v7={300,10,10,100,100}
    vector<int> copy(2,50);
    v.insert(v.begin(), copy.begin(), copy.end()); // v7={50,50,300,10,10,100,100}

    // -- Others

    v.size();
    v.pop_back();
    v2.swap(v2);
    v.clear();
    v.empty(); // T - if empty or F - if not empty
}

// 3.List
void explainList(){
    list<int> ls;
    ls.push_back(2); // ls={2}
    ls.emplace_back(4); // ls={2,4}

    ls.push_front(5); // ls={5,2,4}

    ls.emplace_front(2); // ls={2,5,2,4}
    
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// 4.Deque
void explainDeque(){
    deque<int> dq; // dq={}
    dq.push_back(1); // dq={1}
    dq.emplace_back(2); // dq={1,2}
    dq.push_front(4); // dq={4,1,2}
    dq.emplace_front(3); // dq={3,4,1,2}

    dq.pop_back(); // -> popped :- 2
    dq.pop_front(); // -> popped :- 3

    dq.back(); // last element
    dq.front(); // front element

    // rest same as vector
}

// 5.Stack(FILO)
void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    /*| 5 |
      | 4 | 
      | 3 |
      | 2 |
      | 1 |
    */

    st.top(); // top element -> 5
    st.pop(); // popped top element -> 5
    st.size(); // size of the stack
    st.empty(); // T- if empty or F- if not empty
    stack<int> st1, st2;
    st1.swap(st2); // swaps both the stack
    //-- Indexing doesnt work here
    // all operations Time Complexity-> O(1)
}

// 6. Queue(FIFO)
void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    /*| 4 |
      | 2 | 
      | 1 |
    */

    q.back()+=5; // returns top element +5 
    q.back();
    q.front();
    q.pop();
    q.front();
    
    // size, swap same as stack
}

// 7.Priority Queue
void explainPriorityQueue(){
    priority_queue<int> pq; // pq={}
    pq.push(5); // pq={5}
    pq.push(2); // pq={5,2}
    pq.push(8); // pq={8,5,2}
    pq.emplace(10); // pq={10,8,5,2}
    // here the largest will always atya at the top

    pq.top(); // return top element
    pq.pop(); // deletes the top element

    // size, swap, empty function same as other

    //! For Minimum at the top
    priority_queue<int, vector<int>,greater<int>> pq2; // pq2={}

    pq2.push(5); // pq2={5}
    pq2.push(2); // pq2={2,5}
    pq2.push(8); // pq2={2,5,8}
    pq2.emplace(10); // pq2={2,5,8,10}

    pq.top(); // return the top element here in this case 2

    // T.C = push --> O(log(n))
    // T.C = top --> O(1)
    // T.C = pop --> O(log(n)
}

// 8.Set - Stores Unique in sorted order
void explainSet(){
    set<int> st; // st={}
    st.insert(1); // st={1}
    st.insert(2); // st={1,2}
    st.emplace(2); // st={1,2}
    st.insert(4); // st={1,2,4}
    st.insert(3); // st={1,2,3,4}
    // Functionality of insert in vector
    // begin(), end(), rend(), rbegin(), empty(), swap() are same

    auto it =st.find(3); 
    auto it =st.find(6); // here st doesnt have element by value 6 so st.find() points to st.end()

    st.erase(3);
    int cnt=st.count(1); // if exist 1 (if not exist 0)

    auto it= st.find(3);
    st.erase(it); // erase iterator

    auto it1= st.find(2);
    auto it2= st.find(4);
    st.erase(it1,it2);

    auto it= st.lower_bound(2); // for concept of lower_bound see striver lower_bound video
    auto it= st.upper_bound(3); // for concept of upper_bound see striver upper_bound video

    // Set DataStructure has Time Complexity of O(log(n))
}

// 9.MultiSet :- doesnt obey unique elements property but stores element in sorted order
void explainMultiSet(){
    multiset<int> ms; // ms={}
    ms.insert(1); // ms={1}
    ms.insert(1); // ms={1,1}
    ms.insert(1); // ms={1,1,1}

    ms.erase(1); // all 1's get erased
    int cnt=ms.count(1);

    ms.erase(ms.find(1)); // erases only one 1.
    auto it1 = ms.find(1);
    auto it2 = it1;
    advance(it2, 2);  // Move it2 two steps ahead
    
    ms.erase(it1, it2);  // Erases two 1's

    // rest all same as set
}

// 10.Unordered_Set - doesnt obey sorted property but stores unique element only
void explainUSet(){
    // same functions (exception stated above), lower_bound and upper_bound doesnt work here. Rest all are same
    //For Time Complexity - as it doesnt store in sorted order it has O(1) Time complexity and Worst Time Complexity as O(N)
}

// 11.Map - stores element in this format {key:value}, unique key in sorted order something similar to set
void explainMap(){
    map<int,int> mpp;
    map<int,pair<int,int>> mpp2;

    mpp[1]=2;
    mpp.emplace(make_pair(3,1));
    mpp.insert({2,4});

    /*
    | 1,2 |
    | 3,1 |
    | 2,4 |
    */

    mpp2[10]={2,3};

    //-- iterating 

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    mpp[1];
    mpp[5];

    auto it=mpp.find(3); // stores address of that iterator
    it->second;

    auto it=mpp.find(5); // points to mpp.end() as 5 is not available

    auto it= mpp.lower_bound(2);
    auto it= mpp.upper_bound(3);

    //erase, swap, size, empty are same as above
}

// 12.MultiMap - everything same as map, only it can store multiple keys of same value
void explainMultiMap(){
    //same as Map except above condition
}

// 13.Unordered_Map - unique keys but not in sorted order
void explainUMap(){
    // same as set and Unordered Set Difference here also between Unordered_Map and Map
}

