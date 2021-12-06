//CS20B1109
//Nischal Pradyoth
//Simple program to print some basic shapes with the help of applets`
import java.applet.Applet;
import java.awt.*;
public class shapeApplet extends Applet 
{
    public void paint(Graphics g)
    {
        int x=600,y=300,z=150;
        g.setColor(Color.green);
        g.fillOval(10,50,300,300);
        g.setColor(Color.blue);
        g.drawString("@Nischal",135,200);
        g.setColor(Color.red);
        g.fillRect(10,400,600,300);
        g.setColor(Color.blue);
        g.drawRect(160,460,300,160);
        g.setColor(Color.yellow);
        g.drawOval(700,20,300,150);
        g.fillOval(775,50,150,75);
    }
}
/*
<applet code="shapeApplet.class" width="1024" height="720">
</applet>
*/