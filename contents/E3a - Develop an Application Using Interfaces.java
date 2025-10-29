interface Drawable {
    void draw();
    double calculateArea();
}

class Circle implements Drawable {
    private double radius;
    Circle(double radius) {
        this.radius = radius;
    }
    public void draw() {
        System.out.println("Drawing a circle");
    }
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle implements Drawable {
    private double length, width;
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    public void draw() {
        System.out.println("Drawing a rectangle");
    }
    public double calculateArea() {
        return length * width;
    }
}

public class InterfaceDemo {
    public static void main(String[] args) {
        Drawable circle = new Circle(5.0);
        Drawable rectangle = new Rectangle(4.0, 6.0);

        circle.draw();
        System.out.println("Area of Circle: " + circle.calculateArea());
        rectangle.draw();
        System.out.println("Area of Rectangle: " + rectangle.calculateArea());
    }
}