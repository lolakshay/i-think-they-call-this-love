import java.util.Scanner;
public class SimpleStudentInfo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        int[] regNos = new int[n];
        String[] names = new String[n];
        char[] grades = new char[n];
        double[] CGPAs = new double[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");
            System.out.print("Register Number: ");
            regNos[i] = sc.nextInt();
            sc.nextLine();
            System.out.print("Name: ");
            names[i] = sc.nextLine();
            System.out.print("Grade: ");
            grades[i] = sc.next().charAt(0);
            System.out.print("CGPA: ");
            CGPAs[i] = sc.nextDouble();
        }

        System.out.println("\nAll Student Information:");
        for (int i = 0; i < n; i++) {
            System.out.println("Register Number: " + regNos[i]);
            System.out.println("Name: " + names[i]);
            System.out.println("Grade: " + grades[i]);
            System.out.println("CGPA: " + CGPAs[i]);
            System.out.println("----------------------");
        }

        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (CGPAs[i] > CGPAs[maxIndex]) {
                maxIndex = i;
            }
        }
        System.out.println("Student with the highest CGPA:");
        System.out.println("Register Number: " + regNos[maxIndex]);
        System.out.println("Name: " + names[maxIndex]);
        System.out.println("Grade: " + grades[maxIndex]);
        System.out.println("CGPA: " + CGPAs[maxIndex]);
        sc.close();
    }
}