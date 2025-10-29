class InventoryItem<T> {
    private T productDetails;
    private int quantity;
    public InventoryItem(T productDetails, int quantity) {
        this.productDetails = productDetails;
        this.quantity = quantity;
    }
    public T getProductDetails() {
        return productDetails;
    }
    public int getQuantity() {
        return quantity;
    }
    public void displayDetails() {
        System.out.println("Product Details: " + productDetails.toString());
        System.out.println("Quantity: " + quantity);
    }
}

class Electronics {
    private String model;
    private double price;
    public Electronics(String model, double price) {
        this.model = model;
        this.price = price;
    }
    @Override
    public String toString() {
        return "Model: " + model + ", Price: $" + price;
    }
}

class Grocery {
    private String itemName;
    private String expiryDate;
    public Grocery(String itemName, String expiryDate) {
        this.itemName = itemName;
        this.expiryDate = expiryDate;
    }
    @Override
    public String toString() {
        return "Item: " + itemName + ", Expiry Date: " + expiryDate;
    }
}

public class InventorySystem {
    public static void main(String[] args) {
        Electronics laptop = new Electronics("Dell Inspiron", 800.00);
        InventoryItem<Electronics> electronicsItem = new InventoryItem<>(laptop, 10);
        electronicsItem.displayDetails();
        System.out.println();

        Grocery milk = new Grocery("Milk", "2024-10-10");
        InventoryItem<Grocery> groceryItem = new InventoryItem<>(milk, 20);
        groceryItem.displayDetails();
    }
}