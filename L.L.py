class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None # first node

    # Add a new node
    def append(self, data):
        new_node = Node(data)
        if self.head is None: # if list is empty
            self.head = new_node
            return
        
        current = self.head
        while current.next: # move to the last node
            current = current.next
        
        
        current.next = new_node 

    # Print all elements
    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        
        
        print("None")

# Example:

if __name__ == "__main__":
    ll = LinkedList()
    ll.append(10)
    ll.append(30)
    ll.append(50)
    ll.append(70)
    ll.append(90)
    
    ll.display()
        
        
