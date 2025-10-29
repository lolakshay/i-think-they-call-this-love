class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class Main {
    public static void validateAge(int age) throws InvalidAgeException {
        if (age < 18 || age > 60) {
            throw new InvalidAgeException("Invalid Age: Age must be between 18 and 60.");
        } else {
            System.out.println("Age is valid.");
        }
    }

    public static void main(String[] args) {
        int age = 65;
        try {
            validateAge(age);
        } catch (InvalidAgeException e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Age validation completed.");
        }
    }
}