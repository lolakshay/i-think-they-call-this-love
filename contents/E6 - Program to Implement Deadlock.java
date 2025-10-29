class SeatAllocationSystem {}
class PaymentGateway {}

class User1 extends Thread {
    private SeatAllocationSystem seatSystem;
    private PaymentGateway paymentSystem;
    public User1(SeatAllocationSystem seatSystem, PaymentGateway paymentSystem) {
        this.seatSystem = seatSystem;
        this.paymentSystem = paymentSystem;
    }
    @Override
    public void run() {
        synchronized (seatSystem) {
            System.out.println("User 1: Locked Seat Allocation System");
            try { Thread.sleep(100); } catch (InterruptedException e) {}
            System.out.println("User 1: Waiting for Payment Gateway");
            synchronized (paymentSystem) {
                System.out.println("User 1: Locked Payment Gateway");
            }
        }
    }
}

class User2 extends Thread {
    private SeatAllocationSystem seatSystem;
    private PaymentGateway paymentSystem;
    public User2(SeatAllocationSystem seatSystem, PaymentGateway paymentSystem) {
        this.seatSystem = seatSystem;
        this.paymentSystem = paymentSystem;
    }
    @Override
    public void run() {
        synchronized (paymentSystem) {
            System.out.println("User 2: Locked Payment Gateway");
            try { Thread.sleep(100); } catch (InterruptedException e) {}
            System.out.println("User 2: Waiting for Seat Allocation System");
            synchronized (seatSystem) {
                System.out.println("User 2: Locked Seat Allocation System");
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SeatAllocationSystem seatSystem = new SeatAllocationSystem();
        PaymentGateway paymentSystem = new PaymentGateway();
        User1 user1 = new User1(seatSystem, paymentSystem);
        User2 user2 = new User2(seatSystem, paymentSystem);
        user1.start();
        user2.start();

        try {
            user1.join(1000);
            user2.join(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Both threads are waiting indefinitely - Deadlock detected.");
    }
}