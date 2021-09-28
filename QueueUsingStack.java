
import java.util.Stack;
import java.util.Scanner;

class Queue {
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();

    void insert(int ele) {
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        stack2.push(ele);
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
    }

    void delete() {
        if (stack2.isEmpty())
            System.out.println("null");
        else
            System.out.println(stack2.pop());
    }

    void print() {
        Stack<Integer> stack3 = new Stack<>();
        if (stack2.isEmpty())
            System.out.println("null");
        while (!stack2.isEmpty()) {
            System.out.print(stack2.peek() + " ");
            stack3.push(stack2.pop());
        }
        while (!stack3.isEmpty())
            stack2.push(stack3.pop());
    }
}

public class QueueUsingStack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int val;
        Queue q = new Queue();
        while (true) {
            System.out.println("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
            System.out.println("Select a choice to perform an Operation : ");
            val = sc.nextInt();
            switch (val) {
                case 1:
                    System.out.println("Enter the value to insert into the stack : ");
                    q.insert(sc.nextInt());
                    break;
                case 2:
                    q.delete();
                    break;
                case 3:
                    q.print();
                    break;
                case 4:
                    System.exit(0);
            }
        }
    }
}
