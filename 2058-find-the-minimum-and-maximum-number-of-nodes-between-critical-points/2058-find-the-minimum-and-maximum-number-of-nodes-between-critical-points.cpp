/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>data;
        ListNode* temp = head;
        while(temp){
            data.push_back(temp->val);
            temp = temp->next;
        }

       int n = data.size();
       if( n<=2 ) return {-1,-1};

       vector<int>indices;
       for( int i=1;i<n-1;i++){
        int prev = i-1;
        int nxt = i+1;

        if( data[i] > data[prev] && data[i] > data[nxt]) indices.push_back(i);
        if( data[i] < data[prev] && data[i] < data[nxt] ) indices.push_back(i);

       } 

       sort( indices.begin() , indices.end());

       int p = INT_MAX;
       int q = -1;

       if( indices.size() < 2 ) return {-1,-1};

        for( int i=1;i<indices.size();i++){
            p = min( p , indices[i]-indices[i-1]);
        }

        q = indices.back()-indices.front();

       return {p,q};
    }
};