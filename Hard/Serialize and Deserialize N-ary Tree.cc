string serialize(Node* root) {
        if (root == nullptr) return "";
        string res = to_string(root->val) + "[";
        for (auto node : root->children) {
            res += serialize(node) + " ";
        }
        if (res.back() == ' ')
            res.pop_back();
        res += "]";

        
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        string value;
        Node* head = nullptr;
        stack<Node*> s;
        for (int i = 0; i < data.size(); ++i) {
            const char& c = data[i];
            if ((c >= '0' && c <= '9') || c == '+' || c == '-') {
                value += c;
            } else if (c == '[') {
                Node* node = new Node(stoi(value));
                if (head == nullptr) head = node;
                s.push(node);
                value.clear();
            } else if (c == ']') {
                Node* node = s.top();
                s.pop();
                if (!s.empty()) {
                    Node* prev_node = s.top();
                    prev_node->children.push_back(node);
                }
            }
        }
        return head;
    }
