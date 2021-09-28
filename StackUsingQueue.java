import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Stack {
    int top = -1;
    Queue<Integer> queue1 = new LinkedList<>();
    Queue<Integer> queue2 = new LinkedList<>();

    void push(int ele) {
        top += 1;
        queue2.add(ele);
        while (!queue1.isEmpty()) {
            queue2.add(queue1.peek());
            queue1.remove();
        }
        Queue<Integer> queue3 = queue1;
        queue1 = queue2;
        queue2 = queue3;
    }

    void pop() {
        if (top >= 0)
            top -= 1;
        if (queue1.isEmpty())
            System.out.println("null");
        else
            System.out.println(queue1.remove());
    }

    void peek() {
        System.out.println(queue1.peek());
    }

    void print() {
        Queue<Integer> queue3 = queue1;
        System.out.println("Top = " + top);
        if (queue3.isEmpty())
            System.out.println("null");
        while (!queue3.isEmpty())
            System.out.print(queue3.remove() + " ");
    }
}

public class StackUsingQueue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int val;
        Stack s = new Stack();
        while (true) {
            System.out.println("\n1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
            System.out.println("Select a choice to perform an Operation : ");
            val = sc.nextInt();
            switch (val) {
                case 1:
                    System.out.println("Enter the value to insert into the stack : ");
                    s.push(sc.nextInt());
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.peek();
                    break;
                case 4:
                    s.print();
                    break;
                case 5:
                    System.exit(0);
            }
        }
    }
}