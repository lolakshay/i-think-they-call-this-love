class Employee {
    String name;
    double baseSalary;
    Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }
    double calculateSalary() {
        return baseSalary;
    }
    void displayEmployeeInfo() {
        System.out.println("Name: " + name);
        System.out.println("Base Salary: " + baseSalary);
    }
}

class Manager extends Employee {
    double bonus;
    Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);
        this.bonus = bonus;
    }
    @Override
    double calculateSalary() {
        return baseSalary + bonus;
    }
    @Override
    void displayEmployeeInfo() {
        super.displayEmployeeInfo();
        System.out.println("Role: Manager");
        System.out.println("Total Salary: " + calculateSalary());
    }
}

class Developer extends Employee {
    double overtimePay;
    Developer(String name, double baseSalary, double overtimePay) {
        super(name, baseSalary);
        this.overtimePay = overtimePay;
    }
    @Override
    double calculateSalary() {
        return baseSalary + overtimePay;
    }
    @Override
    void displayEmployeeInfo() {
        super.displayEmployeeInfo();
        System.out.println("Role: Developer");
        System.out.println("Total Salary: " + calculateSalary());
    }
}

class Designer extends Employee {
    double projectAllowance;
    Designer(String name, double baseSalary, double projectAllowance) {
        super(name, baseSalary);
        this.projectAllowance = projectAllowance;
    }
    @Override
    double calculateSalary() {
        return baseSalary + projectAllowance;
    }
    @Override
    void displayEmployeeInfo() {
        super.displayEmployeeInfo();
        System.out.println("Role: Designer");
        System.out.println("Total Salary: " + calculateSalary());
    }
}

public class PolymorphismExample {
    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        employees[0] = new Manager("Alice", 50000, 15000);
        employees[1] = new Developer("Bob", 40000, 5000);
        employees[2] = new Designer("Charlie", 35000, 7000);

        for (Employee emp : employees) {
            emp.displayEmployeeInfo();
            System.out.println();
        }
    }
}