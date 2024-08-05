#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;
    ~Node() { std::cout << "Node destroyed\n"; }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // Creates a cycle

    std::cout<< "node1: " << node1.use_count() << "\n";
    std::cout<< "node2: " << node2.use_count() << "\n";

    // Both node1 and node2 will not be destroyed due to circular reference
    return 0;
}
