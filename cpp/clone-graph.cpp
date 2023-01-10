/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

Node* bfs(Node* node){
	bool vis[200] = { 0 };
    map<int, Node*> m;
    
	queue<Node*> q, q1;
	q.push(node);
	Node * head = new Node(node->val);
	q1.push(head);
    m[node->val] = head;
	while (q.size()){
		auto current = q.front(); q.pop();
		auto current1 = q1.front(); q1.pop();
	    vis[current->val] = 1;	
		for (auto next : current->neighbors){
			if (!vis[next->val]){
                Node* next1  = nullptr;
                if(m.count(next->val)) next1 = m[next->val];
                else next1 = new Node(next->val), m[next->val] = next1;
                next1->neighbors.push_back(current1);   
                current1->neighbors.push_back(next1);
				q1.push(next1);
				q.push(next);
			}
		}
	}
	return head;
}

Node* cloneGraph(Node* node) {
    if(!node) return nullptr;
	auto ret = bfs(node);
	return ret;
}
};