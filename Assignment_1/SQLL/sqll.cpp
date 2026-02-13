#include "sqll.h"
#include <cmath>

//======================= STACK ===========================

Stack::Stack()
{
    top = nullptr; 
}

Stack::~Stack() 
{
    while (!isEmpty()) 
    {
        pop();
    }
}

void Stack::push(string& value) 
{
    // complete this
    node* newNode = new node(value);
    newNode->next = top;
    top = newNode;
}

string Stack::pop() 
{
    // complete this
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    
    node* temp = top; //temporary pointer to holde the current top node
    string data = temp->data; // saving the data before storing the node
    top = top->next; //moves top node to the next node, which removes the current top node from the stack

    delete temp; //prevents memory leaks
    return data; //returns the new stack of data
}

string Stack::peek() 
{
    if (isEmpty()) 
    {
        throw runtime_error("Stack is empty");
    }

    return top->data;  
}

bool Stack::isEmpty() 
{
    return top == nullptr;
}

void Stack::display()
{
    node* current = top;
    cout << "Stack: ";
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//======================= QUEUE ===========================

Queue::Queue()
{
    front = nullptr;
    rear = nullptr; 
}

Queue::~Queue() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

void Queue::enqueue(string& value) 
{
    node* newNode = new node(value); //using the node constructor from sqll.h. 

    //check to see if the queue is empty
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string Queue::dequeue() 
{
    //check to see if its empty
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    
    node* temp = front; //temporarliy hold the front node, which we will delete
    string data = temp->data; // save the data to a data object
    front = front->next; // moving the front node to the next node. 
    
    if (front == nullptr) {
        rear = nullptr; //if the queue is empty, set rear to nullptr
    }
    
    delete temp; //deleted
    return data;
}

bool Queue::isEmpty() 
{
    return front == nullptr;
}

void Queue::display()
{
    node* current = front;
    cout << "Queue: ";
    
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//======================= DIJKSTRA'S TWO STACK ===========================


// what a learning 


//algorithm for this function:


// Dijkstra's Two-Stack Algorithm: Uses two stacks to solve math expressions written in the usual way
// Algorithm Steps:
// 1. Initialize an operator stack and a value stack
// 2. Iterate through each character in the expression
// 3. If the character is a number, parse the full number and push to value stack
// 4. If the character is '(', push to operator stack
// 5. If the character is ')', pop and apply operators until '(' is found
// 6. If the character is an operator, handle precedence and push to operator stack
// 7. After processing all characters, apply remaining operators
// 8. Return the final result from the value stack


//1. Initialize an operator stack and a value stack
double evaluateExpression(string& expr) 
{
    stack<char> ops;
    stack<double> vals;
    int i = 0;
    auto applyOp = [](char op, double val1, double val2) -> double {
        switch (op) {
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            case '/': return val1 / val2;
            case '^': return pow(val1, val2); //came back and added this
            default: return 0;
        }
    };


//2. Iterate through each character in the expression
while (i < expr.length()) {
    char c = expr[i++];

    if (isspace(c)) { //using isspace () to ski over the whitespace. 
        continue;
    }

//3. If the character is a number, parse the full number and push to value stack
else if (isdigit(c)) {
    string numstr;
    numstr += c;

    while (i < expr.length() && isdigit(expr[i])) {
        numstr += expr[i++];
    }
    vals.push(stod(numstr));
}

//4. If the character is '(', push to operator stack
else if (c == '('){
    ops.push(c);
}

//5. If the character is ')', pop and apply operators until '(' is found
else if (c == ')'){
    while (!ops.empty() && ops.top() != '('){
        char op = ops.top(); //getting the operator. 
        ops.pop(); //removing the operator from the stack. 

        double val2;
        if (!vals.empty()){    
         val2 = vals.top();
        vals.pop();
        } 
        double val1;
        if (!vals.empty()){
         val1 = vals.top();
        vals.pop();
        } 
        vals.push(applyOp(op, val1, val2));
    }
    if (!ops.empty() && ops.top() == '('){
        ops.pop();
    }
}

//6. If the character is an operator, handle precedence and push to operator stack
//This was was fighting me for a while. 
else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    while (!ops.empty() && ops.top() != '(' && vals.size() >= 2 &&
       ((c == '^') ? false : 
        (c == '*' || c == '/') ? (ops.top() == '*' || ops.top() == '/' || ops.top() == '^') : 
        (ops.top() == '+' || ops.top() == '-'))) {
        char op = ops.top(); ops.pop();     // Get operator, then remove
        double val2 = vals.top(); vals.pop(); // Get val2, then remove  
        double val1 = vals.top(); vals.pop(); // Get val1, then remove
        vals.push(applyOp(op, val1, val2));  // Push result

    }

    ops.push(c); //push the operator to the stack
    
}



} //close while loop

//7. After processing all characters, apply remaining operators

while (!ops.empty()){

    char op = ops.top(); ops.pop();
    double val2 = vals.top(); vals.pop();
    double val1 = vals.top(); vals.pop();
    vals.push(applyOp(op, val1, val2));

    
}

return vals.empty() ? 0.0 : vals.top();

}//close function


// ============= JOSEPHUS PROBLEM ===========================
void josephus(int n, int k) //we take in n as the number of peeps and k as the step count
{
    Queue q;
    for (int i = 1; i <= n; i++) { 
        string str = to_string(i); 
        q.enqueue(str); //we enqeueue the pepole on to the queue. set by the iteration. 
    }

    while (!q.isEmpty()) {
        for (int i = 0; i < k - 1; i++) {
            string str = q.dequeue(); //we take the person from the queue
            q.enqueue(str); //and immediately put them back on the queue. 
        }
        cout << q.dequeue() << " "; //taking person who = k, and kills them off from the queue. 
    }
    cout << endl;
}