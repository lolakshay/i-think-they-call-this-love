class Vehicle {
    String brand;
    int speed;
    Vehicle(String brand, int speed) {
        this.brand = brand;
        this.speed = speed;
    }
    void displayInfo() {
        System.out.println("Brand: " + brand);
        System.out.println("Speed: " + speed + " km/h");
    }
}

class Car extends Vehicle {
    int doors;
    Car(String brand, int speed, int doors) {
        super(brand, speed);
        this.doors = doors;
    }
    void displayCarInfo() {
        displayInfo();
        System.out.println("Number of doors: " + doors);
    }
}

class Bike extends Vehicle {
    boolean hasCarrier;
    Bike(String brand, int speed, boolean hasCarrier) {
        super(brand, speed);
        this.hasCarrier = hasCarrier;
    }
    void displayBikeInfo() {
        displayInfo();
        System.out.println("Has carrier: " + (hasCarrier ? "Yes" : "No"));
    }
}

public class InheritanceExample {
    public static void main(String[] args) {
        Car car = new Car("Toyota", 180, 4);
        Bike bike = new Bike("Yamaha", 120, true);
        System.out.println("Car Details:");
        car.displayCarInfo();
        System.out.println("\nBike Details:");
        bike.displayBikeInfo();
    }
}