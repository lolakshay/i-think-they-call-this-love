import java.util.Scanner;

class Book {
    String title;
    String author;
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }
    @Override
    public String toString() {
        return "Title: " + title + ", Author: " + author;
    }
}

class Stack {
    private Book[] stack;
    private int top;
    private static final int MAX_SIZE = 10;

    public Stack() {
        stack = new Book[MAX_SIZE];
        top = -1;
    }

    public void push(Book book) {
        if (top < MAX_SIZE - 1) {
            stack[++top] = book;
            System.out.println("Added: " + book);
        } else {
            System.out.println("Stack is full. Cannot add more books.");
        }
    }

    public Book pop() {
        if (top >= 0) {
            Book book = stack[top--];
            System.out.println("Removed: " + book);
            return book;
        } else {
            System.out.println("Stack is empty. Cannot remove book.");
            return null;
        }
    }

    public boolean isEmpty() {
        return top == -1;
    }
}

public class BookStackTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack bookStack = new Stack();
        while (true) {
            System.out.println("\nChoose an option:");
            System.out.println("1. Push a book onto the stack");
            System.out.println("2. Pop a book from the stack");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Enter book details:");
                    System.out.print("Title: ");
                    String title = scanner.nextLine();
                    System.out.print("Author: ");
                    String author = scanner.nextLine();
                    Book book = new Book(title, author);
                    bookStack.push(book);
                    break;
                case 2:
                    bookStack.pop();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        }
    }
}