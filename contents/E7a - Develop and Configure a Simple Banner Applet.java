import java.applet.*;
import java.awt.*;

public class SimpleBannerApplet extends Applet {
    public void init() {
        setBackground(Color.white);
        setForeground(Color.blue);
    }
    public void paint(Graphics g) {
        g.drawString("Welcome to the Simple Banner Applet!", 20, 50);
    }
}